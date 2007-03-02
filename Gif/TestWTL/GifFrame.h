#include "defines.h"



class CGifFrame 
{
	friend class CGif;
	friend class CGifDecoder;
	CGifFrame(int width, int height, CDCHandle& dcScreen);
	~CGifFrame();
	HBITMAP hBmp;
	LPBYTE lpData;
	int delay;
	COLORREF transparent;
	int w, h;
public:
	HBITMAP GetBitmap();
	CSize GetSize();
	int GetDelay();
	COLORREF GetTransparent();
	LPBYTE GetData();
	int ReplaceTransparent(COLORREF clr);
};
