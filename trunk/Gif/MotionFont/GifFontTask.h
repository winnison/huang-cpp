#include "TaskThread.h"
#include <string>
using namespace std;

class CGifFontThread;
class CGifFontTask;
typedef void (*GifFontCallBack)(CGifFontTask* task);


class CGifFontTask
	:public CTask
{
public:
	CGifFontTask(GifFontCallBack* callBack, string file, string text, string formatParams, HFONT font);
	~CGifFontTask();
	virtual void Process();
private:
	GifFontCallBack* m_CallBack;
	string m_sFile;
	string m_sText;
	string m_sFormatParams;
	HFONT m_hFont;
};
