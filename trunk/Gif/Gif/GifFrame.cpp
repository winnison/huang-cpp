#include "GifFrame.h"


HBITMAP _CreateDIB(HDC hdc,int cx,int cy, LPBYTE &lpData)
{
	BITMAPINFO bmpInfo = {
		sizeof(bmpInfo.bmiHeader),		//biSize
			cx,							//biWidth
			cy,							//biHeight
			1,							//biPlanes
			4*8				//biBitCount
	};

	return CreateDIBSection(hdc,&bmpInfo,DIB_RGB_COLORS,(void**)&lpData,NULL,0);
}


CGifFrame::CGifFrame(int width, int height, CDCHandle& dcScreen)
:delay(-1),transparent(EMPTYCOLOR)
{
	hBmp = _CreateDIB(dcScreen, width, height, lpData);
	dc.CreateCompatibleDC(dcScreen);
	hBmp0 = dc.SelectBitmap(hBmp);
}


void CGifFrame::ReleaseDC()
{
	dc.SelectBitmap(hBmp0);
	hBmp0 = NULL;
}

HBITMAP CGifFrame::GetBitmap()
{
	return hBmp;
}
int CGifFrame::GetDelay()
{
	return delay;
}
COLORREF CGifFrame::GetTransparent()
{
	return transparent;
}

bool CGifFrame::IsTransparency()
{
	return transparent != EMPTYCOLOR;
}
LPBYTE CGifFrame::GetData()
{
	return lpData;
}
