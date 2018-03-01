#include "ThreadManage.h"
#include "XJob.h"

int main() 
{ 
	CThreadManage* manage = new CThreadManage(10); 
	for(int i=0;i<1000;i++) 
	{ 
		CXJob*   job = new CXJob(); 
		manage->Run(job,NULL); 
	} 
	Sleep(2);
	manage->TerminateAll(); 
	printf("%d****",number);
	//getchar();
	return 0;
}
