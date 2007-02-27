#include "TaskThread.h"
#include <string>
using namespace std;



class CGifFontTask
	:public CTask
{
public:
	CGifFontTask(string file, string text, string formatParams, HFONT font, COLORREF foreColor, COLORREF backColor);
	~CGifFontTask();
	virtual void Process();
	virtual void OnProcessed(){};
	int GetStatus();
private:
	int m_Status;
	string m_sFile;
	string m_sText;
	string m_sFormatParams;
	HFONT m_hFont;
	COLORREF m_ForeColor;
	COLORREF m_BackColor;
};
