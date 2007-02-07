#include "defines.h"



class CGifFrame 
{
	friend class CGifDecoder;
	CGifFrame(int width, int height, CDCHandle& dcScreen);
	HBITMAP hBmp, hBmp0;
	LPBYTE lpData;
	int delay;
	COLORREF transparent;
	CDC dc;
	int w, h;
	void ReleaseDC();
public:
	HBITMAP GetBitmap();
	CSize GetSize();
	int GetDelay();
	COLORREF GetTransparent();
	LPBYTE GetData();
	int ReplaceTransparent(COLORREF clr);
};
