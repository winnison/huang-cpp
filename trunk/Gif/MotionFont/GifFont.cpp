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
	/*
	0	个性化字体版本号			％d		
	-	透明色					无					客户端背景不同有	
	1	画质						％d		
	2	帧数						％d		
	3	帧间隔时间				％d					单位：ms	
	4	边缘颜色					％d										负值表示没有边缘
	5	阴影颜色					％d										负值表示没有阴影
	6	阴影距离					％d		
	7	变换大小规则				％d		
	8	变换大小比例				％d					单位：1％	
	9	变换大小单字对齐			％d %d									负值表示随机
	10	字体形状					％d		
	11	字体动画					％d		
	*/

string CGifFont::GetParamsString()
{
	char chs[0x100];
	string formatString = _T("");

#define ADD(i)\
	formatString += itoa((int)(i), chs, 10);\
	formatString.push_back(' ');

	ADD(m_Version);
	ADD(m_Quality);
	ADD(m_FramesCount);
	ADD(m_Interval);
	ADD(m_HasEdge?m_EdgeColor:-1);
	ADD(m_HasShadow?m_ShadowColor:-1);
	ADD(m_ShadowDis);
	ADD(m_Sizing);
	ADD(0.5+m_SizingProportion*100);
	ADD(m_SizingAlign);
	ADD(m_SizingVAlign);
	ADD(m_Shape);
	ADD(m_Motion);

#undef ADD
	return formatString;
}
bool CGifFont::SetParamsString(string& formatString)
{
	int index = 0, index1, t;
#define GETT(i, type)\
	index1 = formatString.find_first_of(' ', index);\
	if (index1<0)\
		return false;\
	(i) = (type)atoi(formatString.substr(index, index1-index).c_str());\
	index = index1+1;
#define GET(i) GETT(i, int)

	GET(m_Version);
	GET(m_Quality);
	GET(m_FramesCount);
	GET(m_Interval);
	GET(m_EdgeColor);
	m_HasEdge = m_EdgeColor<0;
	GET(m_ShadowColor);
	m_HasShadow = m_ShadowColor<0;
	GET(m_ShadowDis);
	GETT(m_Sizing, SizingType);
	GET(t);
	m_SizingProportion = (double)t / 100;
	GETT(m_SizingAlign, AlignType);
	GETT(m_SizingVAlign, VAlignType);
	GETT(m_Shape, ShapeType);
	GETT(m_Motion, MotionType);

#undef GET
#undef GETT
	return true;
}

bool CGifFont::Generate(string& giffile, string& text, HFONT hFont)
{
	if (!IsValid())
	{
		return false;
	}
	CGifEncoder age;
	age.Start(giffile);
	age.SetQuality(m_Quality);
	age.SetTransparent(m_Transparent);
	age.SetRepeat(0);
	age.SetDelay(m_Interval);
	vector<string> chars;
	GetChars(chars, text);
	//迫使每次随机得到相同.
	srand(RANDSEED);
	AddFrames(age, chars, hFont);

	age.Finish();


	return true;
}
void CGifFont::Check()
{
	m_Transparent &= 0xffffff;
	CHECKRANGE(m_SizingProportion, 0.01, 1);
	CHECKRANGE(m_Quality, 1, 20);
	CHECKRANGE(m_Interval, 10, 10000);
}
bool CGifFont::IsValid()
{
	Check();
	return 
		m_Sizing>=0 && m_Sizing<SIZINGCOUNT && 
		m_SizingAlign>=-1 && m_SizingAlign<3 &&
		m_SizingVAlign>=-1 && m_SizingVAlign<3 &&
		m_Shape>=0 && m_Shape<SHAPECOUNT && 
		m_Motion>=0 && m_Motion<MOTIONCOUNT;
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
HBITMAP CGifFont::GetOrignalBitmap(vector<string>& chars, HFONT hFont, LPBYTE& lpData, RECT& r, RECT* rs)
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


	if (rs == NULL)
	{
		DrawAllChars(dc,lpData,chars,0,0,w,h);
	}
	else
	{
		DrawAllChars(dc,lpData,chars,0,0,w,h,rs);
	}
	dc.SelectBitmap(hBmp);
	::ReleaseDC(NULL,dcScreen.m_hDC);
	return hBm;
}

void CGifFont::AddFrames(CGifEncoder& ge, vector<string>& chars, HFONT hFont)
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
	case BluringMotion:
		DoBluringMotion(ge, chars, hFont);
		break;
	case SharpenMotion:
		DoSharpenMotion(ge, chars, hFont);
		break;
	case SizingMotion:
		DoSizingMotion(ge, chars, hFont);
		break;
	}
}
void CGifFont::DrawAllChars(CDC& dc, LPBYTE lpData, vector<string>& chars, int x, int y, int width, int height)
{
	RECT* rs = new RECT[chars.size()];
	DrawAllChars(dc, lpData, chars, x, y, width, height, rs);
	delete rs;
}
void CGifFont::DrawAllChars(CDC& dc, LPBYTE lpData, vector<string>& chars, int x, int y, int width, int height, RECT* rs)
{
	for (int i=0; i<chars.size(); i++)
	{
		rs[i] = DrawOneChar(dc, lpData, chars, i, x, y, width, height);
		x = rs[i].right;
	}
}
void RectNoTransform(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{}
void PieSliceMap(double& x, double& y)
{
	y*=0.8;
	y = 1-y;
	double alpha = (1+x)*M_PI/3;
	x = y * cos(alpha)+0.5;
	y = y * sin(alpha);
	x = 1-x;
	y = 1.1-y;
}
void RectToPieSlice(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{
	RectConvert(lpData,cx,cy, rc, PieSliceMap, trans);
}
void MirrorMap(double& x, double& y)
{
	x = 1-x;
}
void RectToMirror(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{
	RectConvert(lpData,cx,cy, rc, MirrorMap, trans);
}
void ReflectionMap(double& x, double& y)
{
	y = 1-y;
}
void RectToReflection(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{
	RectConvert(lpData,cx,cy, rc, ReflectionMap, trans);
}

const RectTransformMethod rectTransformMethods[SHAPECOUNT] = {RectNoTransform, RectToEllipse, RectToTriangle, RectToDiamond, RectToSShape, RectToPieSlice, RectToMirror, RectToReflection};


void CGifFont::SizingConvert(LPBYTE lpData, int cx, int cy, RECT& rc, double proportion, AlignType at, VAlignType vt, DIB32COLOR trans)
{
	CHECKRANGE(proportion, MINSIZINGPROPORTION, 1);
	int dx = rc.right-rc.left, dy = rc.bottom-rc.top;
	int* buffer = new int[dx*dy*4], *p;
	memset(buffer, 0, dx*dy*16);
	double w = (double)(dx-1), h = (double)(dy-1), pt2 = (1-proportion)/2;
	for (int i=dx-1; i>=0; i--)
	{
		for(int j=dy-1; j>=0; j--)
		{
			DIB32COLOR clr = DIBPixel(lpData, rc.left+i,rc.top+j,cx,cy);
			double x = (double)i/w, y = (double)j/h;

			//mapping
			x*=proportion;
			y*=proportion;
			//if (at<0)
			//{
			//	x+=(rand()%3)*pt2;
			//}
			//else
			{
				x+=(int)at*pt2;
			}
			//if (vt<0)
			//{
			//	y+=(rand()%3)*pt2;
			//}
			//else
			{
				y+=(int)vt*pt2;
			}
			CHECKRANGE(x, 0, 1);
			CHECKRANGE(y, 0, 1);
			int ix = ROUND(x*w), iy = ROUND(y*h);
			p = buffer+(ix+iy*dx)*4;
			p[0]++;
			p[1]+=GetR(clr);
			p[2]+=GetG(clr);
			p[3]+=GetB(clr);
		}
	}
	for (int i=dx-1; i>=0; i--)
	{
		for(int j=dy-1; j>=0; j--)
		{
			p = buffer+(i+j*dx)*4;
			if (*p==0)
			{
				DIBPixel(lpData,rc.left+i,rc.top+j,cx,cy) = trans;
			}
			else
			{
				DIBPixel(lpData,rc.left+i,rc.top+j,cx,cy) = GetAvg(p[1],p[2],p[3],p[0]);
			}
		}
	}
	delete buffer;
}
void CGifFont::Sizing(LPBYTE lpData, vector<string>& chars, int charIndex, int cx, int cy, RECT& rc, DIB32COLOR trans)
{

	if (m_Sizing != NoSizing && m_SizingProportion < 1.0 && m_SizingProportion > 0.0)
	{
		AlignType at = m_SizingAlign;
		VAlignType vt = m_SizingVAlign;
		if (at<0)
			at = (AlignType)(rand()%3);
		if (vt<0)
			vt = (VAlignType)(rand()%3);
		double p = (double)(charIndex)/(double)(chars.size()-1);
#define P(p) (1-(1-m_SizingProportion)*(p))
		switch(m_Sizing)
		{
		case NormalSizing:
			SizingConvert(lpData, cx, cy, rc, m_SizingProportion, at, vt, trans);
			break;
		case RandomSizing:
			SizingConvert(lpData, cx, cy, rc, P((double)rand()/(double)RAND_MAX), at, vt, trans);
			break;
		case IncSizing:
			SizingConvert(lpData, cx, cy, rc, P(1-p), at, vt, trans);
			break;
		case DecSizing:
			SizingConvert(lpData, cx, cy, rc, P(p), at, vt, trans);
			break;
		case MiddleUpSizing:
			if (p<0.5)
			{
				p = 1-p;
			}
			SizingConvert(lpData, cx, cy, rc, P(p*2-1), at, vt, trans);
			break;
		case MiddleDownSizing:
			if (p<0.5)
			{
				p = 1-p;
			}
			SizingConvert(lpData, cx, cy, rc, P(2-p*2), at, vt, trans);
			break;
		case AlternateSizing:
			if (charIndex&1)
			{
				SizingConvert(lpData, cx, cy, rc, m_SizingProportion, at, vt, trans);
			}
			else
			{
				SizingConvert(lpData, cx, cy, rc, 1, at, vt, trans);
			}
		    break;
		}
	}
#undef P
}
RECT CGifFont::DrawOneChar(CDC& dc, LPBYTE lpData, vector<string>& chars, int charIndex, int x, int y, int width, int height)
{
	string text = chars[charIndex];
	CSize size;
	dc.GetTextExtent(text.c_str(), text.length(), &size);
	RECT rc;
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
	else
	{
		dc.SetTextColor(m_FontColor);
		rc.left = x;
		rc.top = y;
		rc.right = x+size.cx;
		rc.bottom = y+size.cy;
		dc.DrawText(text.c_str(), text.length(), &rc, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
	}
	rc.left = x;
	rc.top = y;
	rc.right = x + size.cx + exsize;
	rc.bottom = y + size.cy + exsize;
	rectTransformMethods[m_Shape](lpData, width, height, rc, m_Transparent);
	Sizing(lpData, chars, charIndex, width, height, rc, m_Transparent);
	rc.left = x;
	rc.top = y;
	rc.right = x + size.cx + esize;
	rc.bottom = y + size.cy + esize;
	return rc;
}



void CGifFont::DoNomotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
	LPBYTE lpData;
	RECT rc;
	HBITMAP hBm = GetOrignalBitmap(chars, hFont, lpData, rc);
	ge.AddFrame(hBm);
	DeleteObject(hBm);
}
void CGifFont::DoDisappearingMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont)
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
void CGifFont::DoShakeMotion( CGifEncoder& ge, vector<string>& chars, HFONT hFont)
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
			rc = DrawOneChar(dc, lpData, chars, i, x+(rand()%d), y+(rand()%d), w, h);
			x+=rc.right-rc.left;
		}

		dc.SelectBitmap(hBmp);
		ge.AddFrame(hBm);
		DeleteObject(hBm);
	}
	::ReleaseDC(NULL,dcScreen.m_hDC);
}


void CGifFont::DoSnowMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont)
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

const int BluringMatrix[3][3] = {{1,1,1}, {1,1,1}, {1,1,1}};
void CGifFont::DoBluringMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
	LPBYTE lpData = NULL, lpData0;
	RECT rc;
	HBITMAP hBm = GetOrignalBitmap(chars, hFont, lpData0, rc);
	int w = rc.right-rc.left, h = rc.bottom-rc.top;
	int fc = GetFramesCount(), fc2 = fc/2;
	if (fc2<2)
	{
		fc2 = 2;
	}
	HBITMAP* bms = new HBITMAP[fc2];
	CDCHandle dcScreen = GetDC(NULL);
	for (int i=0; i<fc2; i++)
	{
		bms[i] = CreateDIB(dcScreen, w, h, lpData);
		Transform(lpData0, lpData, w,h, rc, BluringMatrix);
		lpData0 = lpData;
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

void CGifFont::DoSharpenMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
	const int m[3][3] = {{1,2,1}, {2,-36,2}, {1,2,1}};
	LPBYTE lpData = NULL, lpData0;
	RECT rc;
	HBITMAP hBm = GetOrignalBitmap(chars, hFont, lpData0, rc);
	int w = rc.right-rc.left, h = rc.bottom-rc.top;
	int fc = GetFramesCount(), fc2 = fc/2;
	if (fc2<2)
	{
		fc2 = 2;
	}
	HBITMAP* bms = new HBITMAP[fc2];
	CDCHandle dcScreen = GetDC(NULL);
	for (int i=0; i<fc2; i++)
	{
		bms[i] = CreateDIB(dcScreen, w, h, lpData);
		Transform(lpData0, lpData, w,h, rc, m);
		lpData0 = lpData;
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

void CGifFont::DoSizingMotion( CGifEncoder& ge, vector<string>& chars, HFONT hFont)
{
	LPBYTE lpData = NULL;
	RECT rc, *rs = new RECT[chars.size()];
	HBITMAP hBm = GetOrignalBitmap(chars, hFont, lpData, rc, rs);
	int w = rc.right-rc.left, h = rc.bottom-rc.top;
	int fc = GetFramesCount(), fc2 = fc/2;
	if (fc2<2)
	{
		fc2 = 2;
	}
	fc = fc2*2;
	HBITMAP* bms = new HBITMAP[fc];
	LPBYTE * lpDatas = new LPBYTE[fc];

	CDCHandle dcScreen = GetDC(NULL);
	for (int i=0; i<fc; i++)
	{
		bms[i] = CreateDIB(dcScreen, w, h, lpDatas[i]);
		memcpy(lpDatas[i], lpData, 4*w*h);
	}
	DeleteObject(hBm);
	for (int index=chars.size()-1; index>=0; index--)
	{
		
		if (m_HasShadow)
		{
			rs[index].right += m_ShadowDis;
			rs[index].bottom += m_ShadowDis;
			if (!m_HasEdge)
			{
				rs[index].right += 2;
				rs[index].bottom += 2;
			}
		}
		AlignType at = m_SizingAlign;
		VAlignType vt = m_SizingVAlign;
		if (at<0)
			at = (AlignType)(rand()%3);
		if (vt<0)
			vt = (VAlignType)(rand()%3);
		for (int i=0; i<fc2; i++)
		{
			SizingConvert(lpDatas[i], w, h, rs[index], 1 - (double)((i)%fc2)/(double)fc2, at, vt, m_Transparent);
		}
		for (int i=fc2; i<fc; i++)
		{
			SizingConvert(lpDatas[i], w, h, rs[index], (double)((i)%fc2)/(double)fc2, at, vt, m_Transparent);
		}
	}

	for (int i=0; i<fc; i++)
	{
		ge.AddFrame(bms[i]);
		DeleteObject(bms[i]);
	}
	delete bms;
	delete rs;
	delete lpDatas;
	::ReleaseDC(NULL,dcScreen.m_hDC);
}



