#include "define.h"
#include "common.h"
#include "xy.h"

#define DIB32COLOR unsigned int
#define GetPos(x, y, width, height)  4*(((height)-(y)-1)*(width)+(x))
#define DIBPixel(p, x, y, width, height) ( *( (DIB32COLOR*)( (LPBYTE)p+GetPos(x,y,width,height) ) ) )
#define GetB(rgb)      ((BYTE)(rgb))
#define GetG(rgb)      ((BYTE)(((WORD)(rgb)) >> 8))
#define GetR(rgb)      ((BYTE)((rgb)>>16))
#define DIB32RGB(r,g,b) ((((r) & 0xff)<<16) | (((g) & 0xff)<<8) | ((b) & 0xff) )
#define RGB2DIB(rgb) ((((BYTE)(rgb))<<16) | (rgb & 0xff00) | ((BYTE)((rgb)>>16)))

DIB32COLOR GetAvg(int r, int g, int b, int n);

HBITMAP CreateDIB(HDC hdc,int cx,int cy, LPBYTE &lpData);

void FillDib32Color(LPBYTE lpData, int cx, int cy, DIB32COLOR clr);
void Transform(LPBYTE lpDataSrc, LPBYTE lpDataDst, int cx, int cy, const int matrix[3][3]);
void Transform(LPBYTE lpDataSrc, LPBYTE lpDataDst, int cx, int cy, RECT& rc, const int matrix[3][3]);
void AntiAliasing(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR bgColor);


typedef void (*RectTransformMethod)(
	LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans
	);

void RectToEllipse(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans);
void RectToTriangle(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans);
void RectToDiamond(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans);
void RectToSShape(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans);

void RectConvert(LPBYTE lpData, int cx, int cy, RECT& rc, MapXY mapping, DIB32COLOR trans);