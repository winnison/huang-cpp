#include <fstream>
#include <string>
#include "defines.h"


struct CGifFrame 
{
	CGifFrame(int width, int height, CDCHandle& dcScreen)
		:delay(-1),transparent(EMPTYCOLOR)
	{
		hBmp = CreateDIB(dcScreen, width, height, lpData);
		dc.CreateCompatibleDC(dcScreen);
		hBmp0 = dc.SelectBitmap(hBmp);
	}
	HBITMAP hBmp, hBmp0;
	LPBYTE lpData;
	int delay;
	COLORREF transparent;
	CDC dc;
	void ReleaseDC()
	{
		dc.SelectBitmap(hBmp0);
	}
};

class GifDecoder 
{

	/**
	* File read status: No errors.
	*/
#define STATUS_OK -1

	/**
	* File read status: open source Done.
	*/
#define STATUS_DONE 0

	/**
	* File read status: Error decoding file (may be partially decoded)
	*/
#define STATUS_FORMAT_ERROR 1

	/**
	* File read status: Unable to open source.
	*/
#define STATUS_OPEN_ERROR 2


	fstream* inStream;
	int status;

	int width; // full image width
	int height; // full image height
	bool gctFlag; // global color table used
	int gctSize; // size of global color table
	int loopCount = 1; // iterations; 0 = repeat forever

	COLORREF* gct; // global color table
	COLORREF* lct; // local color table
	COLORREF* act; // active color table

	int bgIndex; // background color index
	int bgColor; // background color
	int lastBgColor; // previous bg color
	int pixelAspect; // pixel aspect ratio

	bool lctFlag; // local color table flag
	bool interlace; // interlace flag
	int lctSize; // local color table size

	int ix, iy, iw, ih; // current image rectangle
	RECT lastRect; // last image rect
	CGifFrame* image;
	CGifFrame* lastImage;
	//HBITMAP image; // current frame
	//CBitmap bitmap;
	//HBITMAP lastImage; // previous frame

	byte block[256]; // current data block
	int blockSize = 0; // block size

	// last graphic control extension info
	int dispose = 0;
	// 0=no action; 1=leave in place; 2=restore to bg; 3=restore to prev
	int lastDispose = 0;
	bool transparency = false; // use transparent color
	int delay = 0; // delay in milliseconds
	int transIndex; // transparent color index

	static const int MaxStackSize = 4096;
	// max decoder pixel stack size

	// LZW decoder working arrays
	short prefix[MaxStackSize];
	byte suffix[MaxStackSize];
	byte pixelStack[MaxStackSize+1];
	LPBYTE pixels;

	vector<CGifFrame*> frames; // frames read from current file
	int frameCount;


	/**
	* Gets display duration for specified frame.
	*
	* @param n int index of frame
	* @return delay in milliseconds
	*/
	int GetDelay(int n) ;


	/**
	* Creates new frame image from current data (and previous
	* frames as specified by their disposition codes).
	*/
	int [] GetPixels( Bitmap bitmap );

	void SetPixels( int [] pixels );

	void SetPixels();
	/**
	* Decodes LZW image data into pixel array.
	* Adapted from John Cristy's ImageMagick.
	*/
	void DecodeImageData();
	/**
	* Returns true if an error was encountered during reading/decoding
	*/
	bool Error();
	///**
	//* Initializes or re-initializes reader
	//*/
	//void Init();
	/**
	* Reads a single byte from the input stream.
	*/
	int Read();
	/**
	* Reads next variable length block from input.
	*
	* @return number of bytes stored in "buffer"
	*/
	int ReadBlock();
	/**
	* Reads color table as 256 RGB integer values
	*
	* @param ncolors int number of colors to read
	* @return int array containing 256 colors (packed ARGB with full alpha)
	*/
	int[] ReadColorTable(int ncolors);
	/**
	* Main file parser.  Reads GIF content blocks.
	*/
	void ReadContents();
	/**
	* Reads Graphics Control Extension values
	*/
	void ReadGraphicControlExt();
	/**
	* Reads GIF file header information.
	*/
	void ReadHeader();
	/**
	* Reads next frame image
	*/
	void ReadImage();
	/**
	* Reads Logical Screen Descriptor
	*/
	void ReadLSD();
	/**
	* Reads Netscape extenstion to obtain iteration count
	*/
	void ReadNetscapeExt();
	/**
	* Reads next 16-bit value, LSB first
	*/
	int ReadShort();
	/**
	* Resets frame state for reading next image.
	*/
	void ResetFrame();
	/**
	* Skips variable length blocks up to and including
	* next zero length block.
	*/
	void Skip();
public:
	GifDecoder();
	/**
	* Gets the number of frames read from file.
	* @return frame count
	*/
	int GetFrameCount() ;

	/**
	* Gets the first (or only) image read.
	*
	* @return BufferedImage containing first frame, or null if none.
	*/
	HBITMAP GetImage() ;

	/**
	* Gets the "Netscape" iteration count, if any.
	* A count of 0 means repeat indefinitiely.
	*
	* @return iteration count if one was specified, else 1.
	*/
	int GetLoopCount() ;
	/**
	* Gets the image contents of frame n.
	*
	* @return BufferedImage representation of frame, or null if n is invalid.
	*/
	HBITMAP GetFrame(int n);

	/**
	* Gets image size.
	*
	* @return GIF image dimensions
	*/
	CSize GetFrameSize();
	/**
	* Reads GIF image from stream
	*
	* @param BufferedInputStream containing GIF file.
	* @return read status code (0 = no errors)
	*/
	int Load( Stream inStream );
	/**
	* Reads GIF file from specified file/URL source  
	* (URL assumed if name contains ":/" or "file:")
	*
	* @param name String containing source
	* @return read status code (0 = no errors)
	*/
	int Load(string name);
}
