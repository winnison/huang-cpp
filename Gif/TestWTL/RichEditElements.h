#include "stdafx.h"


class CRichEditElement
{
public:
	CRichEditElement(){};
	~CRichEditElement(){};
	virtual int OnTimer(bool &invalidate){invalidate = false;return -1;};
	virtual void GetText(const LPWSTR &lpwString) = 0;
	virtual int TextLength() = 0;
};

class CRichEditLine;

class CRichEditRectangle : CRichEditElement
{
protected:
	int m_x;
	CRichEditLine* m_line;
public:
	CRichEditRectangle(){};
	~CRichEditRectangle(){};
public:
	virtual void GetText(const LPWSTR &lpwString){ lpwString[0] = ' '; lpwString[1] = 0;}
	virtual int TextLength(){return 1;}

	virtual int Width(){return 0;}
	virtual int Height(){return 0;}
	int Right(){return m_x+Width();}
	int Left(){return m_x;}
	virtual void Draw(const CDC &dc, int x, int y, int cy) = 0;
	virtual int GetTextIndexAt(int x){return 0;}
	friend class CRichEditLine;
};


class CRichEditText : CRichEditElement
{
	LPWSTR m_wszString;
	int m_nStringLength;
	HFONT m_hFont;
	COLORREF m_color;
	vector<int> m_xs;
	int m_cy;
public:
	CRichEditText(LPCWSTR wszString, HFONT hFont, COLORREF clr);
	~CRichEditText();
public:
	virtual void GetText(const LPWSTR &lpwString){ lstrcpy(lpwString, m_wszString);};
	virtual int TextLength(){return m_nStringLength;};
	friend class CRichEditTextSegment;
};

class CRichEditLine
{
	int m_lineIndex;
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
	vector< CRichEditRectangle* >  m_vecRects;
public:
	CRichEditLine():m_lineIndex(0),m_x(0), m_y(0),m_cx(0),m_cy(0){};
	~CRichEditLine(){};
	CRichEditRectangle* GetRectangleAt(int &x);
};


class CRichEditTextSegment : public CRichEditRectangle
{
protected:
	CRichEditText *m_text;
	int m_index;
	int m_length;
public:
	CRichEditTextSegment(CRichEditText *text){m_text = text;};
	~CRichEditTextSegment(){};

	virtual void GetText(const LPWSTR &lpwString){ lstrcpyn(lpwString, m_text->m_wszString + m_index, m_length); lpwString[m_length] = 0;};
	virtual int TextLength(){return m_length;};

	virtual int Width(){return m_text->m_xs[m_index+m_length] - m_text->m_xs[m_index];}
	virtual int Height(){return m_text->m_cy;}
	virtual int GetTextIndexAt(int &x);
	virtual int GetCharWidth(int index){index += m_index; return m_text->m_xs[index+1] - m_text->m_xs[index];};
};

class CRichEditTextLineBreak : CRichEditTextSegment
{
public:
	virtual int GetTextIndexAt(int &x);
	virtual int GetCharWidth(int index){return Width();}
};


