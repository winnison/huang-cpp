#include "RectMappingConverter.h"


void CRectMappingConverter::RectConvert(LPBYTE lpDataSrc, LPBYTE lpDataDst, int cx, int cy, RECT& rc, DIB32COLOR trans)
{
	int dx = rc.right-rc.left, dy = rc.bottom-rc.top;
	int* buffer = new int[dx*dy*4], *p;
	memset(buffer, 0, dx*dy*16);
	double w = (double)(dx-1), h = (double)(dy-1);
	for (int i=dx-1; i>=0; i--)
	{
		for(int j=dy-1; j>=0; j--)
		{
			DIB32COLOR clr = DIBPixel(lpDataSrc, rc.left+i,rc.top+j,cx,cy);
			double x = (double)i/w, y = (double)j/h;
			Map(x, y);
			if (x>=0&&x<=1&&y>=0&&y<=1)
			{
				int ix = INTROUND(x*w), iy = INTROUND(y*h);
				p = buffer+(ix+iy*dx)*4;
				p[0]++;
				p[1]+=GetR(clr);
				p[2]+=GetG(clr);
				p[3]+=GetB(clr);
			}
		}
	}
	for (int i=dx-1; i>=0; i--)
	{
		for(int j=dy-1; j>=0; j--)
		{
			p = buffer+(i+j*dx)*4;
			if (*p==0)
			{
				DIBPixel(lpDataDst,rc.left+i,rc.top+j,cx,cy) = trans;
			}
			else
			{
				DIBPixel(lpDataDst,rc.left+i,rc.top+j,cx,cy) = GetAvg(p[1],p[2],p[3],p[0]);
			}
		}
	}
}


void CHTurnOverRectMappingConverter::Map(double& x, double& y)
{
	double p = m_Pos;
	if (p>0.5)
	{
		p = 1-p;
	}
	p = (1-p*4);
	if(p>=0)
		x = 0.5+(x-0.5)*sqrt(p);
	else
		x = 0.5-(x-0.5)*sqrt(-p);
}

void CVTurnOverRectMappingConverter::Map(double& x, double& y)
{
	double p = m_Pos;
	if (p>0.5)
	{
		p = 1-p;
	}
	p = (1-p*4);
	if(p>=0)
		y = 0.5+(y-0.5)*sqrt(p);
	else
		y = 0.5-(y-0.5)*sqrt(-p);
}

void CRollingRectMappingConverter::Map(double& x, double& y)
{
	double r, a;
	x-=0.5;
	y-=0.5;
	XY2Pie(x, y, a, r);
	Pie2XY((M_PI*2)*m_Pos+a, r, x, y);
	x+=0.5;
	y+=0.5;
}
void CWobblyRectMappingConverter::Map(double& x, double& y)
{
	double r, a, p = m_Pos;
	if (p>0.5)
	{
		p = 1-p;
	}
	x-=0.5;
	y-=0.5;
	XY2Pie(x, y, a, r);
	Pie2XY((M_PI*(p-0.25))+a, r, x, y);
	x+=0.5;
	y+=0.5;
}