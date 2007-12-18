#include "stdafx.h"


class CRichEditElement
{
public:
	CRichEditElement(){};
	~CRichEditElement(){};
	virtual int OnTimer(bool &invalidate){invalidate = false;return -1;};
	virtual int GlobalCharIndex(){return -1;};
	virtual void GetText(const LPWSTR &lpwString) = 0;
	virtual int TextLength() = 0;
};

class CRichEditLine;
class CRichEditRectangle : public CRichEditElement
{
public:
	int m_x;
	CRichEditLine* m_line;
	CRichEditRectangle(){};
	~CRichEditRectangle(){};
	virtual void GetText(const LPWSTR &lpwString){ lpwString[0] = ' '; lpwString[1] = 0;}
	virtual int TextLength(){return 1;}

	virtual int Width(){return 0;}
	virtual int Height(){return 0;}
	virtual void Draw(CDC &dc, int dx, int dy) = 0;
	virtual int GetTextIndexAt(int &x){return 0;}
	friend class CRichEditLine;
};

class CRichEditText;
class CRichEditTextSegment : public CRichEditRectangle
{
public:
	CRichEditTextSegment(CRichEditText *text, int index, int length);
	~CRichEditTextSegment(){};
	CRichEditText *m_text;
	int m_index;
	int m_length;
	virtual int GlobalCharIndex();
	virtual void GetText(const LPWSTR &lpwString);
	virtual int TextLength();
	virtual int Width();
	virtual int Height();
	virtual void Draw(CDC &dc, int dx, int dy);
	virtual int GetTextIndexAt(int &x);
	virtual int GetCharWidth(int index);
	friend class CRichEditText;
};

class CRichEditTextLineBreak : public CRichEditTextSegment
{
public:
	CRichEditTextLineBreak(CRichEditText *text, int index, int length):CRichEditTextSegment(text, index, length){};
	~CRichEditTextLineBreak(){};
	virtual int GetTextIndexAt(int &x);
	virtual int GetCharWidth(int index){return Width();}
};

class CRichEditText : public CRichEditElement
{
public:
	int m_globalCharIndex;
	LPWSTR m_wszString;
	int m_nStringLength;
	HFONT m_hFont;
	COLORREF m_color;
	vector<int> m_xs;
	int m_cy;
	CRichEditText(LPCWSTR wszString, HFONT hFont, COLORREF clr);
	~CRichEditText();
	virtual int GlobalCharIndex(){return m_globalCharIndex;}
	virtual void GetText(const LPWSTR &lpwString){ lstrcpy(lpwString, m_wszString);};
	virtual int TextLength(){return m_nStringLength;};

	CRichEditTextSegment* CreateSegment(int &index, int widthLimit);

	friend class CRichEditTextSegment;
};

class CRichEditLine
{
public:
	int m_lineIndex;
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
	vector< CRichEditRectangle* >  m_vecRects;
	CRichEditLine():m_lineIndex(0),m_x(0), m_y(0),m_cx(0),m_cy(0){};
	~CRichEditLine(){};
	CRichEditRectangle* GetRectangleAt(int &x);
	void InsertRectangle(CRichEditRectangle* rect, int index = -1);

	int GlobalCharIndex(){if(m_vecRects.size()) return m_vecRects[0]->GlobalCharIndex();return -1;}
	void Draw(CDC &dc, int dx, int dy);

};




