#include "define.h"
#include <list>
using namespace std;

class CTask
{
public:
	virtual void Process(){};
};

class CTaskThread
{
public:
	CTaskThread();
	~CTaskThread();
	bool Create(int	priority = THREAD_PRIORITY_NORMAL);
	void Stop();
	void Clear();
	virtual void PushTask( CTask*);
protected:
	void PushTaskFront( CTask*);
	void PushTaskBack( CTask*);
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
	virtual void PushTask( CTask* task)
	{
		PushTaskBack(task);
	}
};

class CStackTaskThread :
	public CTaskThread
{
public:
	virtual void PushTask( CTask* task)
	{
		PushTaskFront(task);
	}
};

