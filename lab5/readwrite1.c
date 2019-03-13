#include<stdio.h>
#include<stdlib.h>
int mutex=1,readcnt=0,wrt=0;
int wait(int s)
{
	--s;
}
int signal(int s)
{
	++s;
}
void reader()
{
	int i = 5;
	do
	{
		// reader wants to enter critical section
		mutex = wait(mutex);
		readcnt++;
		if(readcnt==1)
			wait(wrt);
		mutex = signal(mutex);
		printf("Currently reading here %d\n",i);
		mutex = wait(mutex);
		readcnt--;
		if(readcnt==0)
			signal(wrt);
		mutex = signal(mutex);
	}while(--i);
}
void writer()
{
	int i = 5;
	do
	{
		// writer requests for critical section
		wait(wrt);
		printf("Currently writing %d\n",i);
		// leaved the critical section
		signal(wrt);
	}while(--i);
}
void main()
{
	printf("Here reading has been given higher precedence than writing.\n");
	reader();
	writer();
}
