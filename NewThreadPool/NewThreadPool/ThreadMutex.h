#ifndef _THREADMUTEX_H
#define _THREADMUTEX_H
#include <Windows.h>

class CThreadMutex
{
public:
	CThreadMutex();
	~CThreadMutex();

	CRITICAL_SECTION m_gSection;

	void Lock();
	void Unlock();
	void TryLock();//������������ʽ  
};
#endif
