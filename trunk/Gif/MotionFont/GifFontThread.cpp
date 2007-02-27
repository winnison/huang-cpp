#include "GifFontThread.h"
#include "GifFont.h"

CGifFontTask::CGifFontTask(GifFontCallBack* callBack, string file, string text, string formatParams, HFONT font)
{
	m_CallBack = callBack;
	m_sFile = file;
	m_sText = text;
	m_sFormatParams = formatParams;
	m_hFont = font;
}
CGifFontTask::~CGifFontTask()
{
	DeleteObject(m_hFont);
}

void CGifFontTask::Process()
{
	CGifFont gf;
	gf.SetParamsString(m_sFormatParams);
	if (gf.Generate(m_sFile, m_sText, m_hFont) && m_CallBack)
	{
		m_CallBack(this);
	}
}
