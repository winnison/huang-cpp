#include "define.h"

void HSBtoRGB(float hue, float saturation, float brightness, int& r, int& g, int& b);
void RGBtoHSB(int r, int g, int b, float& hue, float& saturation, float& brightness);

COLORREF GetRGBbyHSB(float hue, float saturation, float brightness);

void GetHSBbyRGB(COLORREF rgb, float& hue, float& saturation, float& brightness);

void GrayAdjust(HBITMAP hBitmap);

HBITMAP StretchBitmap(HBITMAP hbmpSrc,int cxDst,int cyDst);
HBITMAP Transform( HBITMAP hBitmap , float matrix[3][3]);