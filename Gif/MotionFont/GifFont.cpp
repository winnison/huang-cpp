#define _USE_MATH_DEFINES

#include "GifFont.h"
#include "drawing.h"
#include <math.h>

inline void GetChars(vector<string>& chars, string& text)
{
	const char* p = text.c_str();
	for (int i=0, end=text.length(); i<end;)
	{
		if (*(p+i)<0)
		{
			chars.push_back(text.substr(i,2));
			i+=2;
		}
		else
		{
			chars.push_back(text.substr(i,1));
			i++;
		}
	}
}

bool CGifFont::Generate(string& giffile, string& text, HFONT hFont)
{
	if (!IsValid())
	{
		return false;
	}
	CAnimatedGifEncoder age;
	age.Start(giffile);
	age.SetQuality(m_Quality);
	age.SetTransparent(m_Transparent);
	age.SetRepeat(0);
	age.SetDelay(m_Interval);
	vector<string> chars;
	GetChars(chars, text);

	AddFrames(age, chars, hFont);

	age.Finish();


	return true;
}
bool CGifFont::IsValid()
{
	return m_Shape>=0 && m_Shape<SHAPECOUNT && m_Motion>=0 && m_Motion<MOTIONCOUNT;
}

void CGifFont::GetOrignalSize(CDC& dc, vector<string>& chars, int& w, int& h)
{
	w = 0; h = 0;
	CSize size;
	for (int i=0; i<chars.size(); i++)
	{
		dc.GetTextExtent(chars[i].c_str(), chars[i].length(), &size);
		w += size.cx;
		h = max(h,size.cy);
	}
	if (m_HasShadow)
	{
		h += m_ShadowDis+2;
		if (m_HasEdge)
		{
			w += chars.size()*2+m_ShadowDis;
		}
		else
		{
			w += m_ShadowDis+2;
		}
	}
	else if (m_HasEdge)
	{
		w += chars.size()*2;
		h += 2;
	}
}
HBITMAP CGifFont::GetOrignalBitmap(vector<string>& chars, HFONT hFont, LPBYTE& lpData, RECT& r)
{
	CDCHandle dcScreen = GetDC(NULL);
	CDC dc;
	dc.CreateCompatibleDC(dcScreen);
	dc.SetBkMode(TRANSPARENT);
	dc.SelectFont(hFont);
	int w,h;
	GetOrignalSize(dc, chars, w, h);
	r.left = 0;
	r.top = 0;
	r.right = w;
	r.bottom = h;
	lpData = NULL;
	HBITMAP 
		hBm = CreateDIB(dcScreen, w, h, lpData),
		hBmp = dc.SelectBitmap(hBm);
	CBrush brush;
	brush.CreateSolidBrush(m_Transparent);
	dc.FillRect(&r, brush);


	DrawAllChars(dc,lpData,chars,0,0,w,h);
	dc.SelectBitmap(hBmp);
	::ReleaseDC(NULL,dcScreen.m_hDC);
	return hBm;
}

void CGifFont::AddFrames(CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
	switch(m_Motion)
	{
	case Nomotion:
		DoNomotion(ge, chars, hFont);
		break;
	case DisappearingMotion:
		DoDisappearingMotion(ge, chars, hFont);
		break;
	case ShakeMotion:
		DoShakeMotion(ge, chars, hFont);
		break;
	case SnowMotion:
		DoSnowMotion(ge, chars, hFont);
		break;
	}
}
void CGifFont::DrawAllChars(CDC& dc, LPBYTE lpData, vector<string>& chars, int x, int y, int width, int height)
{
	RECT rc;
	for (int i=0; i<chars.size(); i++)
	{
		rc = DrawOneChar(dc, lpData, chars[i], x, y, width, height);
		x = rc.right;
	}
}
void RectNoTransform(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{}
void PieSliceMap(double& x, double& y)
{
	double alpha = (1+x)*M_PI/6;
	x = y * cos(alpha);
	y = y * sin(alpha);
	//PieToXY(x,y,(1+x)* M_PI /6,y);
	x = 1-x;
}
void RectToPieSlice(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{
	RectConvert(lpData,cx,cy, PieSliceMap, trans);
}

const RectTransformMethod rectTransformMethods[6] = {RectNoTransform, RectToEllipse, RectToTriangle, RectToDiamond, RectToSShape, RectToPieSlice};
RECT CGifFont::DrawOneChar(CDC& dc, LPBYTE lpData, string& text, int x, int y, int width, int height)
{
	CSize size;
	dc.GetTextExtent(text.c_str(), text.length(), &size);
	int exsize = 0, esize = 0;
	if (m_HasShadow)
	{
		float h,s,v,h1,s1,v1;
		GetHSBbyRGB(m_ShadowColor, h,s,v);
		GetHSBbyRGB(m_Transparent, h1,s1,v1);
		exsize = m_ShadowDis+2;
		DrawTextWithOuter(dc, text, size, x+m_ShadowDis, y+m_ShadowDis, m_ShadowColor, GetRGBbyHSB(h,s,(v+2*v1)/3));
	}
	if (m_HasEdge)
	{
		if (exsize==0)
		{
			exsize = 2;
		}
		esize = 2;
		DrawTextWithOuter(dc, text, size, x, y, m_FontColor, m_EdgeColor);
	}
	RECT rc;
	rc.left = x;
	rc.top = y;
	rc.right = x + size.cx + exsize;
	rc.bottom = y + size.cy + exsize;
	rectTransformMethods[m_Shape](lpData, width, height, rc, m_Transparent);
	rc.right = x+size.cx+esize;
	rc.bottom = y+size.cy+esize;
	return rc;
}



void CGifFont::DoNomotion(CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
	LPBYTE lpData;
	RECT rc;
	HBITMAP hBm = GetOrignalBitmap(chars, hFont, lpData, rc);
	ge.AddFrame(hBm);
	DeleteObject(hBm);
}
void CGifFont::DoDisappearingMotion(CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
	LPBYTE lpData = NULL, lpData0;
	RECT rc;
	HBITMAP hBm = GetOrignalBitmap(chars, hFont, lpData, rc);
	int w = rc.right-rc.left, h = rc.bottom-rc.top;
	int fc = GetFramesCount(), fc2 = fc/2;
	if (fc2<2)
	{
		fc2 = 2;
	}
	HBITMAP* bms = new HBITMAP[fc2];
	CBrush brush;
	brush.CreateSolidBrush(GetTransparent());
	lpData0 = lpData;
	DIB32COLOR clr, trans = DIB32RGB(GetRValue(m_Transparent), GetGValue(m_Transparent), GetBValue(m_Transparent));
	CDCHandle dcScreen = GetDC(NULL);
	for (int i=0; i<fc2; i++)
	{
		CDC dc;dc.CreateCompatibleDC(dcScreen);
		LPBYTE lpData1 = NULL;
		bms[i] = CreateDIB(dc, w, h, lpData1);
		HBITMAP hBmp = dc.SelectBitmap(bms[i]);
		dc.FillRect(&rc, brush);
		for (int x=0; x<w; x++)
		{
			for (int y=0; y<h; y++)
			{
				if ((clr = DIBPixel(lpData0, x, y, w, h)) != trans && (rand()%fc))
				{
					int xx = x-i-1 + (rand()%(2*i+3)), yy=y-i-1+(rand()%(2*i+3));
					if (0<=xx&&xx<w&&0<=yy&&yy<h)
					{
						DIBPixel(lpData1, xx, yy, w, h) = clr;
					}
				}
			}
		}
		lpData0 = lpData1;
		dc.SelectBitmap(hBmp);
	}
	ge.AddFrame(hBm);
	fc2--;
	for (int i=0; i<fc2; i++)
	{
		ge.AddFrame(bms[i]);
	}
	for (int i=fc2; i>=0; i--)
	{
		ge.AddFrame(bms[i]);
		DeleteObject(bms[i]);
	}
	ge.AddFrame(hBm);
	DeleteObject(hBm);
	delete bms;

	::ReleaseDC(NULL,dcScreen.m_hDC);
}
void CGifFont::DoShakeMotion( CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
	CBrush brush;
	brush.CreateSolidBrush(m_Transparent);
	CDCHandle dcScreen = GetDC(NULL);
	CDC dc;
	dc.CreateCompatibleDC(dcScreen);
	dc.SetBkMode(TRANSPARENT);
	dc.SelectFont(hFont);
	int w,h;
	GetOrignalSize(dc, chars, w, h);
	const int d = 4;
	w+=d; h+=d;
	RECT r,rc;
	r.left = 0;
	r.top = 0;
	r.right = w;
	r.bottom = h;
	LPBYTE lpData = NULL;
	int fc = GetFramesCount();
	if (fc<2)
	{
		fc = 2;
	}
	for (int i=fc; i>0; i--)
	{
		HBITMAP 
			hBm = CreateDIB(dcScreen, w, h, lpData),
			hBmp = dc.SelectBitmap(hBm);
		dc.FillRect(&r, brush);
		int x=0,y=0;
		for (int i=0; i<chars.size(); i++)
		{
			rc = DrawOneChar(dc, lpData, chars[i], x+(rand()%d), y+(rand()%d), w, h);
			x+=rc.right-rc.left;
		}

		dc.SelectBitmap(hBmp);
		ge.AddFrame(hBm);
		DeleteObject(hBm);
	}
	::ReleaseDC(NULL,dcScreen.m_hDC);
}


void CGifFont::DoSnowMotion(CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
	DIB32COLOR clr, trans = DIB32RGB(GetRValue(m_Transparent), GetGValue(m_Transparent), GetBValue(m_Transparent));
	LPBYTE lpData = NULL;
	RECT rc;
	HBITMAP hBm = GetOrignalBitmap(chars, hFont, lpData, rc);
	int w = rc.right-rc.left, h = rc.bottom-rc.top;
	int buffersize = w*h*4;
	int fc = GetFramesCount();
	if (fc<2)
	{
		fc = 2;
	}

	CDCHandle dcScreen = GetDC(NULL);
	for (int i=0; i<fc; i++)
	{
		CDC dc;dc.CreateCompatibleDC(dcScreen);
		LPBYTE lpData1 = NULL;
		HBITMAP hBm1 = CreateDIB(dc, w, h, lpData1);
		HBITMAP hBmp = dc.SelectBitmap(hBm1);
		memcpy(lpData1,lpData,buffersize);
		for (int x=0; x<w; x++)
		{
			for (int y=0; y<h; y++)
			{
				if (DIBPixel(lpData1, x, y, w, h) == trans)
				{
					int xx = x-2 + (rand()%5), yy=y+(rand()%3);
					if (xx>=w)
					{
						xx -=w;
					}
					if (xx<0)
					{
						xx +=w;
					}
					if (yy>=h)
					{
						yy-=h;
					}
					DIBPixel(lpData1, xx, yy, w, h) = trans;
				}
			}
		}
		dc.SelectBitmap(hBmp);
		ge.AddFrame(hBm1);
		DeleteObject(hBm1);
	}
	DeleteObject(hBm);

	::ReleaseDC(NULL,dcScreen.m_hDC);
}
