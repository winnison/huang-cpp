
#include "stdafx.h"
#include "RichEdit.h"

#define FOREACH(t, i, s)  for(t::iterator i = (s).begin(); i!=(s).end(); i++)




CRichEdit::CRichEdit()
:m_ptCaretPos(0,0),
m_hCaretBitmap(NULL)
{

}
CRichEdit::~CRichEdit()
{

}


HBITMAP CRichEdit::CreateCaretBitmap(int width, int height)
{
	CDCHandle dcScreen = ::GetDC(NULL);
	LPBYTE data;
	BITMAPINFO bmpInfo = {
		sizeof(bmpInfo.bmiHeader),		//biSize
			width,							//biWidth
			height,							//biHeight
			1,							//biPlanes
			4*8				//biBitCount
	};
	m_hCaretBitmap = CreateDIBSection(dcScreen,&bmpInfo,DIB_RGB_COLORS,(void**)&data,NULL,0);
	memset(data, 0xff, width*height*4);
	::ReleaseDC(NULL,dcScreen.m_hDC);
	return m_hCaretBitmap;
}




LRESULT CRichEdit::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) 
{ 
	SetFocus();
	bHandled = TRUE;
	return 1L;
};
LRESULT CRichEdit::OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) 
{
	return 1L;
}


LRESULT CRichEdit::OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) 
{ 
	bHandled = TRUE;
	return 1L;
};

LRESULT CRichEdit::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	CRect rcClient,rcWindow;
	GetClientRect(rcWindow);
	rcClient = rcWindow;

	CPaintDC _dc(m_hWnd);
	CBrush *pb = new CBrush();
	pb->CreateSolidBrush(0xff);
	_dc.FillRect(&rcClient, pb->m_hBrush);
	LPCSTR s = "ab阿不";
	WCHAR ss[100], ss1[100];
	int a = MultiByteToWideChar(CP_ACP, 0, s, strlen(s)+1, ss, 100);
	int b = lstrlen(ss);
	lstrcpyn(ss1, ss, 4);
	_dc.DrawText(ss, 6, &rcClient, DT_CALCRECT | DT_TOP| DT_LEFT |DT_EXPANDTABS | DT_NOPREFIX);
	bHandled = TRUE;
	return 1L;
};

LRESULT CRichEdit::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	::SetFocus(m_hWnd);
	return 1L;
};

LRESULT CRichEdit::OnRButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 1L;
};



LRESULT CRichEdit::OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) 
{
	if (m_hCaretBitmap == NULL)
	{
		CreateCaretBitmap(1,10);
	}
	CreateCaret(m_hCaretBitmap);
	SetCaretBlinkTime(500);
	SetCaretPos(m_ptCaretPos.x, m_ptCaretPos.y);
	ShowCaret();
	return 1L;

}

LRESULT CRichEdit::OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) 
{
	DestroyCaret();
	return 1L;
}

LRESULT CRichEdit::OnImeStartComposition(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) 
{
	HIMC hIMC = ::ImmGetContext(m_hWnd);
	COMPOSITIONFORM CompForm;
	CompForm.dwStyle = CFS_POINT;
	CompForm.ptCurrentPos.x = 50;
	CompForm.ptCurrentPos.y = 50;
	::ImmSetCompositionWindow(hIMC, &CompForm);
	//DropCaret();可在此处隐藏光标，在OnImeEndComposition消息处理中再显示光标
	::ImmReleaseContext(m_hWnd, hIMC);
	return ::DefWindowProc(m_hWnd, WM_IME_STARTCOMPOSITION, wParam, lParam);
}

LRESULT CRichEdit::OnImeComposition(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) 
{
	//if (lParam & GCS_RESULTSTR) {
	//	//get result text
	//	HIMC hIMC = ::ImmGetContext(m_hWnd);
	//	if (hIMC) {
	//		const int maxLenInputIME = 200;
	//		wchar_t wcs[maxLenInputIME];
	//		LONG bytes = ::ImmGetCompositionStringW(hIMC,
	//			GCS_RESULTSTR, wcs, (maxLenInputIME-1)*2);
	//		//
	//		// Set new position after converted
	//		CPoint pos = GetCurrentPos();
	//		COMPOSITIONFORM CompForm;
	//		CompForm.dwStyle = CFS_POINT;
	//		CompForm.ptCurrentPos.x = pos.x;
	//		CompForm.ptCurrentPos.y = pos.y;
	//		::ImmSetCompositionWindow(hIMC, &CompForm);
	//		::ImmReleaseContext(m_hWnd, hIMC);
	//	}
	//	return 0;
	//}
	return 1L;
}

LRESULT CRichEdit::OnImeEndComposition(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) 
{
	//ShowCaretAtCurrentPosition();
	return 1L;
}
