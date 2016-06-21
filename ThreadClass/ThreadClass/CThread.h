#ifndef CTHREAD_H
#define CTHREAD_H
#include <windows.h>
#include <process.h>
#include <iostream>
typedef void(*THREAD_FUN)(void);
class CThread
{
public:
	CThread();
	CThread(THREAD_FUN);
	~CThread();
	
	void bindFunc(THREAD_FUN);
	bool bindSuccessful(void);
	bool EnableSuspendCreated(void);
	void start();
	void join(int timeout);
	void suspend(void);
	void resume(void);
	void close(void);
	
private:
	void run();
	static unsigned int WINAPI StaticThreadFunc(void * arg);
private:
	THREAD_FUN m_pFunc;
	unsigned int m_ThreadID;
	HANDLE m_handle;
	bool m_bindSuccess;
	bool m_IsRunning;
	bool m_suspend;

};
#endif