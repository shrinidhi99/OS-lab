#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main()
{
	
	printf("getuid() %d is successful!\n",getuid());
	printf("geteuid() %d is successful!\n",geteuid());
}
