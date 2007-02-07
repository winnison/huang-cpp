#include "GifEncoder.h"
#include "NeuQuant.h"
#include "LZWEncoder.h"


CGifEncoder::CGifEncoder()
:
width(0),
height(0),
transparent(EMPTYCOLOR),
transIndex(0),
repeat(-1),
delay(0),
started(false),
fs(NULL),
hBitmap(0),
pixels(NULL),
indexedPixels(NULL),
colorDepth(0),
//colorTab(NULL),
palSize(7),
dispose(-1),
closeStream(false),
firstFrame(true),
sizeSet(false),
sample(10)
{
}

CGifEncoder::~CGifEncoder()
{
	SAVEDEL(pixels)
	SAVEDEL(indexedPixels)
	//SAVEDEL(colorTab)
}

/**
* Analyzes image colors and creates color map.
*/
void CGifEncoder::AnalyzePixels() 
{
	int nPix = width*height;
	int len = 3*nPix;
	SAVEDEL(indexedPixels)
	indexedPixels = new byte[nPix];
	CNeuQuant nq(pixels, len, sample);
	// initialize quantizer
	//SAVEDEL(colorTab)
	nq.Process(colorTab); // create reduced palette
	// convert map from BGR to RGB
	//for (int i = 0; i < NETSIZE*3; i += 3) 
	//{
	//	byte temp = colorTab[i];
	//	colorTab[i] = colorTab[i + 2];
	//	colorTab[i + 2] = temp;
	//}
	memset(usedEntry,0,sizeof(usedEntry));
	// map image pixels to new palette
	int k = 0;
	for (int i = 0; i < nPix; i++) 
	{
		int index =
			nq.Map(pixels[k],
			pixels[k+1],
			pixels[k+2]);
		k+=3;
		usedEntry[index] = true;
		indexedPixels[i] = (byte)(index);
	}

	SAVEDEL(pixels);
	pixels = NULL;
	colorDepth = 8;
	palSize = 7;
	// get closest match to transparent color if specified
	if (transparent != EMPTYCOLOR ) 
	{
		transIndex = FindClosest(transparent);
	}
}





/**
* Returns index of palette color closest to c
*
*/
int CGifEncoder::FindClosest(COLORREF c) 
{
	if (colorTab == NULL) return -1;
	int r = GetRValue(c);
	int g = GetGValue(c);
	int b = GetBValue(c);
	int minpos = 0;
	int dmin = 256 * 256 * 256;
	int len = 3 * NETSIZE;
	for (int i = 0; i < len;) 
	{
		int dr = r - (colorTab[i++] & 0xff);
		int dg = g - (colorTab[i++] & 0xff);
		int db = b - (colorTab[i] & 0xff);
		int d = dr * dr + dg * dg + db * db;
		int index = i / 3;
		if (usedEntry[index] && (d < dmin)) 
		{
			dmin = d;
			minpos = index;
		}
		i++;
	}
	return minpos;
}


/**
* Extracts image pixels into byte array "pixels"
*/
void CGifEncoder::GetImagePixels() 
{
	HBITMAP hBm = NULL;
	BITMAP bmpInfo;
	::GetObject(hBitmap,sizeof(BITMAP),&bmpInfo);

	if ((bmpInfo.bmWidth != width)
		|| (bmpInfo.bmHeight != height)
		) 
	{
		hBm = StretchBitmap(hBitmap, width, height);
		hBitmap = hBm;
	}
	/*
	ToDo:
	improve performance: 
	*/
	SAVEDEL(pixels)
	byte* pch;
	pixels = pch = new byte [ 3 * width * height + 1 ];
	int count =0;
	CDCHandle dcScreen = GetDC(NULL);
	CDC dcTemp;
	dcTemp.CreateCompatibleDC(dcScreen);
	HBITMAP hBmpOldSrc = dcTemp.SelectBitmap(hBitmap);
	for (int th = 0; th < height; th++)
	{
		for (int tw = 0; tw < width; tw++)
		{
			*((COLORREF*)pch) = dcTemp.GetPixel(tw, th);
			pch+=3;

			//COLORREF color = dcTemp.GetPixel(tw, th);
			//pixels[count] = GetRValue(color);
			//count++;
			//pixels[count] = GetGValue(color);
			//count++;
			//pixels[count] = GetBValue(color);
			//count++;
		}
	}
	dcTemp.SelectBitmap(hBmpOldSrc);
	::ReleaseDC(NULL,dcScreen.m_hDC);
	if (hBm != NULL)
	{
		::DeleteObject(hBm);
	}
	//		pixels = ((DataBufferByte) image.getRaster().getDataBuffer()).getData();
}

/**
* Writes Graphic Control Extension
*/
void CGifEncoder::WriteGraphicCtrlExt() 
{
	fs->put(0x21); // extension introducer
	fs->put(0xf9); // GCE label
	fs->put(4); // data block size
	int transp, disp;
	if (transparent == EMPTYCOLOR ) 
	{
		transp = 0;
		disp = 0; // dispose = no action
	} 
	else 
	{
		transp = 1;
		disp = 2; // force clear if using transparent color
	}
	if (dispose >= 0) 
	{
		disp = dispose & 7; // user override
	}
	disp <<= 2;

	// packed fields
	fs->put((char) ( 0 | // 1:3 reserved
		disp | // 4:6 disposal
		0 | // 7   user input - 0 = none
		transp )); // 8   transparency flag

	WriteShort(delay); // delay x 1/100 sec
	fs->put((char)transIndex); // transparent color index
	fs->put(0); // block terminator
}

/**
* Writes Image Descriptor
*/
void CGifEncoder::WriteImageDesc()
{
	fs->put(0x2c);// image separator
	WriteShort(0); // image position x,y = 0,0
	WriteShort(0);
	WriteShort(width); // image size
	WriteShort(height);
	// packed fields
	if (firstFrame) 
	{
		// no LCT  - GCT is used for first (or only) frame
		fs->put(0);
	} 
	else 
	{
		// specify normal LCT
		fs->put((char) (0x80 | // 1 local color table  1=yes
			0 | // 2 interlace - 0=no
			0 | // 3 sorted - 0=no
			0 | // 4-5 reserved
			palSize) ); // 6-8 size of color table
	}
}

/**
* Writes Logical Screen Descriptor
*/
void CGifEncoder::WriteLSD()  
{
	// logical screen size
	WriteShort(width);
	WriteShort(height);
	// packed fields
	fs->put((char) (0x80 | // 1   : global color table flag = 1 (gct used)
		0x70 | // 2-4 : color resolution = 7
		0x00 | // 5   : gct sort flag = 0
		palSize) ); // 6-8 : gct size

	WriteShort(0);
	//fs<<(byte)(0); // background color index
	//fs<<(byte)(0); // pixel aspect ratio - assume 1:1
}

/**
* Writes Netscape application extension to define
* repeat count.
*/
void CGifEncoder::WriteNetscapeExt()
{
	int a = 0x000b;
	WriteShort(0xff21);
	fs->put(0x0b);
	//fs<<(byte)0x21; // extension introducer
	//fs<<(byte)0xff; // app extension label
	//fs<<(byte)0x0b; // block size
	WriteString("NETSCAPE2.0"); // app id + auth code
	a = 0x0103;
	WriteShort(a);
	//fs<<(byte)3; // sub-block size
	//fs<<(byte)1; // loop sub-block id
	WriteShort(repeat); // loop count (extra iterations, 0=repeat forever)
	fs->put(0); // block terminator
}

/**
* Writes color table
*/
void CGifEncoder::WritePalette()
{
	fs->write((char*)colorTab, (3 * NETSIZE));
	/*int n = (3 * 256) - (3 * NETSIZE);
	for (int i = 0; i < n; i++) 
	{
		fs<<(byte)(0);
	}*/
}

/**
* Encodes and writes pixel data
*/
void CGifEncoder::WritePixels()
{
	CLZWEncoder encoder(width, height, indexedPixels, colorDepth);
	encoder.Encode( fs );
}

void CGifEncoder::WriteInt(int value)
{
	fs->write((char*)&value, 4);
}

/**
*    Write 16-bit value to output stream, LSB first
*/
void CGifEncoder::WriteShort(int value)
{
	fs->write((char*)&value, 2);
}

/**
* Writes string to output stream
*/
void CGifEncoder::WriteString(string s)
{
	fs->write(s.c_str(), s.length());
}




/**
* Adds next GIF frame.  The frame is not written immediately, but is
* actually deferred until the next frame is received so that timing
* data can be inserted.  Invoking <code>finish()</code> flushes all
* frames.  If <code>setSize</code> was not invoked, the size of the
* first image is used for all subsequent frames.
*
* @param im BufferedImage containing frame to write.
* @return true if successful.
*/
bool CGifEncoder::AddFrame(HBITMAP hBm) 
{
	if ((hBm == 0) || !started) 
	{
		return false;
	}
	hBitmap = hBm;
	BITMAP bmpInfo;
	::GetObject(hBitmap,sizeof(BITMAP),&bmpInfo);

	bool ok = true;
	try 
	{
		if (!sizeSet) 
		{
			// use first frame's size
			SetSize(bmpInfo.bmWidth, bmpInfo.bmHeight);
		}
		GetImagePixels(); // convert to correct format if necessary
		AnalyzePixels(); // build color table & map pixels
		if (firstFrame) 
		{
			WriteLSD(); // logical screen descriptior
			WritePalette(); // global color table
			if (repeat >= 0) 
			{
				// use NS app extension to indicate reps
				WriteNetscapeExt();
			}
		}
		WriteGraphicCtrlExt(); // write graphic control extension
		WriteImageDesc(); // image descriptor
		if (!firstFrame) 
		{
			WritePalette(); // local color table
		}
		WritePixels(); // encode and write pixel data
		firstFrame = false;
	} 
	catch (...) 
	{
		ok = false;
	}
	//DeleteObject(hBitmap);
	return ok;
}

/**
* Flushes any pending data and closes output file.
* If writing to an OutputStream, the stream is not
* closed.
*/
bool CGifEncoder::Finish() 
{
	if (!started) return false;
	bool ok = true;
	started = false;
	try 
	{
		fs->put( 0x3b ); // gif trailer
		fs->flush();
		if (closeStream) 
		{
			fs->close();
			SAVEDEL(fs)
		}
	} 
	catch (...) 
	{
		ok = false;
	}

	SAVEDEL(pixels)
	SAVEDEL(indexedPixels)
	// reset for subsequent use
	transIndex = 0;
	fs = NULL;
	hBitmap = NULL;
	pixels = NULL;
	indexedPixels = NULL;
	//colorTab = NULL;
	closeStream = false;
	firstFrame = true;
	
	return ok;
}

/**
* Initiates GIF file creation on the given stream.  The stream
* is not closed automatically.
*
* @param os OutputStream on which GIF images are written.
* @return false if initial write failed.
*/
bool CGifEncoder::Start( fstream* os) 
{
	if (os == NULL || started) return false;
	bool ok = true;
	closeStream = false;
	SAVEDEL(fs)
	fs = os;
	try 
	{
		WriteString("GIF89a"); // header
	} 
	catch (...) 
	{
		ok = false;
	}
	return started = ok;
}

/**
* Initiates writing of a GIF file with the specified name.
*
* @param file string containing output file name.
* @return false if open or initial write failed.
*/
bool CGifEncoder::Start(string file) 
{
	if (started) return false;
	bool ok = true;
	try 
	{
		//			bw = new BinaryWriter( new FileStream( file, FileMode.OpenOrCreate, FileAccess.Write, FileShare.None ) );
		ok = Start(new fstream( file.c_str(), ios_base::out | ios_base::binary ));
		closeStream = true;
	} 
	catch (...) 
	{
		ok = false;
	}
	return started = ok;
}

/**
* Sets the delay time between each frame, or changes it
* for subsequent frames (applies to last frame added).
*
* @param ms int delay time in milliseconds
*/
void CGifEncoder::SetDelay(int ms) 
{
	delay = ( int ) ((ms+5) / 10.0f);
}

/**
* Sets the GIF frame disposal code for the last added frame
* and any subsequent frames.  Default is 0 if no transparent
* color has been set, otherwise 2.
* @param code int disposal code.
*/
void CGifEncoder::SetDispose(int code) 
{
	if (code >= 0) 
	{
		dispose = code;
	}
}

/**
* Sets the number of times the set of GIF frames
* should be played.  Default is 1; 0 means play
* indefinitely.  Must be invoked before the first
* image is added.
*
* @param iter int number of iterations.
* @return
*/
void CGifEncoder::SetRepeat(int iter) 
{
	if (iter >= 0) 
	{
		repeat = iter;
	}
}

/**
* Sets the transparent color for the last added frame
* and any subsequent frames.
* Since all colors are subject to modification
* in the quantization process, the color in the final
* palette for each frame closest to the given color
* becomes the transparent color for that frame.
* May be set to NULL to indicate no transparent color.
*
* @param c COLOR to be treated as transparent on display.
*/
void CGifEncoder::SetTransparent(COLORREF c) 
{
	transparent = c & 0x00ffffff;
}

/**
* Sets frame rate in frames per second.  Equivalent to
* <code>setDelay(1000/fps)</code>.
*
* @param fps float frame rate (frames per second)
*/
void CGifEncoder::SetFrameRate(float fps) 
{
	if (fps != 0) 
	{
		delay = ( int ) ((100 / fps)+0.5);
	}
}

/**
* Sets quality of color quantization (conversion of images
* to the maximum 256 colors allowed by the GIF specification).
* Lower values (minimum = 1) produce better colors, but slow
* processing significantly.  10 is the default, and produces
* good color mapping at reasonable speeds.  Values greater
* than 20 do not yield significant improvements in speed.
*
* @param quality int greater than 0.
* @return
*/
void CGifEncoder::SetQuality(int quality) 
{
	if (quality < 1) quality = 1;
	sample = quality;
}

/**
* Sets the GIF frame size.  The default size is the
* size of the first frame added if this method is
* not invoked.
*
* @param w int frame width.
* @param h int frame width.
*/
void CGifEncoder::SetSize(int w, int h) 
{
	if (started && !firstFrame) return;
	width = w;
	height = h;
	if (width < 1) width = 320;
	if (height < 1) height = 240;
	sizeSet = true;
}
