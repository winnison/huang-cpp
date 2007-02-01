#include <atlbase.h>
#include <atlapp.h>
#include <atlgdi.h>
#include <atltypes.h>

#define EMPTYCOLOR 0xffffffff
#define NETSIZE 256
#define SAVEDEL(p) if(p){delete p;p=0;}

HBITMAP StretchBitmap(HBITMAP hbmpSrc,int cxDst,int cyDst);
