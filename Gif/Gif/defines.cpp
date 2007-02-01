#include "defines.h"

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


