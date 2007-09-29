#include "stdafx.h"
#include "RichEditElements.h"


CRichEditText::CRichEditText(LPCWSTR wszString, HFONT hFont, COLORREF color)
{
	m_nStringLength = lstrlen(wszString);
	m_wszString = new wchar_t[m_nStringLength+1];
	lstrcpyn(m_wszString, wszString, m_nStringLength+1);
	m_hFont = hFont;
	m_color = color;
	m_cy = 0;
	CDC dc(NULL);
	HFONT f = dc.SelectFont(hFont);
	int x = 0;
	m_xs.push_back(0);
	for (int i=0; i<m_nStringLength; i++)
	{
		CRect rc(0,0, 0x7fffffff, 0x7fffffff);
		dc.DrawText(wszString+i, 1, &rc, DT_CALCRECT | DT_TOP| DT_LEFT | DT_SINGLELINE |DT_EXPANDTABS | DT_NOPREFIX);
		x+=rc.right;
		if(m_cy<rc.bottom)
			m_cy = rc.bottom;
		m_xs.push_back(x);
	}
	dc.SelectFont(f);
}

CRichEditText::~CRichEditText()
{
	delete m_wszString;
}


CRichEditRectangle* CRichEditLine::GetRectangleAt(int &x)
{
	int left = 0, right = m_vecRects.size()-1;
	while(left < right)
	{
		int a = (left+right)/2;
		if(m_vecRects[a]->Left()>x)
		{
			right = a - 1;
		}
		else
		{
			if(left == a)
			{
				if(m_vecRects[right]->Left()>x)
				{
					return m_vecRects[left];
				}
				x -= m_vecRects[right]->Left();
				if(right == m_vecRects.size()-1 && m_vecRects[right]->Right()<=x)
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

