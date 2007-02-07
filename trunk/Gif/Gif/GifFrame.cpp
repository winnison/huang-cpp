#include "GifFrame.h"


HBITMAP CreateDIB(HDC hdc,int cx,int cy, LPBYTE &lpData)
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
	hBmp = CreateDIB(dcScreen, width, height, lpData);
	dc.CreateCompatibleDC(dcScreen);
	hBmp0 = dc.SelectBitmap(hBmp);
}


void CGifFrame::ReleaseDC()
{
	dc.SelectBitmap(hBmp0);
	hBmp0 = NULL;
	dc.DeleteDC();
}

HBITMAP CGifFrame::GetBitmap()
{
	if (hBmp0!=NULL)
	{
		return NULL;
	}
	return hBmp;
}
int CGifFrame::GetDelay()
{
	if (hBmp0!=NULL)
	{
		return -1;
	}
	return delay;
}
COLORREF CGifFrame::GetTransparent()
{
	if (hBmp0!=NULL)
	{
		return EMPTYCOLOR;
	}
	return transparent;
}

