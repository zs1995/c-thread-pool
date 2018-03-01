#ifndef _THREAD_H
#define _THREAD_H
#include <Windows.h>
#include <string.h>
#include <process.h>
//�߳�״̬  
typedef enum _ThreadState  
{  
	THREAD_RUNNING = 0x0, //����  
	THREAD_IDLE = 0x1,//����  
	THREAD_EXIT = 0X2,//�˳�  
}ThreadState;  

//�̻߳���  
class CThread  
{  
private:  
	int m_ErrorCode; //������  
	unsigned long m_ThreadID; //�߳�ID  
	char* m_ThreadName; //�߳�����  
	ThreadState m_ThreadState; //�߳�״̬  
	HANDLE m_hthreadHandle; //�߳̾��  
	bool      m_IsExit;//�Ƿ��˳�  
protected:  
	static unsigned __stdcall ThreadFunction(void*); //start���ô˺������˺����ٵ���run������ִ��ʵ�ʵ�����  
public:  
	CThread();  
	virtual ~CThread();  

	virtual void Run() = 0;  

	//�����߳�״̬  
	void SetThreadState(ThreadState state);  
	//��ȡ�߳�״̬  
	ThreadState GetThreadState();  

	//Start to execute the thread   
	bool Start();  

	//��ȡ�߳�ID  
	int GetThreadID(void);  

	//���ô�����  
	void SetErrorCode(int errorCode);  
	//��ȡ������  
	int GetLastError(void);  

	//�����߳�����  
	void SetThreadName(char* threadName);  
	//��ȡ�߳�����  
	char* GetThreadName();  

	//�����߳����ȼ�  
	bool     SetPriority(int priority);   
	//��ȡ�߳����ȼ�  
	int      GetPriority(void);   

	bool     Terminate(void);  
	HANDLE GetThreadHandle();  
	void SetThreadHandle(HANDLE hdl);  
	void SetExitFlag(bool bExit);  
	bool GetExitFlag();  
	bool NeedExit();  
};  
#endif