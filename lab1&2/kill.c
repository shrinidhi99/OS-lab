#include<signal.h>
#include<stdio.h>
#include<unistd.h>
void main()
{
	kill(getpid(),SIGABRT);
}
