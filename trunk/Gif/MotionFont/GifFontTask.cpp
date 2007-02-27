#include "GifFontTask.h"
#include "GifFont.h"

CGifFontTask::CGifFontTask(string file, string text, string formatParams, HFONT font)
{
	m_Status = 0;
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
