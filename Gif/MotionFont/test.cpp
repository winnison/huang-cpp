#include "MotionFonts.h"
#include "GifFont.h"
#include "GifDecoder.h"
#include "TaskThread.h"
#include <MMSystem.h>

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
class CTestTask : public CTask
{
	int id;
public:
	CTestTask(int id){this->id = id;};
	virtual void Process(){
		printf("task[%d] try\n", id);
		DWORD dw = 800000000;
		while (--dw);
		//Sleep(1000); 
		printf("task[%d] done\n", id);};
};
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

	//1 file
	//2 text
	//3 fontcolor
	//4 transparent
	//5 quality
	//6 framescount
	//7 interval

	//8 hasEdge
	//9 edgeColor

	//10 hasShadow
	//11 shadowColor
	//12 shadowdis

	//13 sizing type
	//14 align
	//15 valign
	//16 SizingProportion

	//17 Shape type
	//18 motion type

//19 font size
//20 font family

	//string file = argv[1], text = argv[2];
	//CGifFont g;
	//g.SetFontColor(atoi(argv[3]));
	//g.SetTransparent(atoi(argv[4]));
	//g.SetQuality(atoi(argv[5]));
	//g.SetFramesCount(atoi(argv[6]));
	//g.SetInterval(atoi(argv[7]));
	//g.SetHasEdge(atoi(argv[8]));
	//g.SetEdgeColor(atoi(argv[9]));
	//g.SetHasShadow(atoi(argv[10]));
	//g.SetShadowColor(atoi(argv[11]));
	//g.SetShadowDis(atoi(argv[12]));
	//g.SetSizing((CGifFont::SizingType)atoi(argv[13]));
	//g.SetSizingAlign((CGifFont::AlignType)atoi(argv[14]));
	//g.SetSizingVAlign((CGifFont::VAlignType)atoi(argv[15]));
	//g.SetSizingProportion(atof(argv[16]));
	//g.SetShape((CGifFont::ShapeType)atoi(argv[17]));
	//g.SetMotion((CGifFont::MotionType)atoi(argv[18]));

	////string s = g.GetParamsString();
	////g.SetParamsString(s);

	//CFont font;
	//font.CreatePointFont(atoi(argv[19])*10, _T(argv[20]));
	//g.Generate(file, text, font);


	HBITMAP hBmp = LoadPictureFile("1.jpg"), hBmp1, hBmp2;
	BITMAP bmpInfo;
	::GetObject(hBmp,sizeof(BITMAP),&bmpInfo);
	
CDCHandle dcScreen = GetDC(NULL);
CDC dc, dc1;
dc.CreateCompatibleDC(dcScreen);
dc.SelectBitmap(hBmp);
dc1.CreateCompatibleDC(dcScreen);
RECT rc;
rc.left = 0;
rc.top = 0;
rc.right = bmpInfo.bmWidth;
rc.bottom = bmpInfo.bmHeight;

LPBYTE lpData;

hBmp1 = CreateDIB(dcScreen.m_hDC, bmpInfo.bmWidth, bmpInfo.bmHeight, lpData);
dc1.SelectBitmap(hBmp1);
dc1.BitBlt(0,0,rc.right,rc.bottom,dc,0,0,SRCCOPY);
RectToEllipse(lpData, bmpInfo.bmWidth, bmpInfo.bmHeight, rc, 0xffffff);
SaveBmp(hBmp1, "1e.bmp");
hBmp1 = CreateDIB(dcScreen.m_hDC, bmpInfo.bmWidth, bmpInfo.bmHeight, lpData);
dc1.SelectBitmap(hBmp1);
dc1.BitBlt(0,0,rc.right,rc.bottom,dc,0,0,SRCCOPY);
RectToTriangle(lpData, bmpInfo.bmWidth, bmpInfo.bmHeight, rc, 0xffffff);
SaveBmp(hBmp1, "1t.bmp");
hBmp1 = CreateDIB(dcScreen.m_hDC, bmpInfo.bmWidth, bmpInfo.bmHeight, lpData);
dc1.SelectBitmap(hBmp1);
dc1.BitBlt(0,0,rc.right,rc.bottom,dc,0,0,SRCCOPY);
RectToDiamond(lpData, bmpInfo.bmWidth, bmpInfo.bmHeight, rc, 0xffffff);
SaveBmp(hBmp1, "1d.bmp");
hBmp1 = CreateDIB(dcScreen.m_hDC, bmpInfo.bmWidth, bmpInfo.bmHeight, lpData);
dc1.SelectBitmap(hBmp1);
dc1.BitBlt(0,0,rc.right,rc.bottom,dc,0,0,SRCCOPY);
RectToSShape(lpData, bmpInfo.bmWidth, bmpInfo.bmHeight, rc, 0xffffff);
SaveBmp(hBmp1, "1s.bmp");


//char chs[3];
//	CFont font;
//	font.CreatePointFont(200, "宋体");
//	CGifFont g;
//	string text = _T("囸");
//	g.SetFontColor(0xff0000);
//	g.SetHasShadow(FALSE);
//	g.SetHasEdge(FALSE);
//	for (int i=0; i<MOTIONCOUNT; i++)
//	{
//		for (int j=0; j<SHAPECOUNT; j++)
//		{
//			string s = _T("");
//			s += itoa(i, chs, 10);
//			s+="_";
//			s += itoa(j, chs, 10);
//			s += ".gif";
//			g.SetMotion((CGifFont::MotionType)i);
//			g.SetShape((CGifFont::ShapeType)j);
//			g.Generate(s, text, font);
//		}
//	}
//
	//CStackTaskThread qtt;
	//for (int i=0; i<10; i++)
	//{
	//	qtt.PushTask(new CTestTask(i));
	//}
	//printf("Task arranged\n");
	//qtt.Create();
	//Sleep(5500);
	//printf("clear try\n");
	//qtt.Clear();
	//printf("clear done\n");
	//Sleep(6000);
	//printf("Exit\n");

	//for (int i=0; i<30; i++)
	//{
	//	qtt.PushTask(new CTestTask(i));
	//	printf("task[%d] pushed\n", i);
	//	Sleep(((rand()%20)+1)*100);
	//}
	//printf("Task arranged\n");
	//Sleep(30000);
	//printf("Exit\n");


//CGifEncoder age;
//	CGifDecoder gd;
//	age.SetQuality(0);
//	CGif* gif = gd.Load("1.gif");
//	age.Start("1f.gif");
//	age.SetRepeat(0);
//	for (int c= gif->GetFrameCount(),i=0; i<c; i++)
//	{
//		CGifFrame *gf = gif->GetFrame(i);
//		age.SetTransparent(gf->GetTransparent());
//		age.SetDelay(gf->GetDelay());
//		age.AddFrame(gf->GetBitmap());
//	}
//	age.Finish();
//
//	delete gif;
//	gif = gd.Load("2.gif");
//	age.Start("2f.gif");
//	for (int c= gif->GetFrameCount(),i=0; i<c; i++)
//	{
//		CGifFrame *gf = gif->GetFrame(i);
//		age.SetTransparent(gf->GetTransparent());
//		age.SetDelay(gf->GetDelay());
//		age.AddFrame(gf->GetBitmap());
//	}
//	age.Finish();


	//if (b)
	//{
	//	b = EllipseMFont(argv[1], argv[2], font.m_hFont, 0xf0f0f0, 0xff0000, 0xffc0c0);
	//}
	//printf("%d", b);


	//printf("Begin\n");
	//CGifEncoder ge;
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
