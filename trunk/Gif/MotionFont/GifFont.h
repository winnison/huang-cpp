#include <string>
#include <vector>
using namespace std;
#include "GifEncoder.h"

#include "bean.h"
#include "dib.h"

#define RANDSEED 123456789


class CGifFont
{
//Main
	BEAN(COLORREF, FontColor);
	BEAN(COLORREF, Transparent);
	BEAN(int, Quality);

//Individuate
	//Edge
	BEAN(BOOL, HasEdge);
	BEAN(COLORREF, EdgeColor);
	//Shadow
	BEAN(UINT, HasShadow);
	BEAN(COLORREF, ShadowColor);
	BEAN(UINT, ShadowDis);

//Sizing
public:
	enum SizingType{NormalSizing = 0, RandomSizing = 1, IncSizing = 2, DecSizing = 3, AlternateSizing = 4};
#define SIZINGCOUNT 5
	enum AlignType{RandomAlign = -1, LeftAlign = 0, CenterAlign = 1, RightAlign = 2};
	enum VAlignType{RandomVAlign = -1, TopVAlign = 0, CenterVAlign = 1, BottomVAlign = 2};
	BEAN(SizingType, Sizing);
#define MINSIZINGPROPORTION 0.1
    BEAN(double, SizingProportion);
	BEAN(AlignType, SizingAlign);
	BEAN(VAlignType, SizingVAlign);

//Shape
public:
	enum ShapeType{NormalShape = 0, EllipseShape = 1, TriangleShape = 2, DiamondShape = 3, S_Shape = 4, PieSliceShape = 5, AnnulusShape = 6};
#define SHAPECOUNT 7
	BEAN(ShapeType, Shape);

//Motion
public:
	enum MotionType{Nomotion = 0, DisappearingMotion = 1, ShakeMotion = 2, SnowMotion = 3};
#define MOTIONCOUNT 4
	BEAN(MotionType, Motion);

	BEAN(int, FramesCount);
	BEAN(int, Interval);

	
public:
	CGifFont()
	: 
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
	
protected:
	void GetOrignalSize(CDC& dc, vector<string>& chars, int& w, int& h);
	HBITMAP GetOrignalBitmap(vector<string>& chars, HFONT hFont, LPBYTE& lpData, RECT& rc);
	//版本升高了以后需要判断shape和motion
	virtual bool IsValid();
	virtual void AddFrames(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DrawAllChars(CDC& dc, LPBYTE lpData, vector<string>& chars, int x, int y, int width, int height);
	virtual void SizingConvert(LPBYTE lpData, int cx, int cy, RECT& rc, double proportion, DIB32COLOR trans);
	virtual void Sizing(LPBYTE lpData, vector<string>& chars, int charIndex, int cx, int cy, RECT& rc, DIB32COLOR trans);
	RECT DrawOneChar(CDC& dc, LPBYTE lpData, vector<string>& chars, int charIndex, int x, int y, int width, int height);
	void DoNomotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoDisappearingMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoShakeMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoSnowMotion(CGifEncoder& ge, vector<string>& chars, HFONT hFont);
};

