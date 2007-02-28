#include "TaskThread.h"



CTaskThread::CTaskThread() : _hThread(0), _hEvent(0), _fStop(true)
{
}
CTaskThread::~CTaskThread()
{
	Stop();
}
bool CTaskThread::Create(int priority)
{
	if (!_fStop)
		return false;
	DWORD dwThreadId;
	_hThread = CreateThread( NULL, 0, _ThreadProc, (LPVOID)this, 0, &dwThreadId );
	if( _hThread )
	{
		SetThreadPriority( _hThread, priority );
		_hEvent = CreateEvent( NULL, FALSE, FALSE, 0 );
	}
	if( _hThread && _hEvent )
	{
		_fStop = false;
		SetEvent(_hEvent);
	}
	return !_fStop;
}
void CTaskThread::Stop()
{
	_fStop = true;
	if( _hThread && _hEvent )
	{
		Clear();
		SetEvent( _hEvent );
		WaitForSingleObject( _hThread, INFINITE );

		CloseHandle( _hEvent );
		CloseHandle( _hThread );
		_hEvent = NULL;
		_hThread = NULL;
	}
}
void CTaskThread::Clear()
{
	m_csListLock.Lock();
	while(_tasks.size())
	{
		CTask* pt = _tasks.front();
		_tasks.pop_front();
		delete pt;
	}
	m_csListLock.Unlock();
}
void CTaskThread::PushTask(CTask* task)
{
	PushTaskBack(task);
}
void CTaskThread::PushTaskFront(CTask* task)
{
	//if( _fStop )
	//	return;
	BOOL bOK = TRUE;
	m_csListLock.Lock();
	try
	{
		if( task )
			_tasks.push_front(task);
	}
	catch(...)
	{
		bOK = FALSE;
	}
	m_csListLock.Unlock();

	if(bOK)
		SetEvent( _hEvent );
}
void CTaskThread::PushTaskBack(CTask* task)
{
	//if( _fStop )
	//	return;
	BOOL bOK = TRUE;
	m_csListLock.Lock();
	try
	{
		if( task )
			_tasks.push_back(task);
	}
	catch(...)
	{
		bOK = FALSE;
	}
	m_csListLock.Unlock();

	if(bOK)
		SetEvent( _hEvent );
}
void CTaskThread::Work()
{
	while( true ) 
	{
		DWORD dwret = WaitForSingleObject( _hEvent, INFINITE );
		if( dwret == WAIT_OBJECT_0)
		{
			if( _fStop )
				return;
			CTask* pt = NULL;
			m_csListLock.Lock();
			if (_tasks.size())
			{
				pt = _tasks.front();
				_tasks.pop_front();
			}
			m_csListLock.Unlock();
			//Process after unlock;
			if (pt)
			{
				try
				{
					pt->Process();
				}
				catch (...)
				{
				}
				try
				{
					delete pt;
				}
				catch (...)
				{
				}
				SetEvent(_hEvent);
			}
		}
	}

}
DWORD WINAPI CTaskThread::_ThreadProc(LPVOID lp)
{
	CTaskThread *pt = (CTaskThread *)lp;
	if( pt )
		pt->Work();
	return 0;
}
