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
:delay(-1),transparent(EMPTYCOLOR),w(width),h(height)
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
CSize CGifFrame::GetSize()
{
	return CSize(w,h);
}

int CGifFrame::GetDelay()
{
	return delay;
}
COLORREF CGifFrame::GetTransparent()
{
	return transparent;
}

LPBYTE CGifFrame::GetData()
{
	return lpData;
}

int CGifFrame::ReplaceTransparent(COLORREF clr)
{
	byte* pb = (byte*)&clr;
	byte b = pb[0];
	pb[0] = pb[2];
	pb[2] = b;
	int count = 0;
	for (int i=w*h-1; i>=0; i--)
	{
		if(((COLORREF*)lpData)[i] == transparent)
		{
			count++;
			((COLORREF*)lpData)[i] = clr;
		}
	}
	return count;
}

