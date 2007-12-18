#include "stdafx.h"
#include "RichEditElements.h"

CRichEditTextSegment::CRichEditTextSegment(CRichEditText *text, int index, int length)
{
	m_text = text;
	m_index = index;
	m_length = length;
}
int CRichEditTextSegment::GlobalCharIndex()
{
	return m_text->m_globalCharIndex + m_index;
}

void CRichEditTextSegment::GetText(const LPWSTR &lpwString)
{
	lstrcpyn(lpwString, m_text->m_wszString + m_index, m_length); lpwString[m_length] = 0;
}

int CRichEditTextSegment::TextLength()
{
	return m_length;
}

int CRichEditTextSegment::Width()
{
	return m_text->m_xs[m_index+m_length] - m_text->m_xs[m_index];
}

int CRichEditTextSegment::Height()
{
	return m_text->m_cy;
}

int CRichEditTextSegment::GetCharWidth(int index)
{
	index += m_index; 
	return m_text->m_xs[index+1] - m_text->m_xs[index];
}

void CRichEditTextSegment::Draw(CDC &dc, int dx, int dy)
{
	HFONT f = dc.SelectFont(m_text->m_hFont);
	dc.SetBkMode(OPAQUE);
	CRect rc(dx+m_x, dy+m_line->m_y, dx+m_x+Width(), dy+m_line->m_y+m_line->m_cy);
	dc.DrawText(m_text->m_wszString+m_index, m_length, &rc, DT_BOTTOM | DT_LEFT | DT_SINGLELINE |DT_EXPANDTABS | DT_NOPREFIX);
	dc.SelectFont(f);
}

int CRichEditTextSegment::GetTextIndexAt(int &x)
{
	vector<int> &xs = m_text->m_xs;
	x = x + xs[m_index];
	int left = m_index, right = m_index+m_length;
	while(left<right)
	{
		int a = (left+right)/2;
		if(xs[a]>x)
		{
			right = a - 1;
		}
		else
		{
			if(left == a)
			{
				if (xs[right]>x)
				{
					x -= xs[left];
					return left - m_index;
				}
				x -= xs[right];
				right -= m_index;
				if(right == m_length)
					return -1;
				return right;
			}
			left = a;
		}
	}
	x -= xs[left];
	if(right == left)
		return left - m_index;
	return -2;
}

int CRichEditTextLineBreak::GetTextIndexAt(int &x)
{
	if(x<0)
		return -2;
	if(x>=Width())
		return -1;
	return 0;
}


CRichEditText::CRichEditText(LPCWSTR wszString, HFONT hFont, COLORREF color)
{
	m_nStringLength = lstrlen(wszString);
	m_wszString = new wchar_t[m_nStringLength+1];
	lstrcpyn(m_wszString, wszString, m_nStringLength+1);
	m_hFont = hFont;
	m_color = color;
	m_cy = 0;
	CDC dc = GetDC(NULL);
	HFONT f = dc.SelectFont(hFont);
	int x = 0;
	m_xs.push_back(0);
	for (int i=0; i<m_nStringLength; i++)
	{
		CRect rc(0,0, 100, 100);
		dc.DrawText(wszString+i, 1, &rc, DT_CALCRECT | DT_TOP| DT_LEFT | DT_SINGLELINE |DT_EXPANDTABS | DT_NOPREFIX);
		x+=rc.right;
		if(m_cy<rc.bottom)
			m_cy = rc.bottom;
		m_xs.push_back(x);
	}
	dc.SelectFont(f);
	::ReleaseDC(NULL,dc.m_hDC);
}

CRichEditText::~CRichEditText()
{
	delete m_wszString;
}

CRichEditTextSegment* CRichEditText::CreateSegment(int &index, int widthLimit)
{
	if(m_xs[index+1]> m_xs[index] + widthLimit)
		return NULL;
	int start = index, limit = m_xs[index] + widthLimit;
	if(m_wszString[index] == '\r')
	{
		index++;
		if(index<m_nStringLength && m_wszString[index] == '\n')
			index++;
		return new CRichEditTextLineBreak(this, start, index - start);
	}
	else if(m_wszString[index] == '\n')
	{
		index++;
		return new CRichEditTextLineBreak(this, start, index - start);
	}
	while (++index<m_nStringLength && m_xs[index+1] <= limit && m_wszString[index] != '\r' || m_wszString[index] != '\n');
	return new CRichEditTextSegment(this, start, index - start);
}

CRichEditRectangle* CRichEditLine::GetRectangleAt(int &x)
{
	int left = 0, right = m_vecRects.size()-1;
	while(left < right)
	{
		int a = (left+right)/2;
		if(m_vecRects[a]->m_x>x)
		{
			right = a - 1;
		}
		else
		{
			if(left == a)
			{
				if(m_vecRects[right]->m_x>x)
				{
					return m_vecRects[left];
				}
				x -= m_vecRects[right]->m_x;
				if(right == m_vecRects.size()-1 && m_vecRects[right]->m_x + m_vecRects[right]->Width()<=x)
					return NULL;
				return m_vecRects[right];
			}
			left = a;
		}
	}
	if(right == left)
		return m_vecRects[left];
	return NULL;
}


void CRichEditLine::InsertRectangle(CRichEditRectangle* rect, int index)
{
	int x;
	if(index < 0)
	{
		x = m_cx;
		index = m_vecRects.size();
	}
	else
	{
		x = m_vecRects[index]->m_x;
	}
	rect->m_line = this;
	rect->m_x = x;
	x += rect->Width();
	m_vecRects.insert(&m_vecRects[index], rect);
	for (int i= index+1; i < m_vecRects.size(); i++)
	{
		m_vecRects[i]->m_x = x;
		x += m_vecRects[i]->Width();
	}
	m_cx = x;
	if(m_cy<rect->Height())
		m_cy = rect->Height();
}

void CRichEditLine::Draw(CDC &dc, int dx, int dy)
{
	for (int i=0; i<m_vecRects.size(); i++)
	{
		m_vecRects[i]->Draw(dc, dx, dy);
	}
}
