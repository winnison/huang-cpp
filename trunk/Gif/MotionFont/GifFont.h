#include <string>
#include <vector>
using namespace std;
#include "GifEncoder.h"

#include "bean.h"
#include "dib.h"
#include "RectMappingConverter.h"
#define RANDSEED			123456789
#define GIF_FONT_VERSION	0

class CGifFont
{
//Main
	BEAN(int, Version);
	BEAN(COLORREF, FontColor);
	BEAN(COLORREF, Transparent);
	BEAN(int, Quality);

//Individuate
	//Edge
	BEAN(BOOL, HasEdge);
	BEAN(COLORREF, EdgeColor);
	//Shadow
	BEAN(BOOL, HasShadow);
	BEAN(COLORREF, ShadowColor);
	BEAN(UINT, ShadowDis);

//Sizing
public:
	enum SizingType{NoSizing = 0, NormalSizing = 1, RandomSizing = 2, IncSizing = 3, DecSizing = 4, MiddleUpSizing = 5, MiddleDownSizing = 6, AlternateSizing = 7};
#define SIZINGCOUNT 8
	enum AlignType{RandomAlign = -1, LeftAlign = 0, CenterAlign = 1, RightAlign = 2};
	enum VAlignType{RandomVAlign = -1, TopVAlign = 0, CenterVAlign = 1, BottomVAlign = 2};
	BEAN(SizingType, Sizing);
#define MINSIZINGPROPORTION 0.01
    BEAN(double, SizingProportion);
	BEAN(AlignType, SizingAlign);
	BEAN(VAlignType, SizingVAlign);

//Shape
public:
	enum ShapeType{NormalShape = 0, EllipseShape = 1, TriangleShape = 2, DiamondShape = 3, S_Shape = 4, PieSliceShape = 5, MirrorShape = 6, ReflectionShape = 7};
#define SHAPECOUNT 8
	BEAN(ShapeType, Shape);

//Motion
public:
	enum MotionType{Nomotion = 0, DisappearingMotion = 1, ShakeMotion = 2, SnowMotion = 3, BluringMotion = 4, SharpenMotion = 5, SizingMotion = 6, HTurnOverMotion = 7, VTurnOverMotion = 8, RollingMotion = 9, WobblyMotion = 10, JumperMotion = 11, CircinateMotion = 12};
#define MOTIONCOUNT 13
	BEAN(MotionType, Motion);

	BEAN(int, FramesCount);
	BEAN(int, Interval);

	
public:
	CGifFont()
	: 
	m_Version(GIF_FONT_VERSION),
	m_FontColor(0),
	m_Transparent(0xffffff), 

	m_HasEdge(FALSE), 
	m_EdgeColor(0xffffff), 

	m_HasShadow(FALSE), 
	m_ShadowColor(0xb0b0b0),
	m_ShadowDis(4),

	m_Sizing(NormalSizing),
	m_SizingProportion(1.0),
	m_SizingAlign(CenterAlign),
	m_SizingVAlign(CenterVAlign),

	m_Shape(NormalShape),

	m_Motion(Nomotion),

	m_FramesCount(8),
	m_Interval(200),
	m_Quality(1)
	{}
	bool Generate(string& giffile, string& text, HFONT hFont);
	string GetParamsString();
	bool SetParamsString(string& formatString);
	//版本升高了以后需要判断size,shape和motion
	virtual bool IsValid();
protected:
	void Check();
	void GetOrignalSize(CDC& dc, vector<string>& chars, int& w, int& h);
	HBITMAP GetOrignalBitmap(vector<string>& chars, HFONT hFont, LPBYTE& lpData, RECT& rc, RECT* rs = NULL);
	virtual void AddFrames(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DrawAllChars(CDC& dc, LPBYTE lpData, vector<string>& chars, int x, int y, int width, int height);
	void DrawAllChars(CDC& dc, LPBYTE lpData, vector<string>& chars, int x, int y, int width, int height, RECT* rs);
	virtual void SizingConvert(LPBYTE lpData, int cx, int cy, RECT& rc, double proportion, AlignType at, VAlignType vt, DIB32COLOR trans);
	virtual void Sizing(LPBYTE lpData, vector<string>& chars, int charIndex, int cx, int cy, RECT& rc, DIB32COLOR trans);
	RECT DrawOneChar(CDC& dc, LPBYTE lpData, vector<string>& chars, int charIndex, int x, int y, int width, int height);
	void DoNomotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoDisappearingMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoShakeMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoSnowMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoBluringMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoSharpenMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoSizingMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoRectMappingConvertMotion(CRectMappingConverter* prmc, CGifEncoder& ge, vector<string>& chars, HFONT hFont, bool bAntiAliasing = false);
};

