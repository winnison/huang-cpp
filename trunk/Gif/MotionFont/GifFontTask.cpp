#include "GifFontTask.h"
#include "GifFont.h"

CGifFontTask::CGifFontTask(string file, string text, string formatParams, HFONT font, COLORREF foreColor, COLORREF backColor)
{
	m_Status = 0;
	m_sFile = file;
	m_sText = text;
	m_sFormatParams = formatParams;
	m_hFont = font;
	m_ForeColor = foreColor;
	m_BackColor = backColor;
}
CGifFontTask::~CGifFontTask()
{
	DeleteObject(m_hFont);
}

int CGifFontTask::GetStatus()
{
	return m_Status;
}

void CGifFontTask::Process()
{
	CGifFont gf;
	gf.SetFontColor(m_ForeColor);
	gf.SetTransparent(m_BackColor);
	gf.SetParamsString(m_sFormatParams);
	if (!gf.IsValid())
	{
		m_Status = -1;
	}
	else
	{
		m_Status = gf.Generate(m_sFile, m_sText, m_hFont)?1:-1;
	}
	OnProcessed();
}
