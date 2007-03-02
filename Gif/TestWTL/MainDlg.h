// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#include "GifDecoder.h"
#pragma once

#include "resource.h"
class CMainDlg : public CDialogImpl<CMainDlg>,
		public CMessageFilter, public CIdleHandler
{
public:
	enum { IDD = IDD_MAINDLG };

	virtual BOOL PreTranslateMessage(MSG* pMsg)
	{
		return CWindow::IsDialogMessage(pMsg);
	}

	virtual BOOL OnIdle()
	{
		return FALSE;
	}

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		MESSAGE_HANDLER(WM_TIMER,OnTimer)
		
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)

	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	typedef CGif* CGifRef;
	CGifRef gfs[11][8];
	int indecis[11][8];
	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		// center the dialog on the screen
		CenterWindow();

		// set icons
		CGifDecoder gd;
		CGif* g;
		char chs[3];
		for (int i=0; i<11; i++)
		{
			for (int j=0; j<8; j++)
			{
				string s = _T("");
				s += itoa(i, chs, 10);
				s+="_";
				s += itoa(j, chs, 10);
				s += ".gif";
				gfs[i][j] = g = gd.Load(s);
				indecis[i][j]=rand()%g->GetFrameCount();
			}
		}

		// register object for message filtering and idle updates
		CMessageLoop* pLoop = _Module.GetMessageLoop();
		ATLASSERT(pLoop != NULL);
		pLoop->AddMessageFilter(this);
		pLoop->AddIdleHandler(this);

		SetTimer(0,200,NULL);


		return TRUE;
	}

	LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		CPaintDC dc(m_hWnd);
		CRect rc;
		GetClientRect(&rc);
		dc.FillSolidRect(&rc, 0xffffff);
		//rc.left += 10;
		//rc.top += 10;


		CDC dcMem;
		dcMem.CreateCompatibleDC(dc);
		HBITMAP hBmpOld = dcMem.GetCurrentBitmap();
		

		const int cellSize = 27, cellSize1 = cellSize+1;
		const int colCount = 8;
		const int rowCount = 11;
		int x1 = rc.left, x2 = x1 + (cellSize+1)*colCount, y1 = rc.top, y2 = y1 + (cellSize+1)*rowCount;
		CPen pen;
		pen.CreatePen(PS_SOLID, 1, 0xe0e0e0);
		dc.SelectPen(pen);
		for (int i=1, y = y1+(cellSize1); i<rowCount; i++)
		{
			dc.MoveTo(x1, y);
			dc.LineTo(x2, y);
			y += cellSize+1;
		}
		for (int i=1, x = x1+(cellSize1); i<colCount; i++)
		{
			dc.MoveTo(x, y1);
			dc.LineTo(x, y2);
			x += cellSize+1;
		}
		for(int i = 0;i < rowCount;i++)
		{
			for (int j = 0;j < colCount;j++)
			{
				CGif* g = gfs[i][j];
				HBITMAP bmp = g->GetFrame(indecis[i][j])->GetBitmap();
				dcMem.SelectBitmap(bmp);
				dc.BitBlt(rc.left + (cellSize1)*j+1,rc.top + (cellSize1)*i+1,cellSize,cellSize,dcMem,0,0,SRCCOPY);
				indecis[i][j] = (indecis[i][j]+1) % g->GetFrameCount();
			}
		}
		CPoint pos;
		::GetCursorPos(&pos);
		ScreenToClient(&pos);
		pos.y = pos.y/cellSize1*cellSize1;
		pos.x = pos.x/cellSize1*cellSize1;
		dc.Draw3dRect(pos.x, pos.y, cellSize1, cellSize1, 0x808080, 0x808080);
		dcMem.SelectBitmap(hBmpOld);
		return 1;
	}

	LRESULT OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		Invalidate(FALSE);
		return 1;
	}

	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		// TODO: Add validation code 
		CloseDialog(wID);
		return 0;
	}

	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		CloseDialog(wID);
		return 0;
	}

	void CloseDialog(int nVal)
	{
		DestroyWindow();
		::PostQuitMessage(nVal);
	}
};
