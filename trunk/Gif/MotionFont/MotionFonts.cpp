#include "MotionFonts.h"
#include "AnimatedGifEncoder.h"
#include <math.h>

inline void RectToEllipse(CDC& dc, RECT& rc, COLORREF transparent)
{
	int dx = rc.right-rc.left, dy = rc.bottom-rc.top, dx1 = dx/2, dx2 = dx -dx1, dy1=dy/2, dy2=dy-dy1;

	for (int y=dy1; y<dy; y++)
	{
		double d = (double)(y)/(double)(dy-1);
		d = 1 - 2* d;
		int da = (int)(sqrt(1-d*d)*dx), da1 = da/2, da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			double dd = (double)(x+1)/(double)(dx2+1);
			int db = (int)(sqrt(1-dd*dd)*dy), db1 = db/2, db2 = db - db1;
			for (int xx=x*dx2/da2, end = (x+1)*dx2/da2; xx<end; xx++)
			{
				for(int yy=(y-dy1)*dy2/db2, yend = (y-dy1+1)*dy2/db2; yy<yend; yy++)
				{
					COLORREF clr = dc.GetPixel(rc.left+dx1+xx, rc.top+dy1+yy);
					if (clr != transparent)
					{
						n++;
						r+=GetRValue(clr);
						g+=GetGValue(clr);
						b+=GetBValue(clr);
					}
				}
			}
			if (n)
			{
				dc.SetPixel(rc.left+dx1+x, rc.top+y, RGB(r/n,g/n,b/n));
			}
			else
			{
				dc.SetPixel(rc.left+dx1+x, rc.top+y, transparent);
			}
		}
		for (int x=da2; x<dx2; x++)
		{
			dc.SetPixel(rc.left+dx1+x,rc.top+y, transparent);
		}

		for (int x=0; x<da1; x++)
		{
			int r=0,g=0,b=0,n=0;
			double dd = (double)(x+1)/(double)(dx1+1);
			int db = (int)(sqrt(1-dd*dd)*dy), db1 = db/2, db2 = db - db1;
			for (int xx=x*dx1/da1, end = (x+1)*dx1/da1; xx<end; xx++)
			{
				for(int yy=(y-dy1)*dy2/db2, yend = (y-dy1+1)*dy2/db2; yy<yend; yy++)
				{
					COLORREF clr = dc.GetPixel(rc.left+dx1-xx-1, rc.top+dy1+yy);
					if (clr != transparent)
					{
						n++;
						r+=GetRValue(clr);
						g+=GetGValue(clr);
						b+=GetBValue(clr);
					}
				}
			}
			if (n)
			{
				dc.SetPixel(rc.left+dx1-x-1, rc.top+y, RGB(r/n,g/n,b/n));
			}
			else
			{
				dc.SetPixel(rc.left+dx1-x-1, rc.top+y, transparent);
			}
		}
		for (int x=da1; x<dx1; x++)
		{
			dc.SetPixel(rc.left+dx1-x-1,rc.top+y, transparent);
		}
	}
	for (int y=dy1-1; y>=0; y--)
	{
		double d = (double)(y)/(double)(dy-1);
		d = 1 - 2* d;
		int da = (int)(sqrt(1-d*d)*dx), da1 = da/2, da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			double dd = (double)(x+1)/(double)(dx2+1);
			int db = (int)(sqrt(1-dd*dd)*dy), db1 = db/2, db2 = db - db1;
			for (int xx=x*dx2/da2, end = (x+1)*dx2/da2; xx<end; xx++)
			{
				for(int yy=(dy1-1-y)*dy1/db1, yend = (dy1-y)*dy1/db1; yy<yend; yy++)
				{
					COLORREF clr = dc.GetPixel(rc.left+dx1+xx, rc.top+dy1-yy-1);
					if (clr != transparent)
					{
						n++;
						r+=GetRValue(clr);
						g+=GetGValue(clr);
						b+=GetBValue(clr);
					}
				}
			}
			if (n)
			{
				dc.SetPixel(rc.left+dx1+x, rc.top+y, RGB(r/n,g/n,b/n));
			}
			else
			{
				dc.SetPixel(rc.left+dx1+x, rc.top+y, transparent);
			}
		}
		for (int x=da2; x<dx2; x++)
		{
			dc.SetPixel(rc.left+dx1+x,rc.top+y, transparent);
		}

		for (int x=0; x<da1; x++)
		{
			int r=0,g=0,b=0,n=0;
			double dd = (double)(x+1)/(double)(dx1+1);
			int db = (int)(sqrt(1-dd*dd)*dy), db1 = db/2, db2 = db - db1;
			for (int xx=x*dx1/da1, end = (x+1)*dx1/da1; xx<end; xx++)
			{
				for(int yy=(dy1-y-1)*dy1/db1, yend = (dy1-y)*dy1/db1; yy<yend; yy++)
				{
					COLORREF clr = dc.GetPixel(rc.left+dx1-xx-1, rc.top+dy1-yy-1);
					if (clr != transparent)
					{
						n++;
						r+=GetRValue(clr);
						g+=GetGValue(clr);
						b+=GetBValue(clr);
					}
				}
			}
			if (n)
			{
				dc.SetPixel(rc.left+dx1-x-1, rc.top+y, RGB(r/n,g/n,b/n));
			}
			else
			{
				dc.SetPixel(rc.left+dx1-x-1, rc.top+y, transparent);
			}
		}
		for (int x=da1; x<dx1; x++)
		{
			dc.SetPixel(rc.left+dx1-x-1,rc.top+y, transparent);
		}
	}
}

inline void RectToTriangle(CDC& dc, RECT& rc, COLORREF transparent)
{
	int dx = rc.right-rc.left, dy = rc.bottom-rc.top, dx1 = dx/2, dx2 = dx -dx1;

	for (int y=0; y<dy; y++)
	{
		double d = (double)(y)/(double)(dy-1);
		int da = (int)(d*dx), da1 = da/2, da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			for (int xx=x*dx2/da2, end = (x+1)*dx2/da2; xx<end; xx++)
			{
				COLORREF clr = dc.GetPixel(rc.left+dx1+xx, rc.top+y);
				if (clr != transparent)
				{
					n++;
					r+=GetRValue(clr);
					g+=GetGValue(clr);
					b+=GetBValue(clr);
				}
			}
			if (n)
			{
				dc.SetPixel(rc.left+dx1+x, rc.top+y, RGB(r/n,g/n,b/n));
			}
			else
			{
				dc.SetPixel(rc.left+dx1+x, rc.top+y, transparent);
			}
		}
		for (int x=da2; x<dx2; x++)
		{
			dc.SetPixel(rc.left+dx1+x,rc.top+y, transparent);
		}

		for (int x=0; x<da1; x++)
		{
			int r=0,g=0,b=0,n=0;
			for (int xx=x*dx1/da1, end = (x+1)*dx1/da1; xx<end; xx++)
			{
				COLORREF clr = dc.GetPixel(rc.left+dx1-xx-1, rc.top+y);
				if (clr != transparent)
				{
					n++;
					r+=GetRValue(clr);
					g+=GetGValue(clr);
					b+=GetBValue(clr);
				}
			}
			if (n)
			{
				dc.SetPixel(rc.left+dx1-x-1, rc.top+y, RGB(r/n,g/n,b/n));
			}
			else
			{
				dc.SetPixel(rc.left+dx1-x-1, rc.top+y, transparent);
			}
		}
		for (int x=da1; x<dx1; x++)
		{
			dc.SetPixel(rc.left+dx1-x-1,rc.top+y, transparent);
		}
	}
}


inline void DrawTextOuter(CDC& dc, string text, CSize& size, int x, int y, COLORREF outer)
{
	RECT r;
	//  1
	// 402
	//  3
	const int xs[4]={1,2,1,0}, ys[4]={0,1,2,1};
	dc.SetTextColor(outer);
	for (int i=3; i>=0; i--)
	{
		r.left = x+xs[i];
		r.top = y+ys[i];
		r.right = x+size.cx+xs[i];
		r.bottom = y+size.cy+ys[i];
		dc.DrawText(text.c_str(), text.length(), &r, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
	}

}

inline void DrawTextEx(CDC& dc, string text, CSize& size, int x, int y, COLORREF clr, COLORREF outer)
{
	DrawTextOuter(dc, text, size, x, y, outer);
	RECT r;
	dc.SetTextColor(clr);
	r.left = x+1;
	r.top = y+1;
	r.right = x+size.cx+1;
	r.bottom = y+size.cy+1;
	dc.DrawText(text.c_str(), text.length(), &r, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
};


bool HueFloatMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	const int shadowD = 4;
	CAnimatedGifEncoder age;
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
			DrawTextEx(dc, text.substr(j,cn), size, x+shadowD, shadowD, 0xb0b0b0, 0xdddddd);
			DrawTextEx(dc, text.substr(j,cn), size, x+1, 1, clr, clr2);
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
	CAnimatedGifEncoder age;
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
		DrawTextEx(dc, text, size, shadowD, shadowD, 0xb0b0b0, 0xdddddd);
		//TEXT
		DrawTextEx(dc, text, size, 0, 0, primaryClr, secondaryClr);



		dc.SelectBitmap(hBm);

		hBm = bmp.Detach();

		age.AddFrame(hBm);
		DeleteObject(hBm);
		::ReleaseDC(NULL,dcScreen.m_hDC);


	return age.Finish();


}

bool EdgedMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	CAnimatedGifEncoder age;
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


	DrawTextEx(dc, text, size, 0, 0, primaryClr, secondaryClr);



	dc.SelectBitmap(hBm);

	hBm = bmp.Detach();

	age.AddFrame(hBm);
	DeleteObject(hBm);
	::ReleaseDC(NULL,dcScreen.m_hDC);


	return age.Finish();

}

bool DisappearingMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	CAnimatedGifEncoder age;
	age.Start(filename);
	age.SetQuality(1);
	age.SetTransparent(transparent);
	age.SetRepeat(0);
	age.SetDelay(200);
	RECT r;
	HBITMAP bms[4];

	CDCHandle dcScreen = GetDC(NULL);
	CDC dc;
	dc.CreateCompatibleDC(dcScreen);
	dc.SetBkMode(TRANSPARENT);
	dc.SelectFont(hFont);
	CSize size;
	dc.GetTextExtent(text.c_str(), text.length(), &size);
	int w = size.cx+2, h = size.cy+2;
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(dcScreen,size.cx+2,size.cy+2);
	HBITMAP hBm = dc.SelectBitmap(bmp);
	r.left = 0;
	r.top = 0;
	r.right = w;
	r.bottom = h;
	CBrush brush;
	brush.CreateSolidBrush(transparent);
	dc.FillRect(&r, brush);


	DrawTextEx(dc, text, size, 0, 0, primaryClr, secondaryClr);




	for (int i=0,d=1; i<4; i++, d<<=1)
	{
		CDC dc1;
		dc1.CreateCompatibleDC(dcScreen);
		CBitmap bmp1;
		bmp1.CreateCompatibleBitmap(dcScreen,w,h);
		bms[i] = dc1.SelectBitmap(bmp1);
		r.left = 0;
		r.top = 0;
		r.right = w;
		r.bottom = h;
		dc1.FillRect(&r, brush);

		for (int th=0; th<h; th++)
		{
			for (int tw=0; tw<w; tw++)
			{
				COLORREF clr = dc.GetPixel(tw, th);
				if(clr != transparent && (rand()%3)>=i)
				{
					dc1.SetPixel(tw-i-1+(rand()%(2*i+3)), th-i-1+(rand()%(2*i+3)),clr);
				}
			}
		}

		dc1.SelectBitmap(bms[i]);
		bms[i] = bmp1.Detach();
	}
	dc.SelectBitmap(hBm);
	hBm = bmp.Detach();
	age.AddFrame(hBm);
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
	DeleteObject(hBm);
	::ReleaseDC(NULL,dcScreen.m_hDC);

	return age.Finish();

	
}


bool EllipseMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	const int shadowD = 4;
	CAnimatedGifEncoder age;
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
		int cn = (text[j]<0)?2:1;
		DrawTextEx(dc, text.substr(j,cn), size, x+shadowD, shadowD, 0xb0b0b0, 0xdddddd);
		DrawTextEx(dc, text.substr(j,cn), size, x+1, 1, primaryClr, secondaryClr);
		r.left = x+1;
		r.top = 1;
		r.right = w;
		r.bottom = h;
		dc.DrawText(pc+j, cn, &r, DT_CALCRECT);

		x = r.right+1;

		r.left-=1;
		r.right+=shadowD+2;
		r.top-=1;
		r.bottom+=shadowD+2;
		RectToEllipse(dc, r, transparent);
		j+=cn;
	}


	dc.SelectBitmap(hBm);

	hBm = bmp.Detach();

	age.AddFrame(hBm);
	DeleteObject(hBm);
	::ReleaseDC(NULL,dcScreen.m_hDC);
	return age.Finish();
}
bool TriangleMFont(string filename, string text, HFONT hFont, COLORREF transparent, COLORREF primaryClr, COLORREF secondaryClr)
{
	const int shadowD = 4;
	CAnimatedGifEncoder age;
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
		int cn = (text[j]<0)?2:1;
		DrawTextEx(dc, text.substr(j,cn), size, x+shadowD, shadowD, 0xb0b0b0, 0xdddddd);
		DrawTextEx(dc, text.substr(j,cn), size, x+1, 1, primaryClr, secondaryClr);
		r.left = x+1;
		r.top = 1;
		r.right = w;
		r.bottom = h;
		dc.DrawText(pc+j, cn, &r, DT_CALCRECT);

		x = r.right+1;

		r.left-=1;
		r.right+=shadowD+2;
		r.top-=1;
		r.bottom+=shadowD+2;
		RectToTriangle(dc, r, transparent);
		j+=cn;
	}


	dc.SelectBitmap(hBm);

	hBm = bmp.Detach();

	age.AddFrame(hBm);
	DeleteObject(hBm);
	::ReleaseDC(NULL,dcScreen.m_hDC);
	return age.Finish();
}

