
#include <string>
using namespace std;

class CGifFontThread;
class CGifFontTask;
typedef void (*GifFontCallBack)(CGifFontParams* params);


class CGifFontTask
{
public:
	CGifFontTask(GifFontCallBack* callBack, string file, string text, string formatParams, HFONT font);
	~CGifFontTask();
	void Proc();
private:
	GifFontCallBack* m_CallBack;
	string m_sFile;
	string m_sText;
	string m_sFormatParams;
	HFONT m_hFont;
};

class CStackTaskThread
{
public:
	CGifFontThread();
	~CGifFontThread();
	bool create(int	priorty = THREAD_PRIORITY_BELOW_NORMAL);
	bool clear();
	bool addtask(const CGifFontTask*);
private:
	void work_proc();
	static DWORD WINAPI _ThreadProc(LPVOID lp);
private:
	vector<CGifFontParams*> _jobs;
	HANDLE _hThread;
	HANDLE _hEvent;
	volatile bool _fStop;
	CComAutoCriticalSection m_csListLock;
};