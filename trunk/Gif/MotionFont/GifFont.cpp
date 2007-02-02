#include "GifFont.h"
#include "drawing.h"


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
	//TODO:
	return true;
}

HBITMAP CGifFont::GetOrignalBitmap(vector<string>& chars, HFONT hFont, LPBYTE& lpData, RECT& r)
{
	CDCHandle dcScreen = GetDC(NULL);
	CDC dc;
	dc.CreateCompatibleDC(dcScreen);
	dc.SetBkMode(TRANSPARENT);
	dc.SelectFont(hFont);
	int w = 0, h = 0;
	CSize size;
	for (int i=0; i<chars.size(); i++)
	{
		dc.GetTextExtent(chars[i].c_str(), chars[i].length(), &size);
		w += size.cx;
		h += size.cy;
	}
	if (m_HasShadow)
	{
		h += m_ShadowDis;
		if (m_HasEdge)
		{
			w += chars.size()*2+m_ShadowDis;
		}
		else
		{
			w += m_ShadowDis;
		}
	}
	else if (m_HasEdge)
	{
		w += chars.size()*2;
		h += 2;
	}
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
		DoDisappearingMotion(ge, chars, hFont);
		break;
	}
}

void CGifFont::DoNomotion(CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
}
void CGifFont::DoDisappearingMotion(CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
}
void CGifFont::DoShakeMotion( CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
}

void RectNoTransform(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{}

const RectTransformMethod rectTransformMethods[5] = {RectNoTransform, RectToEllipse, RectToTriangle, RectToDiamond, RectToSShape};

void CGifFont::DrawAllChars(CDC& dc, LPBYTE lpData, vector<string>& chars, int x, int y, int width, int height)
{
	RECT rc;
	for (int i=0; i<chars.size(); i++)
	{
		rc = DrawOneChar(dc, lpData, chars[i], x, y, width, height);
		x+=rc.right;
	}
}
RECT CGifFont::DrawOneChar(CDC& dc, LPBYTE lpData, string& text, int x, int y, int width, int height)
{
	CSize size;
	dc.GetTextExtent(text.c_str(), text.length(), &size);
	int exsize = 0, esize = 0;
	if (m_HasShadow)
	{
		exsize = m_ShadowDis+2;
		DrawTextWithOuter(dc, text, size, x+m_ShadowDis, y+m_ShadowDis, m_ShadowColor, m_ShadowColor);
	}
	if (m_HasEdge)
	{
		if (exsize==0)
		{
			exsize = 2;
		}
		esize = 2;
		DrawTextWithOuter(dc, text, size, x+m_ShadowDis, y+m_ShadowDis, m_FontColor, m_EdgeColor);
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
