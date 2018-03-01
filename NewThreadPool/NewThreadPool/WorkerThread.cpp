#include "WorkThread.h"

CWorkerThread::CWorkerThread() 
{ 
	m_Job = NULL; 
	m_JobData = NULL; 
	m_ThreadPool = NULL; 
	m_IsEnd = false; 
} 
CWorkerThread::~CWorkerThread() 
{ 
	if(NULL != m_Job) 
		delete m_Job; 
	if(m_ThreadPool != NULL) 
		delete m_ThreadPool; 
} 

void CWorkerThread::Run() 
{ 
	SetThreadState(THREAD_RUNNING); 
	for(;;) 
	{ 
		while(m_Job == NULL) 
			m_JobCond.Wait();  
	
		m_Job->Run(m_JobData); 
		m_Job->SetWorkThread(NULL); 
		m_Job = NULL; 
		m_ThreadPool->MoveToIdleList(this); 
		if(m_ThreadPool->m_IdleList.size() > m_ThreadPool->GetAvailHighNum()) 
		{ 
			m_ThreadPool->DeleteIdleThread(m_ThreadPool->m_IdleList.size()-m_ThreadPool->GetInitNum()); 
		} 
		m_WorkMutex.Unlock(); 
	} 
} 
void CWorkerThread::SetJob(CJob* job,void* jobdata) 
{ 
	m_VarMutex.Lock(); 
	m_Job = job; 
	m_JobData = jobdata; 
	job->SetWorkThread(this); 
	m_VarMutex.Unlock(); 
	m_JobCond.Signal(); 
} 
void CWorkerThread::SetThreadPool(CThreadPool* thrpool) 
{ 
	m_VarMutex.Lock(); 
	m_ThreadPool = thrpool; 
	m_VarMutex.Unlock(); 
}

void CWorkerThread::Terminate(void)  
{  
	//工作线程在处理任务结束才会解锁，这个时候再去退出线程，避免打断线程处理任务。  
	m_WorkMutex.Lock();  
	SetExitFlag(TRUE);  
	//代表要求线程退出  
	m_Job = NULL;   
	m_JobData = NULL;   
	printf("thread [%d] ready to exit\n", GetThreadID());  
	m_JobCond.Signal(); 
	m_WorkMutex.Unlock();
	//WaitForSingleObject(GetThreadHandle(), INFINITE);  
	CloseHandle(GetThreadHandle());  
}  