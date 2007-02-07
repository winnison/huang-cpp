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
	void ReleaseDC();
public:
	HBITMAP GetBitmap();
	int GetDelay();
	COLORREF GetTransparent();
};
