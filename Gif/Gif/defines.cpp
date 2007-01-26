#include "defines.h"
#include <math.h>



COLORREF GetRGBbyHSB(float hue, float saturation, float brightness)
{
	int r, g, b;
	HSBtoRGB(hue, saturation, brightness, r, g, b);
	return RGB(r,g,b);
};

void GetHSBbyRGB(COLORREF rgb, float& hue, float& saturation, float& brightness)
{
	RGBtoHSB(GetRValue(rgb), GetGValue(rgb), GetBValue(rgb), hue, saturation, brightness);
};

/**
* Converts the components of a color, as specified by the HSB 
* model, to an equivalent set of values for the default RGB model. 
* <p>
* The <code>saturation</code> and <code>brightness</code> components
* should be floating-point values between zero and one
* (numbers in the range 0.0-1.0).  The <code>hue</code> component
* can be any floating-point number.  The floor of this number is
* subtracted from it to create a fraction between 0 and 1.  This
* fractional number is then multiplied by 360 to produce the hue
* angle in the HSB color model.
* <p>
* The integer that is returned by <code>HSBtoRGB</code> encodes the 
* value of a color in bits 0-23 of an integer value that is the same 
* format used by the method {@link #getRGB() <code>getRGB</code>}.
* This integer can be supplied as an argument to the
* <code>Color</code> constructor that takes a single integer argument. 
* @param     hue   the hue component of the color
* @param     saturation   the saturation of the color
* @param     brightness   the brightness of the color
* @return    the RGB value of the color with the indicated hue, 
*                            saturation, and brightness.
* @see       java.awt.Color#getRGB()
* @see       java.awt.Color#Color(int)
* @see       java.awt.image.ColorModel#getRGBdefault()
* @since     JDK1.0
*/
void HSBtoRGB(float hue, float saturation, float brightness, int& r, int& g, int& b) {
	r = 0; g = 0; b = 0;
	if (saturation == 0) {
		r = g = b = (int) (brightness * 255.0f + 0.5f);
	} else {
		float h = (hue - (float)floor(hue)) * 6.0f;
		float f = h - (float)floor(h);
		float p = brightness * (1.0f - saturation);
		float q = brightness * (1.0f - saturation * f);
		float t = brightness * (1.0f - (saturation * (1.0f - f)));
		switch ((int) h) {
		case 0:
			r = (int) (brightness * 255.0f + 0.5f);
			g = (int) (t * 255.0f + 0.5f);
			b = (int) (p * 255.0f + 0.5f);
			break;
		case 1:
			r = (int) (q * 255.0f + 0.5f);
			g = (int) (brightness * 255.0f + 0.5f);
			b = (int) (p * 255.0f + 0.5f);
			break;
		case 2:
			r = (int) (p * 255.0f + 0.5f);
			g = (int) (brightness * 255.0f + 0.5f);
			b = (int) (t * 255.0f + 0.5f);
			break;
		case 3:
			r = (int) (p * 255.0f + 0.5f);
			g = (int) (q * 255.0f + 0.5f);
			b = (int) (brightness * 255.0f + 0.5f);
			break;
		case 4:
			r = (int) (t * 255.0f + 0.5f);
			g = (int) (p * 255.0f + 0.5f);
			b = (int) (brightness * 255.0f + 0.5f);
			break;
		case 5:
			r = (int) (brightness * 255.0f + 0.5f);
			g = (int) (p * 255.0f + 0.5f);
			b = (int) (q * 255.0f + 0.5f);
			break;
		}
	}
}

/**
* Converts the components of a color, as specified by the default RGB 
* model, to an equivalent set of values for hue, saturation, and 
* brightness that are the three components of the HSB model. 
* <p>
* If the <code>hsbvals</code> argument is <code>null</code>, then a 
* new array is allocated to return the result. Otherwise, the method 
* returns the array <code>hsbvals</code>, with the values put into 
* that array. 
* @param     r   the red component of the color
* @param     g   the green component of the color
* @param     b   the blue component of the color
* @param     hsbvals  the array used to return the 
*                     three HSB values, or <code>null</code>
* @return    an array of three elements containing the hue, saturation, 
*                     and brightness (in that order), of the color with 
*                     the indicated red, green, and blue components.
* @see       java.awt.Color#getRGB()
* @see       java.awt.Color#Color(int)
* @see       java.awt.image.ColorModel#getRGBdefault()
* @since     JDK1.0
*/
void RGBtoHSB(int r, int g, int b, float& hue, float& saturation, float& brightness) {
	int cmax = (r > g) ? r : g;
	if (b > cmax) cmax = b;
	int cmin = (r < g) ? r : g;
	if (b < cmin) cmin = b;

	brightness = ((float) cmax) / 255.0f;
	if (cmax != 0)
		saturation = ((float) (cmax - cmin)) / ((float) cmax);
	else
		saturation = 0;
	if (saturation == 0)
		hue = 0;
	else {
		float redc = ((float) (cmax - r)) / ((float) (cmax - cmin));
		float greenc = ((float) (cmax - g)) / ((float) (cmax - cmin));
		float bluec = ((float) (cmax - b)) / ((float) (cmax - cmin));
		if (r == cmax)
			hue = bluec - greenc;
		else if (g == cmax)
			hue = 2.0f + redc - bluec;
		else
			hue = 4.0f + greenc - redc;
		hue = hue / 6.0f;
		if (hue < 0)
			hue = hue + 1.0f;
	}
}


void myStrechConvert(CDC& dcDst,int cxDst,int cyDst,CDC& dcSrc,int cxSrc,int cySrc)
{
	int w1 = cxSrc, h1 = cySrc, wd = 0, hd = 0;
	if (w1*cyDst>cxDst*h1)
	{
		//wd = (w1*cyDst*7/8>cxDst*h1)?(w1/8):(w1 - cxDst*h1/cyDst);
		wd = (w1 - cxDst*h1/cyDst);
		w1 -= wd;
		wd /= 2;
	}
	else
	{
		//hd = (w1*cyDst<cxDst*h1*7/8)?(h1/8):(h1 - w1*cyDst/cxDst);
		hd = (h1 - w1*cyDst/cxDst);
		h1 -= hd;
		hd /= 2;
	}

	//Bitmap ret = new Bitmap(width, height);
	for (int i=cxDst - 1; i >= 0; i--)
	{
		for (int j=cyDst - 1; j >= 0; j--)
		{
			int r = 0,g=0,b=0,n=0;
			for (int ii=i*w1/cxDst, iiend = (i+1)*w1/cxDst; ii<iiend||n==0; ii++)
			{
				for (int jj=j*h1/cyDst,jjend = (j+1)*h1/cyDst; jj<jjend||n==0; jj++)
				{
					n++;
					COLORREF clr = dcSrc.GetPixel(ii+wd,jj+hd);
					r+=GetRValue(clr);g +=GetGValue(clr);b+=GetBValue(clr);
				}
			}

			r = (r+n/2)/n;
			g = (g+n/2)/n;
			b = (b+n/2)/n;

			dcDst.SetPixel(i,j, RGB(r,g,b));

			//n = (r*3+g*6+b)/10/n;
			//ret.SetPixel(i,j, RGB(n,n,n));			
		}
	}
	for (int i=cxDst - 1; i >= 0; i--)
	{
		for (int j=cyDst - 1; j >= 0; j--)
		{
			int r = 0,g=0,b=0,n=0;
			COLORREF clr = dcDst.GetPixel(i,j);
		}
	}
	//for (int i=cxDst - 1; i >= 0; i--)
	//{
	//	for (int j=cyDst - 1; j >= 0; j--)
	//	{
	//		int r = 0,g=0,b=0,n=0;
	//		for (int ii=i*w1/cxDst, iiend = (i+1)*w1/cxDst, iistart=ii; ii<iiend||n==0; ii++)
	//		{
	//			int idis = min(ii-iistart, iiend-ii-1);
	//			for (int jj=j*h1/cyDst,jjend = (j+1)*h1/cyDst, jjstart=jj; jj<jjend||n==0; jj++)
	//			{
	//				int dis = 1+idis+min(jj-jjstart, jjend-jj-1);
	//				n+=dis;
	//				COLORREF clr = dcSrc.GetPixel(ii+wd,jj+hd);
	//				r+=dis*GetRValue(clr);g +=dis*GetGValue(clr);b+=dis*GetBValue(clr);
	//			}
	//		}

	//		dcDst.SetPixel(i,j, RGB(r/n,g/n,b/n));

	//		//n = (r*3+g*6+b)/10/n;
	//		//ret.SetPixel(i,j, RGB(n,n,n));			
	//	}
	//}
	//int w1 = cxSrc, h1 = cySrc, wd = 0, hd = 0;
	//if (w1*cyDst>cxDst*h1)
	//{
	//	wd = (w1 - cxDst*h1/cyDst);
	//	w1 -= wd;
	//	wd /= 2;
	//}
	//else
	//{
	//	hd = (h1 - w1*cyDst/cxDst);
	//	h1 -= hd;
	//	hd /= 2;
	//}
	//for (int i=cxDst - 1; i >= 0; i--)
	//{
	//	for (int j=cyDst - 1; j >= 0; j--)
	//	{
	//		int r = 0,g=0,b=0,n=0;
	//		for (int ii=i*cxSrc/cxDst, iiend = (i+1)*cxSrc/cxDst; ii<iiend||n==0; ii++)
	//		{
	//			for (int jj=j*cySrc/cyDst,jjend = (j+1)*cySrc/cyDst; jj<jjend||n==0; jj++)
	//			{
	//				COLORREF clr = dcSrc.GetPixel(ii,jj);
	//				n++;
	//				r+=GetRValue(clr);g +=GetGValue(clr);b+=GetBValue(clr);
	//			}
	//		}
	//		dcDst.SetPixel(i,j, RGB(r/n,g/n,b/n));
	//	}
	//}
}


HBITMAP StretchBitmap(HBITMAP hbmpSrc,int cxDst,int cyDst)
{
	CDCHandle dcScreen = GetDC(NULL);
	CDC dcTemp,dcMem;
	dcMem.CreateCompatibleDC(dcScreen);
	dcTemp.CreateCompatibleDC(dcScreen);

	BITMAP bmpInfo;
	::GetObject(hbmpSrc,sizeof(BITMAP),&bmpInfo);
	CBitmap bmpRet;
	bmpRet.CreateCompatibleBitmap(dcScreen,cxDst,cyDst);
	HBITMAP hBmpOldRet = dcMem.SelectBitmap(bmpRet);
	HBITMAP hBmpOldSrc = dcTemp.SelectBitmap(hbmpSrc);

	myStrechConvert(dcMem,cxDst,cyDst,dcTemp,bmpInfo.bmWidth,bmpInfo.bmHeight);

	dcTemp.SelectBitmap(hBmpOldSrc);
	dcMem.SelectBitmap(hBmpOldRet);

	::ReleaseDC(NULL,dcScreen.m_hDC);

	return bmpRet.Detach();
}


inline void check0to255(int& a)
{
	if(a<0)
	{
		a = 0;
	}
	else if (a>255)
	{
		a = 255;
	}
}

void GrayAdjust(HBITMAP hBitmap)
{
	CBitmapHandle bmpSrc( hBitmap );
	if( bmpSrc.IsNull() ) return;

	CDC dcScreen = GetDC( NULL );
	BITMAP bm;
	bmpSrc.GetBitmap(&bm);

	CDC dc;dc.CreateCompatibleDC( dcScreen.m_hDC );
	CBitmapHandle hOld = dc.SelectBitmap( bmpSrc );

	int p[25500];
	memset(p, 0, 25500*sizeof(int));
	for (int i=0; i<bm.bmWidth; i++)
	{
		for (int j=0; j<bm.bmHeight; j++)
		{
			COLORREF clr = dc.GetPixel(i,j);
			int v = GetRValue(clr)*30 + GetGValue(clr)*59 + GetBValue(clr)*11;
			p[v]++;
		}
	}
	int all = 0;
	for (int i=0; i<25500; i++)
	{
		all += p[i];
		p[i] = all - p[i]/2;
	}
	for (int i=0; i<bm.bmWidth; i++)
	{
		for (int j=0; j<bm.bmHeight; j++)
		{
			COLORREF clr = dc.GetPixel(i,j);
			int r = GetRValue(clr), g = GetGValue(clr), b = GetBValue(clr);
			int v = r*30 + g*59 + b*11;
			if (v)
			{
				int vv = (p[v] * 25500 / all);
				r = vv*r*30/v/30;
				if (r>255)
				{
					r=255;
				}
				g = vv*g*59/v/59;
				if (g>255)
				{
					g=255;
				}
				b = vv*b*11/v/11;
				if (b>255)
				{
					b=255;
				}
				dc.SetPixel(i,j,RGB(r,g,b));
			}
		}
	}
	dc.SelectBitmap( hOld );
	::ReleaseDC(NULL,dcScreen.m_hDC);
}


HBITMAP Transform( HBITMAP hBitmap , float matrix[3][3])
{
	CBitmapHandle bmpSrc( hBitmap );
	if( bmpSrc.IsNull() ) return NULL;

	CDC dcScreen = GetDC( NULL );
	BITMAP bm;
	bmpSrc.GetBitmap(&bm);

	CDC dcTmp;dcTmp.CreateCompatibleDC( dcScreen.m_hDC );
	CBitmapHandle hOld = dcTmp.SelectBitmap( bmpSrc );

	CDC dcMem;dcMem.CreateCompatibleDC( dcScreen.m_hDC );
	CBitmap bmpRet ; bmpRet.CreateCompatibleBitmap( dcScreen.m_hDC , bm.bmWidth , bm.bmHeight );
	CBitmapHandle hOldMem = dcMem.SelectBitmap( bmpRet );

	for (int nX=0; nX <bm.bmWidth; nX++)
	{
		dcMem.SetPixel(nX,0,dcTmp.GetPixel(nX,0));
		dcMem.SetPixel(nX,bm.bmHeight-1, dcTmp.GetPixel(nX,bm.bmHeight-1));
	}
	for (int nY=0; nY<bm.bmHeight; nY++)
	{
		dcMem.SetPixel(0,nY,dcTmp.GetPixel(0,nY));
		dcMem.SetPixel(bm.bmWidth-1,nY, dcTmp.GetPixel(bm.bmWidth-1,nY));
	}
	float f = 0;
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			f += matrix[i][j];
		}
	}
	if (f != 0)
	{
		for (int nX = 1; nX < bm.bmWidth-1; nX++)
		{
			for (int nY = 1; nY < bm.bmHeight-1; nY++)
			{
				float r = 0, g = 0, b = 0;
				for (int i=0; i<3; i++)
				{
					for (int j=0; j<3; j++)
					{
						COLORREF clr = dcTmp.GetPixel( nX-1+i, nY-1+j );
						float w = matrix[i][j];
						r += w*GetRValue(clr);
						g += w*GetGValue(clr);
						b += w*GetBValue(clr);
					}
				}
				int R = (int)(r/f+.5), G = (int)(g/f+.5), B = (int)(b/f+.5);
				check0to255(R);
				check0to255(G);
				check0to255(B);
				dcMem.SetPixel( nX, nY , RGB(R,G,B) );
			}
		}
	}
	dcMem.SelectBitmap( hOldMem );
	dcTmp.SelectBitmap( hOld );
	::ReleaseDC(NULL,dcScreen.m_hDC);
	return bmpRet.Detach();	
}









