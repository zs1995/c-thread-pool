#ifndef _THREAD_H
#define _THREAD_H
#include <Windows.h>
#include <string.h>
#include <process.h>
//线程状态  
typedef enum _ThreadState  
{  
	THREAD_RUNNING = 0x0, //运行  
	THREAD_IDLE = 0x1,//空闲  
	THREAD_EXIT = 0X2,//退出  
}ThreadState;  

//线程基类  
class CThread  
{  
private:  
	int m_ErrorCode; //错误码  
	unsigned long m_ThreadID; //线程ID  
	char* m_ThreadName; //线程名字  
	ThreadState m_ThreadState; //线程状态  
	HANDLE m_hthreadHandle; //线程句柄  
	bool      m_IsExit;//是否退出  
protected:  
	static unsigned __stdcall ThreadFunction(void*); //start调用此函数，此函数再调用run函数，执行实际的任务  
public:  
	CThread();  
	virtual ~CThread();  

	virtual void Run() = 0;  

	//设置线程状态  
	void SetThreadState(ThreadState state);  
	//获取线程状态  
	ThreadState GetThreadState();  

	//Start to execute the thread   
	bool Start();  

	//获取线程ID  
	int GetThreadID(void);  

	//设置错误码  
	void SetErrorCode(int errorCode);  
	//获取错误码  
	int GetLastError(void);  

	//设置线程名字  
	void SetThreadName(char* threadName);  
	//获取线程名字  
	char* GetThreadName();  

	//设置线程优先级  
	bool     SetPriority(int priority);   
	//获取线程优先级  
	int      GetPriority(void);   

	bool     Terminate(void);  
	HANDLE GetThreadHandle();  
	void SetThreadHandle(HANDLE hdl);  
	void SetExitFlag(bool bExit);  
	bool GetExitFlag();  
	bool NeedExit();  
};  
#endif