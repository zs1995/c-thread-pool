#ifndef _CONDITION_H
#define _CONDITION_H

#include "Thread.h"

class CCondition
{
private:  
	HANDLE m_phEvent; //��� 
public:
	CCondition();
	~CCondition();

	void Signal();
	void Wait();
};
#endif