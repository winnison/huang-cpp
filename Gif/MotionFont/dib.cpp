#include "dib.h"
#include <vector>
#include <utility>

using namespace std;

inline DIB32COLOR GetAvg(int r, int g, int b, int n)
{
	int n2 = n/2;
	return DIB32RGB((r+n2)/n, (g+n2)/n, (b+n2)/n);
}
void FillDib32Color(LPBYTE lpData, int cx, int cy, DIB32COLOR clr)
{
	DIB32COLOR * pClr = (DIB32COLOR*)lpData;
	for (int i=cx*cy-1; i>=0; i--)
	{
		pClr[i] = clr;
	}
}

HBITMAP CreateDIB(HDC hdc,int cx,int cy, LPBYTE &lpData)
{
	BITMAPINFO bmpInfo = {
		sizeof(bmpInfo.bmiHeader),		//biSize
			cx,							//biWidth
			cy,							//biHeight
			1,							//biPlanes
			4*8				//biBitCount
	};

	return CreateDIBSection(hdc,&bmpInfo,DIB_RGB_COLORS,(void**)&lpData,NULL,0);
}


void Transform(LPBYTE lpDataSrc, LPBYTE lpDataDst, int cx, int cy, const int matrix[3][3])
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = cx;
	rc.bottom = cy;
	Transform(lpDataSrc, lpDataDst, cx, cy, rc, matrix);
}
void Transform(LPBYTE lpDataSrc, LPBYTE lpDataDst, int cx, int cy, RECT& rc, const int m[3][3])
{
	int base, base2;
	base = m[0][0]+m[0][1]+m[0][2]+m[1][0]+m[1][1]+m[1][2]+m[2][0]+m[2][1]+m[2][2];
	if (base == 0)
	{
		return;
	}
	int right1 =rc.right-1, bottom1 = rc.bottom-1;
	for (int x=rc.left; x<=right1; x++)
	{
		for (int y=rc.top; y<=bottom1; y++)
		{
			int r = 0, g = 0, b = 0, base = 0;
			DIB32COLOR rgb;
			BOOL istop = y == 0, isbottom = y == bottom1;
#define ADDRGB(x, y, f) \
	rgb = DIBPixel(lpDataSrc, x, y, cx, cy);\
	r += f*GetR(rgb);\
	g += f*GetG(rgb);\
	b += f*GetB(rgb);\
	base += f;

			if (x != 0)
			{
				if (!istop)
				{
					ADDRGB(x-1, y-1,m[0][0]);
				}
				ADDRGB(x-1,y, m[0][1]);
				if (!isbottom)
				{
					ADDRGB(x-1,y+1,m[0][2]);
				}
			}
			if (!istop)
			{
				ADDRGB(x,y-1,m[1][0]);
			}
			ADDRGB(x,y,m[1][1]);
			if (!isbottom)
			{
				ADDRGB(x,y+1,m[1][2])
			}
			if (x != right1)
			{
				if (!istop)
				{
					ADDRGB(x+1, y-1,m[2][0]);
				}
				ADDRGB(x+1,y, m[2][1]);
				if (!isbottom)
				{
					ADDRGB(x+1,y+1,m[2][2]);
				}
			}
#undef ADDRGB
			base2 = (base+1)/2;
			r = (r+base2)/base;
			g = (g+base2)/base;
			b = (b+base2)/base;

			CHECKRANGE(r, 0, 255);
			CHECKRANGE(g, 0, 255);
			CHECKRANGE(b, 0, 255);
			DIBPixel(lpDataDst, x, y, cx, cy) = DIB32RGB(r,g,b);
		}
	}
}
void AntiAliasing(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR bgColor)
{
	int right1 =rc.right-1, bottom1 = rc.bottom-1;
	DIB32COLOR rgb;
	vector<pair< pair<int, int>, DIB32COLOR> > vcList;
	for (int x=rc.left; x<=right1; x++)
	{
		for (int y=rc.top; y<=bottom1; y++)
		{
#define  ISBG(x, y) (DIBPixel(lpData, x, y, cx, cy) == bgColor)
			if (ISBG(x, y))
			{
				int r = 0, g = 0, b = 0, base = 0, n4 = -1, base2;
				if (x!=0 &&!ISBG(x-1,y))
				{
					n4++;
				}
				if (x!=right1 && !ISBG(x+1,y))
				{
					n4++;
				}
				if (y!=0 && !ISBG(x,y-1))
				{
					n4++;
				}
				if (y!=bottom1 && !ISBG(x,y+1))
				{
					n4++;
				}
				if (n4<=0)
				{
					continue;
				}
#undef ISBG

#define ADD(x,y,rgb,f)\
	r += f*GetR(rgb);\
	g += f*GetG(rgb);\
	b += f*GetB(rgb);\
	base ++;

#define ADDRGB(x, y) \
	rgb = DIBPixel(lpData, x, y, cx, cy);\
	ADD(x,y,rgb,1);
				if (x!=0)
				{
					ADDRGB(x-1,y);
				}
				if (x!=right1)
				{
					ADDRGB(x+1,y);
				}
				if (y!=0)
				{
					ADDRGB(x,y-1);
				}
				if (y!=bottom1)
				{
					ADDRGB(x,y+1);
				}
				ADD(x,y,bgColor,2);

#undef ADDRGB
#undef ADD

				base2 = (base+1)/2;
				r = (r+base2)/base;
				g = (g+base2)/base;
				b = (b+base2)/base;

				CHECKRANGE(r, 0, 255);
				CHECKRANGE(g, 0, 255);
				CHECKRANGE(b, 0, 255);
				vcList.push_back(make_pair(make_pair(x, y), DIB32RGB(r,g,b)));
			}
		}
	}
	for (int i=vcList.size()-1; i>=0; i--)
	{
		pair< pair<int, int>, DIB32COLOR>  *p = &vcList[i];
		DIBPixel(lpData, p->first.first, p->first.second, cx, cy) = p->second;
	}
}
void RectToEllipse(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{
	int dx = rc.right-rc.left, dy = rc.bottom-rc.top, dx1 = dx/2, dx2 = dx -dx1, dy1=dy/2, dy2=dy-dy1;
	int dx1_1 = dx1-1, dx2_1=dx2-1, dy1_1=dy1-1, dy2_1=dy2-1, da, da1, da2, db1, db2, xstart, xend, ystart, yend;
	double d, dd;
	DIB32COLOR clr;
	for (int y=0; y<dy2; y++)
	{
		d = (double)(y)/(double)(dy2_1);
		da = INTROUND(sqrt(1-d*d)*dx);
		da1 = da/2;
		da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx2_1);
			db2 = INTROUND(sqrt(1-dd*dd)*(dy2_1));
			xstart = (x)*dx2/da2;
			xend = (x+1)*dx2/da2;
			if (xend>dx2)
			{
				xend = dx2;
			}
			if (db2==0)
			{
				ystart = 0;
				yend = dy2;
			}
			else
			{
				ystart = (y)*dy2/db2;
				yend = (y+1)*dy2/db2;
				if (yend>dy2)
				{
					yend = dy2;
				}
			}
			for (int xx=xstart; xx<xend; xx++)
			{
				for(int yy=ystart; yy<yend; yy++)
				{
					clr = DIBPixel(lpData, rc.left+dx1+xx, rc.top+dy1+yy, cx, cy);
					if (clr != trans)
					{
						n++;
						r+=GetR(clr);
						g+=GetG(clr);
						b+=GetB(clr);
					}
				}
			}
			if (n)
			{
				DIBPixel(lpData, rc.left+dx1+x, rc.top+dy1+y, cx, cy) = GetAvg(r,g,b,n);
			}
			else
			{
				DIBPixel(lpData, rc.left+dx1+x, rc.top+dy1+y, cx, cy) = trans;
			}
		}
		for (int x=da2; x<dx2; x++)
		{
			DIBPixel(lpData, rc.left+dx1+x,rc.top+dy1+y, cx, cy) = trans;
		}

		for (int x=0; x<da1; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx1_1);
			db2 = INTROUND(sqrt(1-dd*dd)*(dy2_1));
			xstart = (x)*dx1/da1;
			xend = (x+1)*dx1/da1;
			if (xend>dx1)
			{
				xend = dx1;
			}
			if (db2==0)
			{
				ystart = 0;
				yend = dy2;
			}
			else
			{
				ystart = (y)*dy2/db2;
				yend = (y+1)*dy2/db2;
				if (yend>dy2)
				{
					yend = dy2;
				}
			}
			for (int xx=xstart; xx<xend; xx++)
			{
				for(int yy=ystart; yy<yend; yy++)
				{
					clr = DIBPixel(lpData, rc.left+dx1_1-xx, rc.top+dy1+yy, cx, cy);
					if (clr != trans)
					{
						n++;
						r+=GetR(clr);
						g+=GetG(clr);
						b+=GetB(clr);
					}
				}
			}
			if (n)
			{
				DIBPixel(lpData, rc.left+dx1_1-x, rc.top+dy1+y, cx, cy) = GetAvg(r,g,b,n);
			}
			else
			{
				DIBPixel(lpData, rc.left+dx1_1-x, rc.top+dy1+y, cx, cy) = trans;
			}
		}
		for (int x=da1; x<dx1; x++)
		{
			DIBPixel(lpData, rc.left+dx1_1-x,rc.top+dy1+y, cx, cy) = trans;
		}

	}
	for (int y=0; y<dy1; y++)
	{
		d = (double)(y)/(double)(dy1_1);
		da = INTROUND(sqrt(1-d*d)*dx);
		da1 = da/2;
		da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx2_1);
			db1 = INTROUND(sqrt(1-dd*dd)*(dy1_1));
			xstart = (x)*dx2/da2;
			xend = (x+1)*dx2/da2;
			if (xend>dx2)
			{
				xend = dx2;
			}
			if (db1==0)
			{
				ystart = 0;
				yend = dy1;
			}
			else
			{
				ystart = (y)*dy1/db1;
				yend = (y+1)*dy1/db1;
				if (yend>dy1)
				{
					yend = dy1;
				}
			}
			for (int xx=xstart; xx<xend; xx++)
			{
				for(int yy=ystart; yy<yend; yy++)
				{
					clr = DIBPixel(lpData, rc.left+dx1+xx, rc.top+dy1_1-yy, cx, cy);
					if (clr != trans)
					{
						n++;
						r+=GetR(clr);
						g+=GetG(clr);
						b+=GetB(clr);
					}
				}
			}
			if (n)
			{
				DIBPixel(lpData, rc.left+dx1+x, rc.top+dy1_1-y, cx, cy) = GetAvg(r,g,b,n);
			}
			else
			{
				DIBPixel(lpData, rc.left+dx1+x, rc.top+dy1_1-y, cx, cy) = trans;
			}
		}
		for (int x=da2; x<dx2; x++)
		{
			DIBPixel(lpData, rc.left+dx1+x,rc.top+dy1_1-y, cx, cy) = trans;
		}

		for (int x=0; x<da1; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx1_1);
			db1 = INTROUND(sqrt(1-dd*dd)*(dy1_1));
			xstart = (x)*dx1/da1;
			xend = (x+1)*dx1/da1;
			if (xend>dx1)
			{
				xend = dx1;
			}
			if (db1==0)
			{
				ystart = 0;
				yend = dy1;
			}
			else
			{
				ystart = (y)*dy1/db1;
				yend = (y+1)*dy1/db1;
				if (yend>dy1)
				{
					yend = dy1;
				}
			}
			for (int xx=xstart; xx<xend; xx++)
			{
				for(int yy=ystart; yy<yend; yy++)
				{
					clr = DIBPixel(lpData, rc.left+dx1_1-xx, rc.top+dy1_1-yy, cx, cy);
					if (clr != trans)
					{
						n++;
						r+=GetR(clr);
						g+=GetG(clr);
						b+=GetB(clr);
					}
				}
			}
			if (n)
			{
				DIBPixel(lpData, rc.left+dx1_1-x, rc.top+dy1_1-y, cx, cy) = GetAvg(r,g,b,n);
			}
			else
			{
				DIBPixel(lpData, rc.left+dx1_1-x, rc.top+dy1_1-y, cx, cy) = trans;
			}
		}
		for (int x=da1; x<dx1; x++)
		{
			DIBPixel(lpData, rc.left+dx1_1-x,rc.top+dy1_1-y, cx, cy) = trans;
		}

	}
}

void RectToTriangle(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{
	int dx = rc.right-rc.left, dy = rc.bottom-rc.top, dx1 = dx/2, dx2 = dx -dx1;
	int dx1_1 = dx1-1, dy_1 = dy-1;
	DIB32COLOR clr;
	for (int y=0; y<dy; y++)
	{
		int da = dx*y/dy_1, da1 = da/2, da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			for (int xx=x*dx2/da2, end = (x+1)*dx2/da2; xx<end; xx++)
			{
				clr = DIBPixel(lpData, rc.left+dx1+xx, rc.top+y, cx, cy);
				if (clr != trans)
				{
					n++;
					r+=GetR(clr);
					g+=GetG(clr);
					b+=GetB(clr);
				}
			}
			if (n)
			{
				DIBPixel(lpData, rc.left+dx1+x, rc.top+y, cx, cy) = GetAvg(r,g,b,n);
			}
			else
			{
				DIBPixel(lpData, rc.left+dx1+x, rc.top+y, cx, cy) = trans;
			}
		}
		for (int x=da2; x<dx2; x++)
		{
			DIBPixel(lpData, rc.left+dx1+x,rc.top+y, cx, cy) = trans;
		}

		for (int x=0; x<da1; x++)
		{
			int r=0,g=0,b=0,n=0;
			for (int xx=x*dx1/da1, end = (x+1)*dx1/da1; xx<end; xx++)
			{
				clr = DIBPixel(lpData, rc.left+dx1_1-xx, rc.top+y, cx, cy);
				if (clr != trans)
				{
					n++;
					r+=GetR(clr);
					g+=GetG(clr);
					b+=GetB(clr);
				}
			}
			if (n)
			{
				DIBPixel(lpData, rc.left+dx1_1-x, rc.top+y, cx, cy) = GetAvg(r,g,b,n);
			}
			else
			{
				DIBPixel(lpData, rc.left+dx1_1-x, rc.top+y, cx, cy) = trans;
			}
		}
		for (int x=da1; x<dx1; x++)
		{
			DIBPixel(lpData, rc.left+dx1_1-x,rc.top+y, cx, cy) = trans;
		}
	}
}



void RectToDiamond(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{
	int dx = rc.right-rc.left, dy = rc.bottom-rc.top, dx1 = dx/2, dx2 = dx -dx1, dy1=dy/2, dy2=dy-dy1;
	int dx1_1 = dx1-1, dx2_1=dx2-1, dy1_1=dy1-1, dy2_1=dy2-1, da, da1, da2, db1, db2, xstart, xend, ystart, yend;
	double d, dd;
	DIB32COLOR clr;
	for (int y=0; y<dy2; y++)
	{
		d = (double)(y)/(double)(dy2_1);
		da = INTROUND((1-d)*dx);
		da1 = da/2;
		da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx2_1);
			db2 = INTROUND((1-dd)*(dy2_1));
			xstart = (x)*dx2/da2;
			xend = (x+1)*dx2/da2;
			if (xend>dx2)
			{
				xend = dx2;
			}
			if (db2==0)
			{
				ystart = 0;
				yend = dy2;
			}
			else
			{
				ystart = (y)*dy2/db2;
				yend = (y+1)*dy2/db2;
				if (yend>dy2)
				{
					yend = dy2;
				}
			}
			for (int xx=xstart; xx<xend; xx++)
			{
				for(int yy=ystart; yy<yend; yy++)
				{
					clr = DIBPixel(lpData, rc.left+dx1+xx, rc.top+dy1+yy, cx, cy);
					if (clr != trans)
					{
						n++;
						r+=GetR(clr);
						g+=GetG(clr);
						b+=GetB(clr);
					}
				}
			}
			if (n)
			{
				DIBPixel(lpData, rc.left+dx1+x, rc.top+dy1+y, cx, cy) = GetAvg(r,g,b,n);
			}
			else
			{
				DIBPixel(lpData, rc.left+dx1+x, rc.top+dy1+y, cx, cy) = trans;
			}
		}
		for (int x=da2; x<dx2; x++)
		{
			DIBPixel(lpData, rc.left+dx1+x,rc.top+dy1+y, cx, cy) = trans;
		}

		for (int x=0; x<da1; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx1_1);
			db2 = INTROUND((1-dd)*(dy2_1));
			xstart = (x)*dx1/da1;
			xend = (x+1)*dx1/da1;
			if (xend>dx1)
			{
				xend = dx1;
			}
			if (db2==0)
			{
				ystart = 0;
				yend = dy2;
			}
			else
			{
				ystart = (y)*dy2/db2;
				yend = (y+1)*dy2/db2;
				if (yend>dy2)
				{
					yend = dy2;
				}
			}
			for (int xx=xstart; xx<xend; xx++)
			{
				for(int yy=ystart; yy<yend; yy++)
				{
					clr = DIBPixel(lpData, rc.left+dx1_1-xx, rc.top+dy1+yy, cx, cy);
					if (clr != trans)
					{
						n++;
						r+=GetR(clr);
						g+=GetG(clr);
						b+=GetB(clr);
					}
				}
			}
			if (n)
			{
				DIBPixel(lpData, rc.left+dx1_1-x, rc.top+dy1+y, cx, cy) = GetAvg(r,g,b,n);
			}
			else
			{
				DIBPixel(lpData, rc.left+dx1_1-x, rc.top+dy1+y, cx, cy) = trans;
			}
		}
		for (int x=da1; x<dx1; x++)
		{
			DIBPixel(lpData, rc.left+dx1_1-x,rc.top+dy1+y, cx, cy) = trans;
		}

	}
	for (int y=0; y<dy1; y++)
	{
		d = (double)(y)/(double)(dy1_1);
		da = INTROUND((1-d)*dx);
		da1 = da/2;
		da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx2_1);
			db1 = INTROUND((1-dd)*(dy1_1));
			xstart = (x)*dx2/da2;
			xend = (x+1)*dx2/da2;
			if (xend>dx2)
			{
				xend = dx2;
			}
			if (db1==0)
			{
				ystart = 0;
				yend = dy1;
			}
			else
			{
				ystart = (y)*dy1/db1;
				yend = (y+1)*dy1/db1;
				if (yend>dy1)
				{
					yend = dy1;
				}
			}
			for (int xx=xstart; xx<xend; xx++)
			{
				for(int yy=ystart; yy<yend; yy++)
				{
					clr = DIBPixel(lpData, rc.left+dx1+xx, rc.top+dy1_1-yy, cx, cy);
					if (clr != trans)
					{
						n++;
						r+=GetR(clr);
						g+=GetG(clr);
						b+=GetB(clr);
					}
				}
			}
			if (n)
			{
				DIBPixel(lpData, rc.left+dx1+x, rc.top+dy1_1-y, cx, cy) = GetAvg(r,g,b,n);
			}
			else
			{
				DIBPixel(lpData, rc.left+dx1+x, rc.top+dy1_1-y, cx, cy) = trans;
			}
		}
		for (int x=da2; x<dx2; x++)
		{
			DIBPixel(lpData, rc.left+dx1+x,rc.top+dy1_1-y, cx, cy) = trans;
		}

		for (int x=0; x<da1; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx1_1);
			db1 = INTROUND((1-dd)*(dy1_1));
			xstart = (x)*dx1/da1;
			xend = (x+1)*dx1/da1;
			if (xend>dx1)
			{
				xend = dx1;
			}
			if (db1==0)
			{
				ystart = 0;
				yend = dy1;
			}
			else
			{
				ystart = (y)*dy1/db1;
				yend = (y+1)*dy1/db1;
				if (yend>dy1)
				{
					yend = dy1;
				}
			}
			for (int xx=xstart; xx<xend; xx++)
			{
				for(int yy=ystart; yy<yend; yy++)
				{
					clr = DIBPixel(lpData, rc.left+dx1_1-xx, rc.top+dy1_1-yy, cx, cy);
					if (clr != trans)
					{
						n++;
						r+=GetR(clr);
						g+=GetG(clr);
						b+=GetB(clr);
					}
				}
			}
			if (n)
			{
				DIBPixel(lpData, rc.left+dx1_1-x, rc.top+dy1_1-y, cx, cy) = GetAvg(r,g,b,n);
			}
			else
			{
				DIBPixel(lpData, rc.left+dx1_1-x, rc.top+dy1_1-y, cx, cy) = trans;
			}
		}
		for (int x=da1; x<dx1; x++)
		{
			DIBPixel(lpData, rc.left+dx1_1-x,rc.top+dy1_1-y, cx, cy) = trans;
		}

	}

}

void RectToSShape(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{
	int dx = rc.right-rc.left, dy = rc.bottom-rc.top, dx1 = dx/4, dx2 = dx/8, dx3=dx1*3;
	int dy_1 = dy-1, start;
	DIB32COLOR* buffer = new DIB32COLOR[cx];
	for (int i=0; i<dy; i++)
	{
		start = 0;
		double d = (double)(i*6)/(double)dy;
		switch((int)d)
		{
		case 0:
		case 1:
			d = (2-d)/2;
			start = INTROUND(dx1 * d * d);
			break;
		case 2:
			d = d-2;
			start = INTROUND(dx2 * d * d);
			break;
		case 3:
			d = 4-d;
			start = dx2 + INTROUND((dx1-dx2) * (1-d*d));
			break;
		case 4:
		case 5:
			d = (d-4)/2;
			start = INTROUND(dx1 * (1-d*d));
			break;
		default:
			break;
		}
		start += rc.left;
		int y = i+rc.top;
		for (int ii=0; ii<dx; ii++)
		{
			buffer[ii] = DIBPixel(lpData, rc.left+ii, y, cx, cy);
			DIBPixel(lpData, rc.left+ii, y, cx, cy) = trans;
		}

		for (int ii=0, j=0; j<dx3; j++)
		{
			DIB32COLOR clr1 = buffer[ii++], clr2;
			if(j%3)
			{
				DIBPixel(
					lpData, start+j, y, cx, cy
					) = clr1;
			}
			else
			{
				clr2 = buffer[ii++];
				DIBPixel(
					lpData, start+j, y, cx, cy
					)
					= DIB32RGB((GetR(clr1)+GetR(clr2)+1)/2, (GetG(clr1)+GetG(clr2)+1)/2, (GetB(clr1)+GetB(clr2)+1)/2);
			}
		}
	}
	delete buffer;
}



void RectConvert(LPBYTE lpData, int cx, int cy, RECT& rc, MapXY mapping, DIB32COLOR trans)
{
	int dx = rc.right-rc.left, dy = rc.bottom-rc.top;
	int* buffer = new int[dx*dy*4], *p;
	memset(buffer, 0, dx*dy*16);
	double w = (double)(dx-1), h = (double)(dy-1);
	for (int i=dx-1; i>=0; i--)
	{
		for(int j=dy-1; j>=0; j--)
		{
			DIB32COLOR clr = DIBPixel(lpData, rc.left+i,rc.top+j,cx,cy);
			double x = (double)i/w, y = (double)j/h;
			mapping(x, y);
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
				DIBPixel(lpData,rc.left+i,rc.top+j,cx,cy) = trans;
			}
			else
			{
				DIBPixel(lpData,rc.left+i,rc.top+j,cx,cy) = GetAvg(p[1],p[2],p[3],p[0]);
			}
		}
	}
}