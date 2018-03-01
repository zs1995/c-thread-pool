#include "Job.h"
static int number = 0;
class CXJob:public CJob 
{ 
public: 
	CXJob(){int i=0;} 
	~CXJob(){} 
	void Run(void* jobdata)    { 
		printf("The Job comes from CXJOB\n"); 
		number ++;
		Sleep(2); 
	} 
}; 