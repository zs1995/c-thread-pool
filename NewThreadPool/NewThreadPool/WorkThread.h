#ifndef _WORKTHREAD_H
#define _WORKTHREAD_H

#include "Thread.h"
#include "ThreadPool.h"
#include "Job.h"
#include "Condition.h"
#include "ThreadMutex.h"
class CThreadPool;
class CWorkerThread:public CThread 
{ 
private: 
	CThreadPool*  m_ThreadPool; 
	CJob*    m_Job; 
	void*    m_JobData; 
	CThreadMutex m_VarMutex; 
	bool      m_IsEnd; 
public: 
	CCondition   m_JobCond; 
	CThreadMutex m_WorkMutex; 
	CWorkerThread(); 
	virtual ~CWorkerThread(); 
	void Run(); 
	void    SetJob(CJob* job,void* jobdata); 
	CJob*   GetJob(void){return m_Job;} 
	void    SetThreadPool(CThreadPool* thrpool); 
	CThreadPool* GetThreadPool(void){return m_ThreadPool;} 
	void Terminate(void);
}; 

#endif