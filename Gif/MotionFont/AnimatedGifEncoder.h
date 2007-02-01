

#include <fstream>
#include <string>
#include "defines.h"


using namespace std;


class CAnimatedGifEncoder
{
	int width; // image size
	int height;
	COLORREF transparent; // transparent color if given
	int transIndex; // transparent index in color table
	int repeat; // no repeat
	int delay; // frame delay (hundredths)
	bool started; // ready to output frames
		//BinaryWriter bw;
	fstream * fs;

	HBITMAP hBitmap; // current frame
	byte * pixels; // BGR byte array from frame
	byte * indexedPixels; // converted frame indexed to palette
	int colorDepth; // number of bit planes
	byte colorTab[NETSIZE*3]; // RGB palette
	bool usedEntry[256]; // active palette entries
	int palSize; // color table size (bits-1)
	int dispose; // disposal code (-1 = use default)
	bool closeStream; // close stream when finished
	bool firstFrame;
	bool sizeSet; // if false, get size from first frame
	int sample; // default sample interval for quantizer

	/**
	* Analyzes image colors and creates color map.
	*/
	void AnalyzePixels();

	/**
	* Returns index of palette color closest to c
	*
	*/
	int FindClosest(COLORREF c);

	/**
	* Extracts image pixels into byte array "pixels"
	*/
	void GetImagePixels();

	/**
	* Writes Graphic Control Extension
	*/
	void WriteGraphicCtrlExt();

	/**
	* Writes Image Descriptor
	*/
	void WriteImageDesc();

	/**
	* Writes Logical Screen Descriptor
	*/
	void WriteLSD();

	/**
	* Writes Netscape application extension to define
	* repeat count.
	*/
	void WriteNetscapeExt();

	/**
	* Writes color table
	*/
	void WritePalette();

	/**
	* Encodes and writes pixel data
	*/
	void WritePixels();

	/**
	*    Write 16-bit value to output stream, LSB first
	*/
	void WriteShort(int value);

	/**
	*    Write 32-bit value to output stream, LSB first
	*/
	void WriteInt(int value);

	/**
	* Writes string to output stream
	*/
	void WriteString(string s);
public:
	CAnimatedGifEncoder(void);
	~CAnimatedGifEncoder();
	/**
	* Sets the delay time between each frame, or changes it
	* for subsequent frames (applies to last frame added).
	*
	* @param ms int delay time in milliseconds
	*/
	void SetDelay(int ms) ;

	/**
	* Sets the GIF frame disposal code for the last added frame
	* and any subsequent frames.  Default is 0 if no transparent
	* color has been set, otherwise 2.
	* @param code int disposal code.
	*/
	void SetDispose(int code) ;

	/**
	* Sets the number of times the set of GIF frames
	* should be played.  Default is 1; 0 means play
	* indefinitely.  Must be invoked before the first
	* image is added.
	*
	* @param iter int number of iterations.
	* @return
	*/
	void SetRepeat(int iter) ;

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
	void SetTransparent(COLORREF c) ;

	/**
	* Sets frame rate in frames per second.  Equivalent to
	* <code>setDelay(1000/fps)</code>.
	*
	* @param fps float frame rate (frames per second)
	*/
	void SetFrameRate(float fps) ;

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
	void SetQuality(int quality) ;

	/**
	* Sets the GIF frame size.  The default size is the
	* size of the first frame added if this method is
	* not invoked.
	*
	* @param w int frame width.
	* @param h int frame width.
	*/
	void SetSize(int w, int h) ;

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
	bool AddFrame(HBITMAP hBitmap);

	/**
	* Flushes any pending data and closes output file.
	* If writing to an OutputStream, the stream is not
	* closed.
	*/
	bool Finish();

	/**
	* Initiates GIF file creation on the given stream.  The stream
	* is not closed automatically.
	*
	* @param os OutputStream on which GIF images are written.
	* @return false if initial write failed.
	*/
	bool Start( fstream* os);

	/**
	* Initiates writing of a GIF file with the specified name.
	*
	* @param file string containing output file name.
	* @return false if open or initial write failed.
	*/
	bool Start(string file);

};

