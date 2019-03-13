#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void main()
{
	printf("alarm() %d",alarm(2));
}
