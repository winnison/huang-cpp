#include <math.h>


#define DIB32COLOR unsigned int
#define GetPos(x, y, width, height)  4*(((height)-(y)-1)*(width)+(x))
#define DIB32COLORAT(p) (*((DIB32COLOR*)(p)))
#define GetDIBPixel(clr, p, x, y, width, height) clr = DIB32COLORAT( (LPBYTE)p+GetPos(x,y,width,height) )
#define SetDIBPixel(clr, p, x, y, width, height) DIB32COLORAT( (LPBYTE)p+GetPos(x,y,width,height) ) = clr
#define GetB(rgb)      ((BYTE)(rgb))
#define GetG(rgb)      ((BYTE)(((WORD)(rgb)) >> 8))
#define GetR(rgb)      ((BYTE)((rgb)>>16))
#define DIB32RGB(r,g,b) ((((r) & 0xff)<<16) | (((g) & 0xff)<<8) | ((b) & 0xff) )

inline HBITMAP CreateDIB(HDC hdc,int cx,int cy, LPBYTE &lpData)
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
inline DIB32COLOR GetAvg(int r, int g, int b, int n)
{
	int n2 = n/2;
	return DIB32RGB((r+n2)/n, (g+n2)/n, (b+n2)/n);
}
inline void RectToEllipse(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{
	int dx = rc.right-rc.left, dy = rc.bottom-rc.top, dx1 = dx/2, dx2 = dx -dx1, dy1=dy/2, dy2=dy-dy1;
	int dx1_1 = dx1-1, dx2_1=dx2-1, dy1_1=dy1-1, dy2_1=dy2-1, da, da1, da2, db1, db2, xend, yend;
	double d, dd;
	DIB32COLOR clr;
	for (int y=0; y<dy2; y++)
	{
		d = (double)(y)/(double)(dy2-1);
		da = (int)(sqrt(1-d*d)*dx);
		da1 = da/2;
		da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx2-1);
			db2 = (int)(sqrt(1-dd*dd)*(dy2-1));
			xend = (x+1)*dx2/da2;
			if (xend>dx2)
			{
				xend = dx2;
			}
			yend = (y+1)*dy2/db2;
			if (yend>dy2)
			{
				yend = dy2;
			}
			for (int xx=x*dx2/da2; xx<xend; xx++)
			{
				for(int yy=y*dy2/db2; yy<yend; yy++)
				{
					GetDIBPixel(clr, lpData, rc.left+dx1+xx, rc.top+dy1+yy, cx, cy);
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
				SetDIBPixel(GetAvg(r,g,b,n), lpData, rc.left+dx1+x, rc.top+dy1+y, cx, cy);
			}
			else
			{
				SetDIBPixel(trans, lpData, rc.left+dx1+x, rc.top+dy1+y, cx, cy);
			}
		}
		for (int x=da2; x<dx2; x++)
		{
			SetDIBPixel(trans, lpData, rc.left+dx1+x,rc.top+dy1+y, cx, cy);
		}

		for (int x=0; x<da1; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx1-1);
			db2 = (int)(sqrt(1-dd*dd)*(dy2-1));
			xend = (x+1)*dx1/da1;
			if (xend>dx1)
			{
				xend = dx1;
			}
			yend = (y+1)*dy2/db2;
			if (yend>dy2)
			{
				yend = dy2;
			}
			for (int xx=x*dx1/da1; xx<xend; xx++)
			{
				for(int yy=y*dy2/db2; yy<yend; yy++)
				{
					GetDIBPixel(clr, lpData, rc.left+dx1-xx-1, rc.top+dy1+yy, cx, cy);
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
				SetDIBPixel(GetAvg(r,g,b,n), lpData, rc.left+dx1-x-1, rc.top+dy1+y, cx, cy);
			}
			else
			{
				SetDIBPixel(trans, lpData, rc.left+dx1-x-1, rc.top+dy1+y, cx, cy);
			}
		}
		for (int x=da1; x<dx1; x++)
		{
			SetDIBPixel(trans, lpData, rc.left+dx1-x-1,rc.top+dy1+y, cx, cy);
		}

	}
	for (int y=0; y<dy1; y++)
	{
		d = (double)(y)/(double)(dy1-1);
		da = (int)(sqrt(1-d*d)*dx);
		da1 = da/2;
		da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx2-1);
			db1 = (int)(sqrt(1-dd*dd)*(dy1-1));
			xend = (x+1)*dx2/da2;
			if (xend>dx2)
			{
				xend = dx2;
			}
			yend = (y+1)*dy1/db1;
			if (yend>dy1)
			{
				yend = dy1;
			}
			for (int xx=x*dx2/da2; xx<xend; xx++)
			{
				for(int yy=y*dy1/db1; yy<yend; yy++)
				{
					GetDIBPixel(clr, lpData, rc.left+dx1+xx, rc.top+dy1-yy-1, cx, cy);
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
				SetDIBPixel(GetAvg(r,g,b,n), lpData, rc.left+dx1+x, rc.top+dy1-y-1, cx, cy);
			}
			else
			{
				SetDIBPixel(trans, lpData, rc.left+dx1+x, rc.top+dy1-y-1, cx, cy);
			}
		}
		for (int x=da2; x<dx2; x++)
		{
			SetDIBPixel(trans, lpData, rc.left+dx1+x,rc.top+dy1-y-1, cx, cy);
		}

		for (int x=0; x<da1; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx1-1);
			db1 = (int)(sqrt(1-dd*dd)*(dy1-1));
			xend = (x+1)*dx1/da1;
			if (xend>dx1)
			{
				xend = dx1;
			}
			yend = (y+1)*dy1/db1;
			if (yend>dy1)
			{
				yend = dy1;
			}
			for (int xx=x*dx1/da1; xx<xend; xx++)
			{
				for(int yy=y*dy1/db1; yy<yend; yy++)
				{
					GetDIBPixel(clr, lpData, rc.left+dx1-xx-1, rc.top+dy1-yy-1, cx, cy);
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
				SetDIBPixel(GetAvg(r,g,b,n), lpData, rc.left+dx1-x-1, rc.top+dy1-y-1, cx, cy);
			}
			else
			{
				SetDIBPixel(trans, lpData, rc.left+dx1-x-1, rc.top+dy1-y-1, cx, cy);
			}
		}
		for (int x=da1; x<dx1; x++)
		{
			SetDIBPixel(trans, lpData, rc.left+dx1-x-1,rc.top+dy1-y-1, cx, cy);
		}

	}
}

inline void RectToTriangle(LPBYTE lpData, int cx, int cy, RECT& rc, DIB32COLOR trans)
{
	int dx = rc.right-rc.left, dy = rc.bottom-rc.top, dx1 = dx/2, dx2 = dx -dx1;
	int dy_1 = dy - 1;
	DIB32COLOR clr;
	for (int y=0; y<dy; y++)
	{
		int da = dx*y/dy_1, da1 = da/2, da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			for (int xx=x*dx2/da2, end = (x+1)*dx2/da2; xx<end; xx++)
			{
				GetDIBPixel(clr, lpData, rc.left+dx1+xx, rc.top+y, cx, cy);
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
				SetDIBPixel(DIB32RGB(r/n,g/n,b/n), lpData, rc.left+dx1+x, rc.top+y, cx, cy);
			}
			else
			{
				SetDIBPixel(trans, lpData, rc.left+dx1+x, rc.top+y, cx, cy);
			}
		}
		for (int x=da2; x<dx2; x++)
		{
			SetDIBPixel(trans, lpData, rc.left+dx1+x,rc.top+y, cx, cy);
		}

		for (int x=0; x<da1; x++)
		{
			int r=0,g=0,b=0,n=0;
			for (int xx=x*dx1/da1, end = (x+1)*dx1/da1; xx<end; xx++)
			{
				GetDIBPixel(clr, lpData, rc.left+dx1-xx-1, rc.top+y, cx, cy);
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
				SetDIBPixel(DIB32RGB(r/n,g/n,b/n), lpData, rc.left+dx1-x-1, rc.top+y, cx, cy);
			}
			else
			{
				SetDIBPixel(trans, lpData, rc.left+dx1-x-1, rc.top+y, cx, cy);
			}
		}
		for (int x=da1; x<dx1; x++)
		{
			SetDIBPixel(trans, lpData, rc.left+dx1-x-1,rc.top+y, cx, cy);
		}
	}
}


