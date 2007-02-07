#include "GifDecoder.h"


CGifDecoder::CGifDecoder()
:
inStream(NULL),
status(0),
width(0),
height(0),
gctFlag(false),
gctSize(0),
loopCount(1),
//gct(NULL),
//lct(NULL),
act(NULL),
bgIndex(0),
bgColor(0),
lastBgColor(0),
pixelAspect(0),
lctFlag(false),
interlace(false),
lctSize(0),
ix(0),
iy(0),
iw(0),
ih(0),
image(NULL),
lastImage(NULL),
blockSize(0),
dispose(0),
lastDispose(0),
transparency(false),
delay(0),
transIndex(0),
pixels(NULL)
{

}

///**
//* Gets display duration for specified frame.
//*
//* @param n int index of frame
//* @return delay in milliseconds
//*/
//int CGifDecoder::GetDelay(int n) 
//{
//	if ((n >= 0) && (n < frames.size())) 
//	{
//		return frames[n].delayMs;
//	}
//	return -1;
//}

/**
* Gets the number of frames read from file.
* @return frame count
*/
int CGifDecoder::GetFrameCount() 
{
	return frames.size();
}

/**
* Gets the first (or only) image read.
*
* @return BufferedImage containing first frame, or NULL if none.
*/
CGifFrame* CGifDecoder::GetImage() 
{
	return GetFrame(0);
}

/**
* Gets the "Netscape" iteration count, if any.
* A count of 0 means repeat indefinitiely.
*
* @return iteration count if one was specified, else 1.
*/
int CGifDecoder::GetLoopCount() 
{
	return loopCount;
}

///**
//* Creates new frame image from current data (and previous
//* frames as specified by their disposition codes).
//*/
//int [] CGifDecoder::GetPixels( Bitmap bitmap )
//{
//	int [] pixels = new int [ 3 * image.Width * image.Height ];
//	int count = 0;
//	for (int th = 0; th < image.Height; th++)
//	{
//		for (int tw = 0; tw < image.Width; tw++)
//		{
//			Color color = bitmap.GetPixel(tw, th);
//			pixels[count] = color.R;
//			count++;
//			pixels[count] = color.G;
//			count++;
//			pixels[count] = color.B;
//			count++;
//		}
//	}
//	return pixels;
//}
//
//void CGifDecoder::SetPixels( int [] pixels )
//{
//	int count = 0;
//	for (int th = 0; th < image.Height; th++)
//	{
//		for (int tw = 0; tw < image.Width; tw++)
//		{
//			Color color = Color.FromArgb( pixels[count++] );
//			bitmap.SetPixel( tw, th, color );
//		}
//	}
//}

void CGifDecoder::SetPixels() 
{
	// expose destination image's pixels as int array
	//		int[] dest =
	//			(( int ) image.getRaster().getDataBuffer()).getData();
	//int[] dest = GetPixels( bitmap );

	// fill in starting image contents based on last image's dispose code
	if (lastDispose > 0) 
	{
		if (lastDispose == 3) 
		{
			// use image before last
			int n = frames.size() - 2;
			if (n > 0) 
			{
				lastImage = frames.at(n - 1);
			} 
			else 
			{
				lastImage = NULL;
			}
		}

		if (lastImage != NULL) 
		{
			//				int[] prev =
			//					((DataBufferInt) lastImage.getRaster().getDataBuffer()).getData();
			//int[] prev = GetPixels( new Bitmap( lastImage ) );
			//Array.Copy(prev, 0, dest, 0, width * height);
			memcpy(image->lpData, lastImage->lpData, width*height*4);
			// copy pixels

			if (lastDispose == 2) 
			{
				// fill last image rect area with background color
				COLORREF c = EMPTYCOLOR;
				if (transparency) 
				{
					c = 0; 	// assume background is transparent
				} 
				else 
				{
					c = lastBgColor;
					//						c = new Color(lastBgColor); // use given background color
				}
				CBrush brush;
				brush.CreateSolidBrush(c);
				image->dc.FillRect(&lastRect, brush);
			}
		}
	}

	// copy each source line to the appropriate place in the destination
	int pass = 1;
	int inc = 8;
	int iline = 0;
	for (int i = 0; i < ih; i++) 
	{
		int line = i;
		if (interlace) 
		{
			if (iline >= ih) 
			{
				pass++;
				switch (pass) 
				{
				case 2 :
					iline = 4;
					break;
				case 3 :
					iline = 2;
					inc = 4;
					break;
				case 4 :
					iline = 1;
					inc = 2;
					break;
				}
			}
			line = iline;
			iline += inc;
		}
		line += iy;
		if (line < height) 
		{
			int k = line * width;
			int dx = k + ix; // start of line in dest
			int dlim = dx + iw; // end of dest line
			if ((k + width) < dlim) 
			{
				dlim = k + width; // past dest edge
			}
			int sx = i * iw; // start of line in source
			while (dx < dlim) 
			{
				// map color and insert in destination
				int index = ((int) pixels[sx++]) & 0xff;
				COLORREF c = act[index];
				if (c != 0) 
				{
					*((COLORREF*)(image->lpData+(4*(width*height-dx)))) = c;
					//dest[dx] = c;
				}
				dx++;
			}
		}
	}
	//SetPixels( dest );
}

/**
* Gets the image contents of frame n.
*
* @return BufferedImage representation of frame, or NULL if n is invalid.
*/
CGifFrame* CGifDecoder::GetFrame(int n) 
{
	if ((n >= 0) && (n < frames.size())) 
	{
		return frames[n];
	}
	return NULL;
}

/**
* Gets image size.
*
* @return GIF image dimensions
*/
CSize CGifDecoder::GetFrameSize() 
{
	return CSize(width, height);
}

/**
* Reads GIF image from stream
*
* @param BufferedInputStream containing GIF file.
* @return read status code (0 = no errors)
*/
int CGifDecoder::Load( fstream* inStream ) 
{
	//Init();
	if ( inStream != NULL) 
	{
		this->inStream = inStream;
		ReadHeader();
		if (!Error()) 
		{
			ReadContents();
			if (frameCount < 0) 
			{
				status = STATUS_FORMAT_ERROR;
			}
		}
		inStream->close();
	} 
	else 
	{
		status = STATUS_OPEN_ERROR;
	}
	for (int i=0; i<frames.size(); i++)
	{
		frames[i]->ReleaseDC();
	}
	if (status == STATUS_OK)
	{
		status = STATUS_DONE;
	}
	return status;
}

/**
* Reads GIF file from specified file/URL source  
* (URL assumed if name contains ":/" or "file:")
*
* @param name String containing source
* @return read status code (0 = no errors)
*/
int CGifDecoder::Load(string file) 
{
	status = STATUS_OK;
	try 
	{
		fstream* fs = new fstream( file.c_str(), ios_base::out | ios_base::binary ) ;
		status = Load(fs);
		fs->close();
	} 
	catch (...) 
	{
		status = STATUS_OPEN_ERROR;
	}
	if (status == STATUS_OK)
	{
		status = STATUS_DONE;
	}
	return status;
}

/**
* Decodes LZW image data into pixel array.
* Adapted from John Cristy's ImageMagick.
*/
void CGifDecoder::DecodeImageData() 
{
	int NullCode = -1;
	int npix = iw * ih;
	int available, 
		clear,
		code_mask,
		code_size,
		end_of_information,
		in_code,
		old_code,
		bits,
		code,
		count,
		i,
		datum,
		data_size,
		first,
		top,
		bi,
		pi;

	//if ((pixels == NULL) || (pixels.Length < npix)) 
	//{
	//	pixels = new byte[npix]; // allocate new pixel array
	//}
	//if (prefix == NULL) prefix = new short[MaxStackSize];
	//if (suffix == NULL) suffix = new byte[MaxStackSize];
	//if (pixelStack == NULL) pixelStack = new byte[MaxStackSize + 1];

	//  Initialize GIF data stream decoder.

	data_size = Read();
	clear = 1 << data_size;
	end_of_information = clear + 1;
	available = clear + 2;
	old_code = NullCode;
	code_size = data_size + 1;
	code_mask = (1 << code_size) - 1;
	for (code = 0; code < clear; code++) 
	{
		prefix[code] = 0;
		suffix[code] = (byte) code;
	}

	//  Decode GIF pixel stream.

	datum = bits = count = first = top = pi = bi = 0;

	for (i = 0; i < npix;) 
	{
		if (top == 0) 
		{
			if (bits < code_size) 
			{
				//  Load bytes until there are enough bits for a code.
				if (count == 0) 
				{
					// Read a new data block.
					count = ReadBlock();
					if (count <= 0)
						break;
					bi = 0;
				}
				datum += (((int) block[bi]) & 0xff) << bits;
				bits += 8;
				bi++;
				count--;
				continue;
			}

			//  Get the next code.

			code = datum & code_mask;
			datum >>= code_size;
			bits -= code_size;

			//  Interpret the code

			if ((code > available) || (code == end_of_information))
				break;
			if (code == clear) 
			{
				//  Reset decoder.
				code_size = data_size + 1;
				code_mask = (1 << code_size) - 1;
				available = clear + 2;
				old_code = NullCode;
				continue;
			}
			if (old_code == NullCode) 
			{
				pixelStack[top++] = suffix[code];
				old_code = code;
				first = code;
				continue;
			}
			in_code = code;
			if (code == available) 
			{
				pixelStack[top++] = (byte) first;
				code = old_code;
			}
			while (code > clear) 
			{
				pixelStack[top++] = suffix[code];
				code = prefix[code];
			}
			first = ((int) suffix[code]) & 0xff;

			//  Add a new string to the string table,

			if (available >= MaxStackSize)
				break;
			pixelStack[top++] = (byte) first;
			prefix[available] = (short) old_code;
			suffix[available] = (byte) first;
			available++;
			if (((available & code_mask) == 0)
				&& (available < MaxStackSize)) 
			{
				code_size++;
				code_mask += available;
			}
			old_code = in_code;
		}

		//  Pop a pixel off the pixel stack.

		top--;
		pixels[pi++] = pixelStack[top];
		i++;
	}

	npix-=pi;
	if (npix)
	{
		memset(pixels+pi, 0, npix);
	}

	//for (i = pi; i < npix; i++) 
	//{
	//	pixels[i] = 0; // clear missing pixels
	//}

}

/**
* Returns true if an error was encountered during reading/decoding
*/
bool CGifDecoder::Error() 
{
	return status >= 0;
}

///**
//* Initializes or re-initializes reader
//*/
//void CGifDecoder::Init() 
//{
//	status = STATUS_OK;
//	frameCount = 0;
//	frames.clear();
//	SAVEDEL(gct);
//	SAVEDEL(lct);
//}

/**
* Reads a single byte from the input stream.
*/
int CGifDecoder::Read() 
{
	int curByte = 0;
	try 
	{
		inStream->read((char*)(&curByte), 1);
		if (inStream->fail())
		{
			status = STATUS_FORMAT_ERROR;
		}
	} 
	catch (...) 
	{
		status = STATUS_FORMAT_ERROR;
	}
	return curByte;
}

/**
* Reads next variable length block from input.
*
* @return number of bytes stored in "buffer"
*/
int CGifDecoder::ReadBlock() 
{
	blockSize = Read();
	int n = 0;
	if (blockSize > 0) 
	{
		try 
		{
			int count = 0;
			while (n < blockSize) 
			{
				inStream->read((char*)(&block[n]), blockSize - n);
				if(inStream->fail())
				{
					break;
				}

				//if (count <= -1) 
				//if (count <= 0) 
				//	break;
				n += count;
			}
		} 
		catch (...) 
		{
		}

		if (n < blockSize) 
		{
			status = STATUS_FORMAT_ERROR;
		}
	}
	return n;
}

/**
* Reads color table as 256 RGB integer values
*
* @param ncolors int number of colors to read
* @return int array containing 256 colors (packed ARGB with full alpha)
*/
void CGifDecoder::ReadColorTable(int ncolors, COLORREF* tab) 
{
	int nbytes = 3 * ncolors;
	//COLORREF* tab = NULL;
	byte* c = new byte[nbytes];
	int n = 0;
	try 
	{
		inStream->read((char*)c, nbytes );
		if (!inStream->fail())
		{
			n = nbytes;
		}
	} 
	catch (...) 
	{
	}
	if (n < nbytes) 
	{
		status = STATUS_FORMAT_ERROR;
	} 
	else 
	{
		//tab = new COLORREF[256]; // max size to avoid bounds checks
		int i = 0;
		int j = 0;
		while (i < ncolors) 
		{
			int r = ((int) c[j++]) & 0xff;
			int g = ((int) c[j++]) & 0xff;
			int b = ((int) c[j++]) & 0xff;
			tab[i++] = ( COLORREF ) ( 0xff000000 | (r << 16) | (g << 8) | b );
		}
	}
	delete c;
	//return tab;
}

/**
* Main file parser.  Reads GIF content blocks.
*/
void CGifDecoder::ReadContents() 
{
	// read GIF file content blocks
	CDCHandle dcScreen = GetDC(NULL);
	bool done = false;
	string app = "NETSCAPE2.0";
	while (!(done || Error())) 
	{
		int code = Read();
		switch (code) 
		{

		case 0x2C : // image separator
			ReadImage(dcScreen);
			break;

		case 0x21 : // extension
			code = Read();
			switch (code) 
			{
			case 0xf9 : // graphics control extension
				ReadGraphicControlExt();
				break;

			case 0xff : // application extension
				ReadBlock();
				//for (int i = 0; i < 11; i++) 
				//{
				//	app += (char) block[i];
				//}
				if (app.compare(0,11,(char*)block,11)==0) 
				{
					ReadNetscapeExt();
				}
				else
				{
					Skip(); // don't care
				}
				break;

			default : // uninteresting extension
				Skip();
				break;
			}
			break;

		case 0x3b : // terminator
			done = true;
			break;

		case 0x00 : // bad byte, but keep going and see what happens
			break;

		default :
			status = STATUS_FORMAT_ERROR;
			break;
		}
	}
	::ReleaseDC(NULL,dcScreen);
}

/**
* Reads Graphics Control Extension values
*/
void CGifDecoder::ReadGraphicControlExt() 
{
	Read(); // block size
	int packed = Read(); // packed fields
	dispose = (packed & 0x1c) >> 2; // disposal method
	if (dispose == 0) 
	{
		dispose = 1; // elect to keep old image if discretionary
	}
	transparency = (packed & 1) != 0;
	delay = ReadShort() * 10; // delay in milliseconds
	transIndex = Read(); // transparent color index
	Read(); // block terminator
}

/**
* Reads GIF file header information.
*/
void CGifDecoder::ReadHeader() 
{
	string id = "";
	for (int i = 0; i < 6; i++) 
	{
		id += (char) Read();
	}
	if (!id.compare(0,3,"GIF",3)!=0) 
	{
		status = STATUS_FORMAT_ERROR;
		return;
	}

	ReadLSD();
	if (gctFlag && !Error()) 
	{
		ReadColorTable(gctSize, gct);
		bgColor = gct[bgIndex];
	}
}

/**
* Reads next frame image
*/
void CGifDecoder::ReadImage(CDCHandle& dcScreen) 
{
	ix = ReadShort(); // (sub)image position & size
	iy = ReadShort();
	iw = ReadShort();
	ih = ReadShort();

	int packed = Read();
	lctFlag = (packed & 0x80) != 0; // 1 - local color table flag
	interlace = (packed & 0x40) != 0; // 2 - interlace flag
	// 3 - sort flag
	// 4-5 - reserved
	lctSize = 2 << (packed & 7); // 6-8 - local color table size

	if (lctFlag) 
	{
		ReadColorTable(lctSize, lct); // read table
		act = lct; // make local table active
	} 
	else 
	{
		act = gct; // make global table active
		if (bgIndex == transIndex)
			bgColor = 0;
	}
	int save = 0;
	if (transparency) 
	{
		save = act[transIndex];
		act[transIndex] = 0; // set transparent color if specified
	}

	if (act == NULL) 
	{
		status = STATUS_FORMAT_ERROR; // no color table defined
	}

	if (Error()) return;

	DecodeImageData(); // decode pixel data
	Skip();

	if (Error()) return;

	frameCount++;

	// create new image to receive frame data
	//		image =
	//			new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB_PRE);

	image = new CGifFrame(width, height, dcScreen);
	SetPixels(); // transfer pixel data to image

	frames.push_back(image);

	if (transparency) 
	{
		act[transIndex] = save;
	}
	ResetFrame();

}

/**
* Reads Logical Screen Descriptor
*/
void CGifDecoder::ReadLSD() 
{

	// logical screen size
	width = ReadShort();
	height = ReadShort();
	pixels = new byte[width*height];

	// packed fields
	int packed = Read();
	gctFlag = (packed & 0x80) != 0; // 1   : global color table flag
	// 2-4 : color resolution
	// 5   : gct sort flag
	gctSize = 2 << (packed & 7); // 6-8 : gct size

	bgIndex = Read(); // background color index
	pixelAspect = Read(); // pixel aspect ratio
}

/**
* Reads Netscape extenstion to obtain iteration count
*/
void CGifDecoder::ReadNetscapeExt() 
{
	do 
	{
		ReadBlock();
		if (block[0] == 1) 
		{
			// loop count sub-block
			int b1 = ((int) block[1]) & 0xff;
			int b2 = ((int) block[2]) & 0xff;
			loopCount = (b2 << 8) | b1;
		}
	} while ((blockSize > 0) && !Error());
}

/**
* Reads next 16-bit value, LSB first
*/
int CGifDecoder::ReadShort() 
{
	// read 16-bit value, LSB first
	return Read() | (Read() << 8);
}

/**
* Resets frame state for reading next image.
*/
void CGifDecoder::ResetFrame() 
{
	lastDispose = dispose;
	lastRect.left = ix;
	lastRect.top = iy;
	lastRect.right = ix+iw;
	lastRect.bottom = iy+ih;
	//lastRect = new Rectangle(ix, iy, iw, ih);
	lastImage = image;
	lastBgColor = bgColor;
	//		int dispose = 0;
	bool transparency = false;
	int delay = 0;
	//lct = NULL;
}

/**
* Skips variable length blocks up to and including
* next zero length block.
*/
void CGifDecoder::Skip() 
{
	do 
	{
		ReadBlock();
	} while ((blockSize > 0) && !Error());
}