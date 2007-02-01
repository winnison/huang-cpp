#include "bean.h"
#include "dib.h"
#include <string>
using namespace std;

class CGifFont
{
//Main
	BEAN(COLORREF, FontColor)
	BEAN(COLORREF, Transparent)
	BEAN(int, Quality)
	BEAN(int, FramesCount)
	BEAN(int, Interval)

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
enum MotionType{Nomotion = 0, Disappearing = 1, Shake = 2};
	BEAN(MotionType, Motion)


private:
	UINT MotionExtraSize();
	UINT EdgeExtraSize();
	UINT ShadowExtraSize();

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
	virtual bool Generate(string giffile, string text, HFONT hFont);
};

