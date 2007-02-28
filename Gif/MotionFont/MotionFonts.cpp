#include "MotionFonts.h"
#include "GifEncoder.h"
#include <math.h>
#include "drawing.h"




bool HueFloatMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	const int shadowD = 4;
	CGifEncoder age;
	age.Start(filename);
	age.SetQuality(1);
	age.SetTransparent(transparent);
	age.SetRepeat(0);
	age.SetDelay(20);
	RECT r;
	float h,s,v,h2,s2,v2;
	int len = text.length();
	const char* pc = text.c_str();
	GetHSBbyRGB(primaryClr, h, s, v);
	GetHSBbyRGB(secondaryClr, h2, s2, v2);
	for (int i=0; i<12; i++)
	{
		CDCHandle dcScreen = GetDC(NULL);
		CDC dc;
		dc.CreateCompatibleDC(dcScreen);
		dc.SetBkMode(TRANSPARENT);
		dc.SelectFont(hFont);
		CSize size;
		dc.GetTextExtent(pc, text.length(), &size);
		int w = size.cx+shadowD+2*len, h = size.cy+shadowD+2;
		CBitmap bmp;
		bmp.CreateCompatibleBitmap(dcScreen, w, h);
		HBITMAP hBm = dc.SelectBitmap(bmp);
		
		r.left = 0;
		r.top = 0;
		r.right = w;
		r.bottom = h;
		CBrush brush;
		brush.CreateSolidBrush(transparent);
		dc.FillRect(&r, brush);

		int x = 0;
		for (int j=0; j<len; )
		{
			COLORREF 
				clr = GetRGBbyHSB(1+h+(float)j/(float)len-(float)i/(float)12, s, v),
				clr2 = GetRGBbyHSB(1+h+(float)j/(float)len-(float)i/(float)12, s2/2, v2);
			int cn = (text[j]<0)?2:1;
			DrawTextWithOuter(dc, text.substr(j,cn), size, x+shadowD, shadowD, 0xb0b0b0, 0xdddddd);
			DrawTextWithOuter(dc, text.substr(j,cn), size, x+1, 1, clr, clr2);
			r.left = x+1;
			r.top = 1;
			r.right = w;
			r.bottom = h;
			dc.DrawText(pc+j, cn, &r, DT_CALCRECT);
			x = r.right+1;
			j+=cn;
		}


		//float h1, h2, s1, s2, v1, v2, f, ff;
		//COLORREF clr;
		//GetHSBbyRGB(transparent, h1, s1, v1);
		//ff = fabsf(s-s1)/4;
		//for (int tw=0; tw<size.cx; tw++)
		//{
		//	bool b = false;
		//	for (int th=0; th<size.cy; th++)
		//	{
		//		GetHSBbyRGB(clr = dc.GetPixel(tw, th), h2, s2, v2);
		//		f = fabsf(s1-s2);
		//		if (secondaryClr==clr || f<ff)
		//		{
		//			if (b)
		//			{
		//				dc.SetPixel(tw,th, secondaryClr);
		//			}
		//			b = false;
		//		}
		//		else
		//		{
		//			b = true;
		//		}
		//	}
		//}
		//for (int tw=0; tw<size.cx; tw++)
		//{
		//	bool b = false;
		//	for (int th=size.cy-1; th>=0; th--)
		//	{
		//		GetHSBbyRGB(clr = dc.GetPixel(tw, th), h2, s2, v2);
		//		f = fabsf(s1-s2);
		//		if (secondaryClr==clr || f<ff)
		//		{
		//			if (b)
		//			{
		//				dc.SetPixel(tw,th, secondaryClr);
		//			}
		//			b = false;
		//		}
		//		else
		//		{
		//			b = true;
		//		}
		//	}
		//}
		//for (int th=0; th<size.cy; th++)
		//{
		//	bool b = false;
		//	for (int tw=0; tw<size.cx; tw++)
		//	{
		//		GetHSBbyRGB(clr = dc.GetPixel(tw, th), h2, s2, v2);
		//		f = fabsf(s1-s2);
		//		if (secondaryClr==clr || f<ff)
		//		{
		//			if (b)
		//			{
		//				dc.SetPixel(tw, th, secondaryClr);
		//			}
		//			b = false;
		//		}
		//		else
		//		{
		//			b = true;
		//		}
		//	}
		//}
		//for (int th=0; th<size.cy; th++)
		//{
		//	bool b = false;
		//	for (int tw=size.cx-1; tw>=0; tw--)
		//	{
		//		GetHSBbyRGB(clr = dc.GetPixel(tw, th), h2, s2, v2);
		//		f = fabsf(s1-s2);
		//		if (secondaryClr==clr || f<ff)
		//		{
		//			if (b)
		//			{
		//				dc.SetPixel(tw, th, secondaryClr);
		//			}
		//			b = false;
		//		}
		//		else
		//		{
		//			b = true;
		//		}
		//	}
		//}


		dc.SelectBitmap(hBm);

		hBm = bmp.Detach();

		age.AddFrame(hBm);
		DeleteObject(hBm);
		::ReleaseDC(NULL,dcScreen.m_hDC);
	}
	return age.Finish();
}

bool ShapeShadowedMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	const int shadowD = 4;
	CGifEncoder age;
	age.Start(filename);
	age.SetQuality(1);
	age.SetTransparent(transparent);
	age.SetRepeat(0);
	age.SetDelay(500);
	RECT r;

		CDCHandle dcScreen = GetDC(NULL);
		CDC dc;
		dc.CreateCompatibleDC(dcScreen);
		dc.SetBkMode(TRANSPARENT);
		dc.SelectFont(hFont);
		CSize size;
		dc.GetTextExtent(text.c_str(), text.length(), &size);
		CBitmap bmp;
		bmp.CreateCompatibleBitmap(dcScreen,size.cx+shadowD+2,size.cy+shadowD+2);
		HBITMAP hBm = dc.SelectBitmap(bmp);
		r.left = 0;
		r.top = 0;
		r.right = size.cx+shadowD+2;
		r.bottom = size.cy+shadowD+2;
		CBrush brush;
		brush.CreateSolidBrush(transparent);
		dc.FillRect(&r, brush);

		
		//Shadow
		DrawTextWithOuter(dc, text, size, shadowD, shadowD, 0xb0b0b0, 0xdddddd);
		//TEXT
		DrawTextWithOuter(dc, text, size, 0, 0, primaryClr, secondaryClr);



		dc.SelectBitmap(hBm);

		hBm = bmp.Detach();

		age.AddFrame(hBm);
		DeleteObject(hBm);
		::ReleaseDC(NULL,dcScreen.m_hDC);


	return age.Finish();


}

bool EdgedMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	CGifEncoder age;
	age.Start(filename);
	age.SetQuality(1);
	age.SetTransparent(transparent);
	age.SetRepeat(0);
	age.SetDelay(500);
	RECT r;

	CDCHandle dcScreen = GetDC(NULL);
	CDC dc;
	dc.CreateCompatibleDC(dcScreen);
	dc.SetBkMode(TRANSPARENT);
	dc.SelectFont(hFont);
	CSize size;
	dc.GetTextExtent(text.c_str(), text.length(), &size);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(dcScreen,size.cx+2,size.cy+2);
	HBITMAP hBm = dc.SelectBitmap(bmp);
	r.left = 0;
	r.top = 0;
	r.right = size.cx+2;
	r.bottom = size.cy+2;
	CBrush brush;
	brush.CreateSolidBrush(transparent);
	dc.FillRect(&r, brush);


	DrawTextWithOuter(dc, text, size, 0, 0, primaryClr, secondaryClr);



	dc.SelectBitmap(hBm);

	hBm = bmp.Detach();

	age.AddFrame(hBm);
	DeleteObject(hBm);
	::ReleaseDC(NULL,dcScreen.m_hDC);


	return age.Finish();

}

bool DisappearingMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	CGifEncoder age;
	age.Start(filename);
	age.SetQuality(1);
	age.SetTransparent(transparent);
	age.SetRepeat(0);
	age.SetDelay(200);
	RECT r;
	HBITMAP bms[4];

	CDCHandle dcScreen = GetDC(NULL);
	CDC dc, dc1;
	dc.CreateCompatibleDC(dcScreen);
	dc1.CreateCompatibleDC(dcScreen);
	dc.SetBkMode(TRANSPARENT);
	dc.SelectFont(hFont);
	CSize size;
	dc.GetTextExtent(text.c_str(), text.length(), &size);
	int w = size.cx+2, h = size.cy+2;
	//CBitmap bmp;
	//bmp.CreateCompatibleBitmap(dcScreen,size.cx+2,size.cy+2);
	//HBITMAP hBm = dc.SelectBitmap(bmp);
	LPBYTE lpData = NULL, lpData1 = NULL;
	HBITMAP 
		hBm = CreateDIB(dcScreen, w, h, lpData),
		hBmp = dc.SelectBitmap(hBm), hBmp1;
	r.left = 0;
	r.top = 0;
	r.right = w;
	r.bottom = h;
	CBrush brush;
	brush.CreateSolidBrush(transparent);
	dc.FillRect(&r, brush);


	DrawTextWithOuter(dc, text, size, 0, 0, primaryClr, secondaryClr);

	DIB32COLOR clr, trans = RGB2DIB(transparent);


	for (int i=0,d=1; i<4; i++, d<<=1)
	{
		bms[i] = CreateDIB(dcScreen, w, h, lpData1);
		hBmp1 = dc1.SelectBitmap(bms[i]);
		r.left = 0;
		r.top = 0;
		r.right = w;
		r.bottom = h;
		dc1.FillRect(&r, brush);

		for (int th=0; th<h; th++)
		{
			for (int tw=0; tw<w; tw++)
			{
				clr = DIBPixel(lpData, tw, th, w, h);
				if(clr != trans && (rand()%3)>=i)
				{
					int x = tw-i-1+(rand()%(2*i+3)), y = th-i-1+(rand()%(2*i+3));
					if (x>=0&&x<w&&y>=0&&y<h)
					{
						DIBPixel(lpData1, x, y, w, h) = clr;
					}
				}
			}
		}
		dc1.SelectBitmap(hBmp1);
	}
	dc.SelectBitmap(hBmp);
	age.AddFrame(hBm);
	DeleteObject(hBm);
	//0,1,2
	for (int i=0; i<3; i++)
	{
		age.AddFrame(bms[i]);
	}
	//3,2,1,0
	for (int i=3;i>=0; i--)
	{
		age.AddFrame(bms[i]);
		DeleteObject(bms[i]);
	}
	::ReleaseDC(NULL,dcScreen.m_hDC);

	return age.Finish();

	
}


bool EllipseMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	const int shadowD = 4;
	CGifEncoder age;
	age.Start(filename);
	age.SetQuality(1);
	age.SetTransparent(transparent);
	//age.SetRepeat(0);
	//age.SetDelay(20);
	RECT r;
	int len = text.length();
	const char* pc = text.c_str();
	CDCHandle dcScreen = GetDC(NULL);
	CDC dc;
	dc.CreateCompatibleDC(dcScreen);
	dc.SetBkMode(TRANSPARENT);
	dc.SelectFont(hFont);
	CSize size;
	dc.GetTextExtent(pc, text.length(), &size);
	int w = size.cx+shadowD+2*len, h = size.cy+shadowD+2;
	//CBitmap bmp;
	//bmp.CreateCompatibleBitmap(dcScreen, w, h);
	LPBYTE lpData = NULL;
	HBITMAP 
		hBm = CreateDIB(dcScreen, w, h, lpData),
		hBmp = dc.SelectBitmap(hBm);

	r.left = 0;
	r.top = 0;
	r.right = w;
	r.bottom = h;
	CBrush brush;
	brush.CreateSolidBrush(transparent);
	dc.FillRect(&r, brush);

	DIB32COLOR trans = RGB2DIB(transparent);
	int x = 0;
	for (int j=0; j<len; )
	{
		int cn = (text[j]<0)?2:1;
		DrawTextWithOuter(dc, text.substr(j,cn), size, x+shadowD, shadowD, 0xb0b0b0, 0xdddddd);
		DrawTextWithOuter(dc, text.substr(j,cn), size, x+1, 1, primaryClr, secondaryClr);
		r.left = x+1;
		r.top = 1;
		r.right = w;
		r.bottom = h;
		dc.DrawText(pc+j, cn, &r, DT_CALCRECT);

		x = r.right+1;

		r.left-=1;
		r.top-=1;
		r.right+=shadowD+1;
		r.bottom+=shadowD+1;
		RectToEllipse(lpData, w, h, r, trans);
		j+=cn;
	}


	dc.SelectBitmap(hBmp);
	age.AddFrame(hBm);
	DeleteObject(hBm);
	::ReleaseDC(NULL,dcScreen.m_hDC);
	return age.Finish();
}
bool TriangleMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	const int shadowD = 4;
	CGifEncoder age;
	age.Start(filename);
	age.SetQuality(1);
	age.SetTransparent(transparent);
	age.SetRepeat(0);
	age.SetDelay(20);
	RECT r;
	int len = text.length();
	const char* pc = text.c_str();
	CDCHandle dcScreen = GetDC(NULL);
	CDC dc;
	dc.CreateCompatibleDC(dcScreen);
	dc.SetBkMode(TRANSPARENT);
	dc.SelectFont(hFont);
	CSize size;
	dc.GetTextExtent(pc, text.length(), &size);
	int w = size.cx+shadowD+2*len-2, h = size.cy+shadowD+2;
	size.cx = w;
	size.cy = h;
	//CBitmap bmp;
	//bmp.CreateCompatibleBitmap(dcScreen, w, h);
	//HBITMAP hBm = dc.SelectBitmap(bmp);
	LPBYTE lpData = NULL;
	HBITMAP 
		hBm = CreateDIB(dcScreen, w, h, lpData),
		hBmp = dc.SelectBitmap(hBm);

	r.left = 0;
	r.top = 0;
	r.right = w;
	r.bottom = h;
	CBrush brush;
	brush.CreateSolidBrush(transparent);
	dc.FillRect(&r, brush);

	DIB32COLOR trans = RGB2DIB(transparent);
	int x = 0;
	for (int j=0; j<len; )
	{
		int cn = (text[j]<0)?2:1;
		DrawTextWithOuter(dc, text.substr(j,cn), size, x+shadowD, shadowD, 0xb0b0b0, 0xdddddd);
		DrawTextWithOuter(dc, text.substr(j,cn), size, x+1, 1, primaryClr, secondaryClr);
		r.left = x+1;
		r.top = 1;
		r.right = w;
		r.bottom = h;
		dc.DrawText(pc+j, cn, &r, DT_CALCRECT);

		x = r.right+1;

		r.left-=1;
		r.right+=shadowD+1;
		r.top-=1;
		r.bottom+=shadowD+1;
		RectToTriangle(lpData, w, h, r, trans);
		j+=cn;
	}


	dc.SelectBitmap(hBmp);
	age.AddFrame(hBm);
	DeleteObject(hBm);
	::ReleaseDC(NULL,dcScreen.m_hDC);
	return age.Finish();
}


//bool ScrollMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
//{
//	CGifEncoder age;
//	age.Start(filename);
//	age.SetQuality(1);
//	age.SetTransparent(transparent);
//	age.SetRepeat(0);
//	age.SetDelay(500);
//	RECT r;
//
//	CDCHandle dcScreen = GetDC(NULL);
//	CDC dc;
//	dc.CreateCompatibleDC(dcScreen);
//	dc.SetBkMode(TRANSPARENT);
//	dc.SelectFont(hFont);
//	CSize size;
//	dc.GetTextExtent(text.c_str(), text.length(), &size);
//	size.cx+=2;
//	size.cy+=2;
//	CBitmap bmp;
//	bmp.CreateCompatibleBitmap(dcScreen,size.cx,size.cy);
//	HBITMAP hBm = dc.SelectBitmap(bmp);
//	r.left = 0;
//	r.top = 0;
//	r.right = size.cx;
//	r.bottom = size.cy;
//	CBrush brush;
//	brush.CreateSolidBrush(transparent);
//	dc.FillRect(&r, brush);
//
//	size.cx-=2;
//	size.cy-=2;
//
//	DrawTextWithOuter(dc, text, size, 0, 0, primaryClr, secondaryClr);
//	size.cx+=2;
//	size.cy+=2;
//
//
//	for (double pos = 0; pos<=1; pos+=.05)
//	{
//		CDC dc1;
//		dc1.CreateCompatibleDC(dcScreen);
//		CBitmap bmp1;
//		bmp1.CreateCompatibleBitmap(dcScreen, size.cx, size.cy);
//		HBITMAP hBm1 = dc1.SelectBitmap(bmp1);
//
//		for (int y=size.cy-1; y>=0; y--)
//		{
//			double py = (double)y/(size.cy), py1 = (double)(y+1)/(size.cy);
//			py = 2 * (pos + acos(1-2*py)/(2 * M_PI));
//			py1 = 2 * (pos + acos(1-2*py1)/(2 * M_PI));
//			py1 = (py1 - floor(py));
//			py = (py - floor(py));
//			for (int x = size.cx-1; x>=0; x--)
//			{
//				int r = 0, g = 0, b = 0, n = 0;
//				for (int istart=(int)(py*size.cy), iend = (int)(py1*size.cy), i=istart; i<iend||i==istart; i++)
//				{
//					COLORREF clr = dc.GetPixel(x,i%size.cy);
//					if (clr != transparent)
//					{
//						n++;
//						r += GetRValue(clr);
//						g += GetGValue(clr);
//						b += GetBValue(clr);
//					}
//				}
//				if (n)
//				{
//					dc1.SetPixel(x, y,RGB(r/n,g/n,b/n));
//				}
//				else
//				{
//					dc1.SetPixel(x,y, transparent);
//				}
//			}
//		}
//
//
//
//		dc1.SelectBitmap(hBm1);
//
//		hBm1 = bmp1.Detach();
//
//		age.AddFrame(hBm1);
//		DeleteObject(hBm1);
//	}
//
//
//
//
//	dc.SelectBitmap(hBm);
//
//	hBm = bmp.Detach();
//
//	DeleteObject(hBm);
//	::ReleaseDC(NULL,dcScreen.m_hDC);
//
//
//	return age.Finish();
//
//
//}
//
//
//
//
//
//
//
bool QuadrelScrollMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	CGifEncoder age;
	age.Start(filename);
	age.SetQuality(1);
	age.SetTransparent(transparent);
	age.SetRepeat(0);
	age.SetDelay(500);
	RECT r;

	CDCHandle dcScreen = GetDC(NULL);
	CDC dc, dc0, dc1;
	dc.CreateCompatibleDC(dcScreen);
	dc0.CreateCompatibleDC(dcScreen);
	dc1.CreateCompatibleDC(dcScreen);
	dc.SetBkMode(TRANSPARENT);
	dc0.SetBkMode(TRANSPARENT);
	dc.SelectFont(hFont);
	dc0.SelectFont(hFont);
	CSize size;
	dc.GetTextExtent(text.c_str(), text.length(), &size);
	size.cx+=2;
	size.cy+=2;
	//CBitmap bmp, bmp0;
	//bmp.CreateDIB(dcScreen,size.cx,size.cy);
	//bmp0.CreateCompatibleBitmap(dcScreen,size.cx,size.cy);
	//HBITMAP hBm = dc.SelectBitmap(bmp), hBm0 = dc0.SelectBitmap(bmp0);
	LPBYTE lpData = NULL, lpData0 = NULL, lpData1 = NULL;
	HBITMAP 
		hBm = CreateDIB(dcScreen.m_hDC, size.cx, size.cy, lpData), 
		hBm0 = CreateDIB(dcScreen.m_hDC, size.cx, size.cy, lpData0),
		hBm1 = CreateDIB(dcScreen.m_hDC, size.cx, size.cy, lpData1),
		hBmp = dc.SelectBitmap(hBm),
		hBmp0 = dc0.SelectBitmap(hBm0),
		hBmp1 = dc1.SelectBitmap(hBm1);
	r.left = 0;
	r.top = 0;
	r.right = size.cx;
	r.bottom = size.cy;
	CBrush brush, brush0;
	brush.CreateSolidBrush(transparent);
	brush0.CreateSolidBrush(primaryClr);
	dc.FillRect(&r, brush);
	dc0.FillRect(&r, brush0);

	size.cx-=2;
	size.cy-=2;

	DrawTextWithOuter(dc, text, size, 0, 0, primaryClr, secondaryClr);
	DrawTextWithOuter(dc0, text, size, 0, 0, transparent, secondaryClr);
	size.cx+=2;
	size.cy+=2;

	DIB32COLOR clr, trans = RGB2DIB(transparent);

	for (double pos = 0; pos<=1; pos+=.1)
	{
		int py = (int)(size.cy*pos);
		for (int y=0; y<py; y++)
		{
			for (int x=0; x<size.cx; x++)
			{
				int r = 0, g = 0, b = 0, n = 0;
				for (int yy=y*size.cy/py, yend = (y+1)*size.cy/py; yy<yend; yy++)
				{
					clr = DIBPixel(lpData, x,yy, size.cx, size.cy);
					if (clr != trans)
					{
						n++;
						r += GetR(clr);
						g += GetG(clr);
						b += GetB(clr);
					}
				}
				if (n)
				{
					DIBPixel(lpData1, x, y, size.cx, size.cy) = DIB32RGB(r/n,g/n,b/n);
				}
				else
				{
					DIBPixel(lpData1, x, y, size.cx, size.cy) = trans;
				}
			}
		}
		for (int y=py; y<size.cy; y++)
		{
			for (int x=0; x<size.cx; x++)
			{
				int r = 0, g = 0, b = 0, n = 0;
				for (int yy=(y-py)*size.cy/(size.cy-py), yend = (y+1-py)*size.cy/(size.cy-py); yy<yend; yy++)
				{
					clr = DIBPixel(lpData0, x,yy, size.cx, size.cy);
					if (clr != trans)
					{
						n++;
						r += GetR(clr);
						g += GetG(clr);
						b += GetB(clr);
					}
				}
				if (n)
				{
					DIBPixel(lpData1, x, y, size.cx, size.cy) = DIB32RGB(r/n,g/n,b/n);
				}
				else
				{
					DIBPixel(lpData1, x, y, size.cx, size.cy) = trans;
				}
			}
		}

		dc1.SelectBitmap(hBmp1);
		age.AddFrame(hBm1);
		dc1.SelectBitmap(hBm1);
	}




	for (double pos = 0; pos<=1; pos+=.1)
	{

		int py = (int)(size.cy*pos);
		for (int y=0; y<py; y++)
		{
			for (int x=0; x<size.cx; x++)
			{
				int r = 0, g = 0, b = 0, n = 0;
				for (int yy=y*size.cy/py, yend = (y+1)*size.cy/py; yy<yend; yy++)
				{
					clr = DIBPixel(lpData0, x,yy, size.cx, size.cy);
					if (clr != trans)
					{
						n++;
						r += GetR(clr);
						g += GetG(clr);
						b += GetB(clr);
					}
				}
				if (n)
				{
					DIBPixel(lpData1, x, y, size.cx, size.cy) = DIB32RGB(r/n,g/n,b/n);
				}
				else
				{
					DIBPixel(lpData1, x, y, size.cx, size.cy) = trans;
				}
			}
		}
		for (int y=py; y<size.cy; y++)
		{
			for (int x=0; x<size.cx; x++)
			{
				int r = 0, g = 0, b = 0, n = 0;
				for (int yy=(y-py)*size.cy/(size.cy-py), yend = (y+1-py)*size.cy/(size.cy-py); yy<yend; yy++)
				{
					clr = DIBPixel(lpData, x,yy, size.cx, size.cy);
					if (clr != trans)
					{
						n++;
						r += GetR(clr);
						g += GetG(clr);
						b += GetB(clr);
					}
				}
				if (n)
				{
					DIBPixel(lpData1, x, y, size.cx, size.cy) = DIB32RGB(r/n,g/n,b/n);
				}
				else
				{
					DIBPixel(lpData1, x, y, size.cx, size.cy) = trans;
				}

			}
		}


		dc1.SelectBitmap(hBmp1);
		age.AddFrame(hBm1);
		dc1.SelectBitmap(hBm1);
	}



	dc.SelectBitmap(hBmp);
	dc0.SelectBitmap(hBmp0);
	dc1.SelectBitmap(hBmp1);
	DeleteObject(hBm);
	DeleteObject(hBm0);
	DeleteObject(hBm1);

	::ReleaseDC(NULL,dcScreen.m_hDC);


	return age.Finish();


}







