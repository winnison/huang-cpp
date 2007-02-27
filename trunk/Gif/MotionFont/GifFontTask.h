#include "TaskThread.h"
#include <string>
using namespace std;



class CGifFontTask
	:public CTask
{
public:
	CGifFontTask(string file, string text, string formatParams, HFONT font);
	~CGifFontTask();
	virtual void Process();
	virtual void OnProcessed(){};
private:
	int m_Status;
	string m_sFile;
	string m_sText;
	string m_sFormatParams;
	HFONT m_hFont;
};
