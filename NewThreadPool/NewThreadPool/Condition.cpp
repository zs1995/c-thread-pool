#include "Condition.h"


CCondition::CCondition()  
{  
	//�ڶ������� bManualReset FALSE the system automatically resets the state to nonsignaled  
	//If this parameter is TRUE, the function creates a manual-reset event object  
	//���������� bInitialState FALSE it is nonsignaled  
	m_phEvent = ::CreateEvent(NULL, TRUE, FALSE, NULL);  
}  

CCondition::~CCondition()  
{  
	if (NULL != m_phEvent)  
	{  
		::CloseHandle((m_phEvent));  
	}  
}  

void CCondition::Wait()  
{  
	//If dwMilliseconds is INFINITE, the function will return only when the object is signaled.  
	WaitForSingleObject(m_phEvent, INFINITE);  
	ResetEvent(m_phEvent);  
}  

void CCondition::Signal()  
{  
	//Sets the specified event object to the signaled state  
	SetEvent(m_phEvent);  
}  