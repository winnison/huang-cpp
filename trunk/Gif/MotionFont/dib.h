#include <math.h>
#include <atlbase.h>
#include <atlapp.h>
#include <atlgdi.h>
#include <atltypes.h>

#define DIB32COLOR unsigned int
#define GetPos(x, y, width, height)  4*(((height)-(y)-1)*(width)+(x))
#define DIBPixel(p, x, y, width, height) ( *( (DIB32COLOR*)( (LPBYTE)p+GetPos(x,y,width,height) ) ) )
#define GetB(rgb)      ((BYTE)(rgb))
#define GetG(rgb)      ((BYTE)(((WORD)(rgb)) >> 8))
#define GetR(rgb)      ((BYTE)((rgb)>>16))
#define DIB32RGB(r,g,b) ((((r) & 0xff)<<16) | (((g) & 0xff)<<8) | ((b) & 0xff) )


DIB32COLOR GetAvg(int r, int g, int b, int n);

HBITMAP CreateDIB(HDC hdc,int cx,int cy, LPBYTE &lpData);
void Transform(LPBYTE lpDataSrc, LPBYTE lpDataDst, int cx, int cy, float matrix[3][3]);

void RectToEllipse(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans);
void RectToTriangle(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans);
void RectToDiamond(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans);
void RectToSShape(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans);