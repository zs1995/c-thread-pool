#include "ThreadMutex.h"

CThreadMutex::CThreadMutex()
{
#if (_WIN32_WINNT >= 0x0403)  
	//ʹ�� InitializeCriticalSectionAndSpinCount �����������  
	::InitializeCriticalSectionAndSpinCount(&m_gSection,4000);  
#else  
	::InitializeCriticalSection(&m_gSection);  
#endif  
}

CThreadMutex::~CThreadMutex()
{
	DeleteCriticalSection(&m_gSection);
}


void CThreadMutex::Lock()
{
	EnterCriticalSection(&m_gSection);
}

void CThreadMutex::Unlock()
{
	LeaveCriticalSection(&m_gSection);
}

void CThreadMutex::TryLock()  
{  
	TryEnterCriticalSection(&m_gSection);  
}  