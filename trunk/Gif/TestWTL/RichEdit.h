#include "stdafx.h"
#include "RichEditElements.h"



class CRichEdit : public CWindowImpl<CRichEdit, CWindow,CControlWinTraits>
{
public:
	CRichEdit();
	~CRichEdit();


private:
	CPoint m_ptCaretPos;
	HBITMAP m_hCaretBitmap;
protected:
	virtual void OnCaretPosChanging(const CPoint &pt){};
	virtual void OnCaretPosChanged(){};
	virtual HBITMAP CreateCaretBitmap(int width, int height);

protected:
	BEGIN_MSG_MAP(CRichEdit)

		MESSAGE_HANDLER(WM_CHAR,			OnChar)
		MESSAGE_HANDLER(WM_INITDIALOG,		OnInitDialog)
		MESSAGE_HANDLER(WM_PAINT,			OnPaint)
		MESSAGE_HANDLER(WM_ERASEBKGND,		OnEraseBkgnd)
		MESSAGE_HANDLER(WM_LBUTTONDOWN,		OnLButtonDown)
		MESSAGE_HANDLER(WM_RBUTTONDOWN,		OnRButtonDown)


		MESSAGE_HANDLER(WM_SETFOCUS,		OnSetFocus)
		MESSAGE_HANDLER(WM_KILLFOCUS ,		OnKillFocus)
		MESSAGE_HANDLER(WM_IME_STARTCOMPOSITION,		OnImeStartComposition)
		MESSAGE_HANDLER(WM_IME_COMPOSITION,				OnImeComposition)
		MESSAGE_HANDLER(WM_IME_ENDCOMPOSITION,			OnImeEndComposition)

		DEFAULT_REFLECTION_HANDLER()
	END_MSG_MAP()



	LRESULT OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnRButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);


	LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnImeStartComposition(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnImeComposition(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnImeEndComposition(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
public:
	void BeginUpdate();
	void EndUpdate();


private:
	vector<CRichEditLine*> m_lines;
	vector<CRichEditElement*> m_elements;
public:
	int GetElementCount();
	CRichEditElement* GetElement(int index);
	void DeleteElement(CRichEditElement* element);
	void DeleteElement(int index);
	void InsertElement(CRichEditElement* element);
};
