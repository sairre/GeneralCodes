#include "CThread.h"
CThread::CThread()
{
	m_handle = NULL;
	m_ThreadID = -1;
	m_bindSuccess = false;
	m_IsRunning = false;
	m_suspend = false;
}
CThread::~CThread()
{
	m_handle = NULL;
	m_ThreadID = -1;
	m_bindSuccess = false;
	m_IsRunning = false;
	m_suspend = false;
}
CThread::CThread(THREAD_FUN pFunc)
{
	m_handle = NULL;
	m_pFunc = pFunc;
	m_ThreadID = -1;
	m_IsRunning = false;
	m_suspend = false;
	if (m_pFunc)
		m_bindSuccess = true;
	else
		m_bindSuccess = false;
}
bool CThread::EnableSuspendCreated()
{
	if (m_IsRunning)
		return false;

	m_suspend = true;

	return true;
}
bool CThread::bindSuccessful()
{
	return m_bindSuccess;
}
void CThread::bindFunc(THREAD_FUN pFunc)
{
	if (m_bindSuccess)
	{
		return ;
	}
	m_pFunc = pFunc;

	if (m_pFunc)
		m_bindSuccess = true;
	else
		m_bindSuccess = false;
	
}
void CThread::start()
{
	if (m_IsRunning)
		return;
	if (m_suspend)
	{
		m_handle = (HANDLE)_beginthreadex(NULL, 0, StaticThreadFunc, this, CREATE_SUSPENDED, &m_ThreadID);
	}
	else
	{
		m_handle = (HANDLE)_beginthreadex(NULL, 0, StaticThreadFunc, this, 0, &m_ThreadID);
	}
	
}
void CThread::run()
{
	m_IsRunning = true;
	if (!m_bindSuccess)
	{
		return;
	}
	m_pFunc();
	std::cout << "testing...." << std::endl;
}
void CThread::join(int timeout)
{
	if (m_bindSuccess&&m_IsRunning&&m_handle)
	{
		if (timeout < 0)
			timeout = INFINITE;

		WaitForSingleObject(m_handle, timeout);
	}
}
void CThread::resume()
{
	if (!m_suspend || !m_IsRunning || !m_handle)
	{
		return;
	}
	ResumeThread(m_handle);
	m_suspend = false;
}
void CThread::suspend()
{
	if (!m_IsRunning || !m_handle || m_suspend)
	{
		return;
	}
	SuspendThread(m_handle);
}
void CThread::close()
{
	if (!m_IsRunning || !m_handle)
	{
		return;
	}
	CloseHandle(m_handle);
}
unsigned int CThread::StaticThreadFunc(void *arg)
{
	CThread * pthread = (CThread *)arg;
	pthread->run();
	return true;
}
