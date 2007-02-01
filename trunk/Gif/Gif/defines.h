#include <atlbase.h>
#include <atlapp.h>
#include <atlgdi.h>
#include <atltypes.h>

#define EMPTYCOLOR 0xffffffff
#define NETSIZE 256
#define SAVEDEL(p) if(p){delete p;p=0;}
#define MAX(a, b)  (((a)>(b))?(a):(b))
#define CHECKRANGE(a, left, right) \
	if ((a)<(left))\
	{\
	(a) = (left);\
	}\
	else if((a)>(right))\
	{\
	(a) = (right);\
	}




void HSBtoRGB(float hue, float saturation, float brightness, int& r, int& g, int& b);
void RGBtoHSB(int r, int g, int b, float& hue, float& saturation, float& brightness);

COLORREF GetRGBbyHSB(float hue, float saturation, float brightness);

void GetHSBbyRGB(COLORREF rgb, float& hue, float& saturation, float& brightness);

void GrayAdjust(HBITMAP hBitmap);

HBITMAP StretchBitmap(HBITMAP hbmpSrc,int cxDst,int cyDst);
HBITMAP Transform( HBITMAP hBitmap , float matrix[3][3]);
