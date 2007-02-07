#include "MotionFonts.h"
#include "GifFont.h"
#include "GifDecoder.h"

HBITMAP LoadPictureFile(LPCTSTR pszFile)
{
	ATLASSERT(pszFile != NULL);

	// open file
	HANDLE hFile = NULL;
	hFile = CreateFile(pszFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return NULL;

	// get file size
	DWORD dwFileSize = GetFileSize(hFile, NULL);
	ATLASSERT(dwFileSize > 0);
	if(dwFileSize < 1)	//如果头像大小为0字节，删除，等下次登陆时重新下载
	{
		CloseHandle(hFile);
		DeleteFile(pszFile);
		return NULL;
	}

	HGLOBAL hGlobal = ::GlobalAlloc(GMEM_MOVEABLE,dwFileSize);
	_ASSERTE(NULL != hGlobal);
	if (hGlobal == NULL)
		return NULL;

	LPVOID pvData = GlobalLock(hGlobal);
	ATLASSERT(NULL != pvData);

	DWORD dwBytesRead = 0;
	// read file and store in global memory
	BOOL bRead = ReadFile(hFile, pvData, dwFileSize, &dwBytesRead, NULL);
	ATLASSERT(FALSE != bRead && dwBytesRead == dwFileSize);
	GlobalUnlock(hGlobal);

	//close the picture file
	CloseHandle(hFile);

	LPSTREAM pstm = NULL;
	// create IStream* from global memory
	HRESULT hr = CreateStreamOnHGlobal(hGlobal, TRUE, &pstm);
	ATLASSERT(SUCCEEDED(hr) && pstm);
	if (FAILED(hr))
	{
		GlobalFree(hGlobal);
		return NULL;
	}

	// Create IPicture from image file
	LPPICTURE pPicture = NULL;

	hr = OleLoadPicture(pstm, dwFileSize, FALSE, IID_IPicture, (LPVOID *)&pPicture);
	if(pPicture == NULL)
		return NULL;
	ATLASSERT(SUCCEEDED(hr) && pPicture); 
	pstm->Release();
	if (FAILED(hr))
		return NULL;

	OLE_HANDLE picHandle = NULL;

	pPicture->get_Handle(&picHandle);
	ATLASSERT(picHandle != NULL);

	/*
	if (pBitmap->m_hObject)
	pBitmap->DeleteObject();
	pBitmap->Attach((HBITMAP)picHandle);*/

	int nType = ::GetObjectType( (HBITMAP)picHandle );
	ATLASSERT( nType == OBJ_BITMAP );

	return (HBITMAP)picHandle;
}





BOOL SaveBmp(HBITMAP hBitmap , LPTSTR szFile) 
{    	 
	HDC				hDC;
	//设备描述表  
	int				iBits;
	//当前显示分辨率下每个像素所占字节数
	WORD            wBitCount;
	//位图中每个像素所占字节数
	DWORD           dwPaletteSize=0, 
		//定义调色板大小， 位图中像素字节大小 ，位图文件大小 ， 写入文件字节数
		dwBmBitsSize,
		dwDIBSize, dwWritten;
	BITMAP          Bitmap;        
	BITMAPFILEHEADER   bmfHdr;
	//位图属性结构    
	BITMAPINFOHEADER   bi;
	//位图文件头结构       
	LPBITMAPINFOHEADER lpbi;			
	//位图信息头结构     
	HANDLE          fh, hDib, hPal,hOldPal=NULL;	
	//指向位图信息头结构,定义文件，分配内存句柄，调色板句柄
	//计算位图文件每个像素所占字节数
	hDC = CreateDC("DISPLAY", NULL,NULL,NULL);
	iBits = GetDeviceCaps(hDC, BITSPIXEL) *  GetDeviceCaps(hDC, PLANES);
	DeleteDC(hDC);
	if (iBits <= 1)
		wBitCount = 1;
	else if (iBits <= 4)
		wBitCount = 4;
	else if (iBits <= 8)
		wBitCount = 8;
	else if (iBits <= 24)
		wBitCount = 24;
	else if (iBits <=32)
		wBitCount = 32;
	//计算调色板大小
	if (wBitCount <= 8)
		dwPaletteSize = (1 << wBitCount) * sizeof(RGBQUAD);

	//设置位图信息头结构
	GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&Bitmap);
	bi.biSize            = sizeof(BITMAPINFOHEADER);
	bi.biWidth           = Bitmap.bmWidth;
	bi.biHeight          = Bitmap.bmHeight;
	bi.biPlanes          = 1;
	bi.biBitCount         = wBitCount;
	bi.biCompression      = BI_RGB;
	bi.biSizeImage        = 0;
	bi.biXPelsPerMeter     = 0;
	bi.biYPelsPerMeter     = 0;
	bi.biClrUsed         = 0;
	bi.biClrImportant      = 0;

	dwBmBitsSize = ((Bitmap.bmWidth * wBitCount+31)/32)* 4 *Bitmap.bmHeight ;

	//为位图内容分配内存
	hDib  = GlobalAlloc(GHND,dwBmBitsSize+
		dwPaletteSize+sizeof(BITMAPINFOHEADER));
	lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib);
	*lpbi = bi;

	// 处理调色板   
	hPal = GetStockObject(DEFAULT_PALETTE);
	if (hPal)
	{
		hDC  = ::GetDC(NULL);
		hOldPal = SelectPalette(hDC, (HPALETTE)hPal, FALSE);
		RealizePalette(hDC);
	}

	// 获取该调色板下新的像素值
	GetDIBits(hDC, hBitmap, 0, (UINT) Bitmap.bmHeight,
		(LPSTR)lpbi + sizeof(BITMAPINFOHEADER)+dwPaletteSize,
		(LPBITMAPINFO)lpbi, DIB_RGB_COLORS);

	//恢复调色板   
	if (hOldPal)
	{
		SelectPalette(hDC, (HPALETTE)hOldPal, TRUE);
		RealizePalette(hDC);
		::ReleaseDC(NULL, hDC);
	}

	//创建位图文件    
	fh = CreateFile(szFile, GENERIC_WRITE, 
		0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);

	if (fh == INVALID_HANDLE_VALUE)
		return FALSE;

	// 设置位图文件头
	bmfHdr.bfType = 0x4D42;  // &quot;BM&quot;
	dwDIBSize    = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dwPaletteSize + dwBmBitsSize;  
	bmfHdr.bfSize = dwDIBSize;
	bmfHdr.bfReserved1 = 0;
	bmfHdr.bfReserved2 = 0;
	bmfHdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) 
		+ (DWORD)sizeof(BITMAPINFOHEADER)
		+ dwPaletteSize;
	// 写入位图文件头
	WriteFile(fh, (LPSTR)&bmfHdr, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);
	// 写入位图文件其余内容
	WriteFile(fh, (LPSTR)lpbi, dwDIBSize, &dwWritten, NULL);
	//消除内存分配  
	GlobalUnlock(hDib);
	GlobalFree(hDib);
	CloseHandle(fh);
	return TRUE;
}

int main(int argc ,char * argv[])
{
	//if(argc!=12)
	//	return 0;
	//float m[3][3];
	//m[0][0] = atoi(argv[1]);
	//m[0][1] = atoi(argv[2]);
	//m[0][2] = atoi(argv[3]);
	//m[1][0] = atoi(argv[4]);
	//m[1][1] = atoi(argv[5]);
	//m[1][2] = atoi(argv[6]);
	//m[2][0] = atoi(argv[7]);
	//m[2][1] = atoi(argv[8]);
	//m[2][2] = atoi(argv[9]);
	//HBITMAP bm0 = LoadPictureFile(argv[10]);
	//SaveBmp(Transform(bm0, m), argv[11]);

	//float matrix[3][3]={{-1,-2,-1},{-2,9,-2},{-1,-2,-1}};
	//char sz[100];
	//for (int i=1; i<70; i++)
	//{
	//	_snprintf(sz, 100, "%d.jpg", i);
	//	HBITMAP bm0 = LoadPictureFile(sz);
	//	if(bm0==NULL)
	//		continue;
	//	HBITMAP bm1 = StretchBitmap(bm0, 40, 40);
	//	_snprintf(sz, 100, "%d.bmp", i);
	//	SaveBmp(bm1, sz);
	//	for(int j=13; j<25; j++)
	//	{
	//		matrix[1][1] = j;
	//		_snprintf(sz, 100, "%d-%d.bmp", i, j);
	//		SaveBmp(Transform(bm1, matrix), sz);
	//	}
	//}
	//float matrix0[3][3]={{1,1,1},{1,1,1},{1,1,1}};
	//float matrix1[3][3]={{1,2,1},{2,4,2},{1,2,1}};
	//float matrix2[3][3]={{1,4,1},{4,-20,4},{1,4,1}};
	//float matrix3[3][3]={{-2,-1,-2},{-1,16,-1},{-2,-1,-2}};
	//float matrix4[3][3]={{-1,-1,-1},{-1,16,-1},{-1,-1,-1}};
	//float matrix5[3][3]={{-1,0,-1},{0,16,0},{-1,-1,-1}};	
	//
	//HBITMAP bm0 = LoadPictureFile("C:\\1.jpg");
	////HBITMAP bm1 = StretchBitmap(bm0, 40, 40);
	//SaveBmp(Transform(bm0, matrix), "C:\\11.bmp")
	//GrayAdjust(bm0);
	//SaveBmp(bm0, "C:\\1.bmp");
	//

	////SaveBmp(Transform(bm1, matrix2), "C:\\11.bmp");

	//HBITMAP bm2 = LoadPictureFile("C:\\2.jpg");
	////HBITMAP bm3 = StretchBitmap(bm2, 40, 40);
	//GrayAdjust(bm2);
	//SaveBmp(bm2, "C:\\2.bmp");

	//SaveBmp(Transform(bm3, matrix2), "C:\\22.bmp");

	//HBITMAP bm = bm3;
	//for (int i=0; i<10; i++)
	//{
	//	char sz[100];
	//	_snprintf(sz, 100, "C:\\bmp\\a\\%d.bmp", i);
	//	SaveBmp(bm = Transform(bm, matrix1),sz);
	//}
	//bm = bm3;
	//for (int i=0; i<10; i++)
	//{
	//	char sz[100];
	//	_snprintf(sz, 100, "C:\\bmp\\b\\%d.bmp", i);
	//	SaveBmp(bm = Transform(bm, matrix2),sz);
	//}
	//for (int i=10; i>=1; i-=1)
	//{
	//	matrix2[1][1] = i;
	//	char sz[100];
	//	_snprintf(sz, 100, "C:\\bmp\\b\\%d.bmp", i);
	//		SaveBmp(Transform(bm3, matrix2),sz);
	//}

	//for (int i=50; i>=6; i-=2)
	//{
	//	matrix5[1][1] = i;
	//	char sz[100];
	//	_snprintf(sz, 100, "C:\\bmp\\c\\%d.bmp", i);
	//		SaveBmp(Transform(bm3, matrix5),sz);
	//}



	//CFont font;
	//font.CreatePointFont(300, _T("幼圆"));
	//CGifFont g;
	//g.SetHasEdge(TRUE);
	//g.SetHasShadow(TRUE);
	//g.SetShadowDis(4);
	//g.SetSizingProportion(.6);
	//g.SetSizing((CGifFont::SizingType)atoi(argv[2]));
	//g.SetShape((CGifFont::ShapeType)atoi(argv[3]));
	//g.SetMotion((CGifFont::MotionType)atoi(argv[4]));
	//g.SetFontColor(0xff0000);
	//g.SetEdgeColor(0xf0f0f0);
	//g.SetTransparent(0xffffff);
	//string file = argv[3], text = argv[1];
	//file = "_"+file+"_";
	//g.Generate(argv[2]+file+argv[4]+".gif", text, font);


CAnimatedGifEncoder age;
	CGifDecoder gd;
	age.SetQuality(0);
	gd.Load("1.gif");
	age.Start("1e.gif");
	age.SetRepeat(0);
	for (int c= gd.GetFrameCount(),i=0; i<c; i++)
	{
		CGifFrame *gf = gd.GetFrame(i);
		age.SetTransparent(gf->GetTransparent());
		age.SetDelay(gf->GetDelay());
		age.AddFrame(gf->GetBitmap());
	}
	age.Finish();


	//if (b)
	//{
	//	b = EllipseMFont(argv[1], argv[2], font.m_hFont, 0xf0f0f0, 0xff0000, 0xffc0c0);
	//}
	//printf("%d", b);


	//printf("Begin\n");
	//CAnimatedGifEncoder ge;
	//if(argc>2)
	//{
	//	ge.Start(argv[1]);
	//	ge.SetQuality(1);
	//	ge.SetRepeat(0);
	//	//ge.SetTransparent(0xff00ff);
	//	int i=2;
	//	do 
	//	{
	//		ge.SetDelay(1000);
	//		ge.AddFrame();
	//		printf("[%d] %s\n",i-1,argv[i]);
	//	} while(++i<argc);
	//}
	//ge.Finish();
	//printf("End\n");

};
