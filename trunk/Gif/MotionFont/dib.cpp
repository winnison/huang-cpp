#include "dib.h"


inline DIB32COLOR GetAvg(int r, int g, int b, int n)
{
	int n2 = n/2;
	return DIB32RGB((r+n2)/n, (g+n2)/n, (b+n2)/n);
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




void Transform(LPBYTE lpDataSrc, LPBYTE lpDataDst, int cx, int cy, float matrix[3][3])
{

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
		da = (int)(sqrt(1-d*d)*dx);
		da1 = da/2;
		da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx2_1);
			db2 = (int)(sqrt(1-dd*dd)*(dy2_1));
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
			db2 = (int)(sqrt(1-dd*dd)*(dy2_1));
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
		da = (int)(sqrt(1-d*d)*dx);
		da1 = da/2;
		da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx2_1);
			db1 = (int)(sqrt(1-dd*dd)*(dy1_1));
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
			db1 = (int)(sqrt(1-dd*dd)*(dy1_1));
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
		da = (int)((1-d)*dx);
		da1 = da/2;
		da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx2_1);
			db2 = (int)((1-dd)*(dy2_1));
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
			db2 = (int)((1-dd)*(dy2_1));
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
		da = (int)((1-d)*dx);
		da1 = da/2;
		da2 = da - da1;
		for (int x=0; x<da2; x++)
		{
			int r=0,g=0,b=0,n=0;
			dd = (double)(x)/(double)(dx2_1);
			db1 = (int)((1-dd)*(dy1_1));
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
			db1 = (int)((1-dd)*(dy1_1));
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
			start = (int)(dx1 * d * d);
			break;
		case 2:
			d = d-2;
			start = (int)(dx2 * d * d);
			break;
		case 3:
			d = 4-d;
			start = dx2 + (int)((dx1-dx2) * (1-d*d));
			break;
		case 4:
		case 5:
			d = (d-4)/2;
			start = (int)(dx1 * (1-d*d));
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