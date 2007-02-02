#include <string>
#include <vector>
using namespace std;

#include "AnimatedGifEncoder.h"

#include "bean.h"
#include "dib.h"



class CGifFont
{
//Main
	BEAN(COLORREF, FontColor)
	BEAN(COLORREF, Transparent)
	BEAN(int, Quality)

//Individuate
	//Edge
	BEAN(BOOL, HasEdge)
	BEAN(COLORREF, EdgeColor)
	//Shadow
	BEAN(UINT, HasShadow)
	BEAN(COLORREF, ShadowColor)
	BEAN(UINT, ShadowDis)

//Shape
public:
enum ShapeType{NormalShape = 0, EllipseShape = 1, TriangleShape = 2, DiamondShape = 3, S_Shape = 4};
	BEAN(ShapeType, Shape)

//Motion
public:
enum MotionType{Nomotion = 0, DisappearingMotion = 1, ShakeMotion = 2};
	BEAN(MotionType, Motion)
	BEAN(int, FramesCount)
	BEAN(int, Interval)

	
public:
	CGifFont()
	: 
	m_FontColor(0),
	m_Transparent(0xffffff), 
	m_HasEdge(FALSE), 
	m_EdgeColor(0xffffff), 
	m_HasShadow(FALSE), 
	m_ShadowColor(0xdddddd),
	m_ShadowDis(4),
	m_Shape(NormalShape),
	m_Motion(Nomotion),
	m_FramesCount(10),
	m_Interval(200),
	m_Quality(1)
	{}
	bool Generate(string& giffile, string& text, HFONT hFont);
	
private:
	HBITMAP GetOrignalBitmap(vector<string>& chars, HFONT hFont, LPBYTE& lpData, RECT& rc);
protected:
	virtual bool IsValid();
	virtual void AddFrames(CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoNomotion(CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoDisappearingMotion(CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DoShakeMotion(CAnimatedGifEncoder& ge, vector<string>& chars, HFONT hFont);
	void DrawAllChars(CDC& dc, LPBYTE lpData, vector<string>& chars, int x, int y, int width, int height);
	RECT DrawOneChar(CDC& dc, LPBYTE lpData, string& text, int x, int y, int width, int height);
};

