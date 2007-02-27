#include "define.h"
#include <list>
using namespace std;

class CTask
{
public:
	virtual void Process();
};

class CTaskThread
{
public:
	CTaskThread();
	~CTaskThread();
	bool Create(int	priority = THREAD_PRIORITY_NORMAL);
	void Stop();
	bool Clear();
	virtual void PushTask(const CTask*);
protected:
	void PushTaskFront(const CTask*);
	void PushTaskBack(const CTask*);
private:
	void Work();
	static DWORD WINAPI _ThreadProc(LPVOID lp);
private:
	list<CTask*> _tasks;
	HANDLE _hThread;
	HANDLE _hEvent;
	volatile bool _fStop;
	CComAutoCriticalSection m_csListLock;
};

class CQueueTaskThread :
	public CTaskThread
{
	virtual void PushTask(const CTask* task)
	{
		PushTaskBack(task);
	}
};

class CStackTaskThread :
	public CTaskThread
{
public:
	virtual void PushTask(const CTask* task)
	{
		PushTaskFront(task);
	}
};

