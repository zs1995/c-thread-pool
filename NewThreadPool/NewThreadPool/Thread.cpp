#include "Thread.h"

bool CThread::NeedExit()  
{  
	return m_IsExit;  
}  

void CThread::SetExitFlag(bool bExit)  
{  
	m_IsExit = bExit;  
}  

bool CThread::GetExitFlag()  
{  
	return m_IsExit;  
}  

bool CThread::Terminate(void)  
{  
	_endthreadex(0);  
	return TRUE;  
}  

HANDLE CThread::GetThreadHandle()  
{  
	return m_hthreadHandle;  
}  

void CThread::SetThreadHandle(HANDLE hdl)  
{  
	m_hthreadHandle = hdl;  
}  

void CThread::SetErrorCode(int errorCode)   
{  
	m_ErrorCode = errorCode;  
}  

int CThread::GetLastError(void)  
{  
	return m_ErrorCode;  
}  

CThread::CThread()  
{  
	m_IsExit = FALSE;  
}  

CThread::~CThread()  
{  

}  

void CThread::SetThreadState(ThreadState state)  
{  
	m_ThreadState = state;  
}  

ThreadState CThread::GetThreadState()  
{  
	return m_ThreadState;  
}  

//Start to execute the thread   
bool CThread::Start()  
{  
	unsigned threadID;  
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, ThreadFunction, this, 0, &threadID);  
	this->m_ThreadID = threadID;  
	this->SetThreadHandle(hThread);  
	return true;  
}  

unsigned __stdcall CThread::ThreadFunction(void* pArg)  
{  
	CThread* pThread = (CThread*)pArg;  
	pThread->Run(); 
	return TRUE;  
}  

int  CThread::GetThreadID(void)  
{  
	return m_ThreadID;  
}  

void CThread::SetThreadName(char* threadName)  
{  
	strncpy(m_ThreadName, threadName, strlen(threadName));  
}  

char* CThread::GetThreadName()  
{  
	return m_ThreadName;  
}  