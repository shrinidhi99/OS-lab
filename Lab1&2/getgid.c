#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	printf("getuid() %d is successful!\n",getuid());
	printf("geteuid() %d is successful!\n",geteuid());
	printf("getgid() %d is successful!\n",getgid());
	printf("getegid() %d is successful!\n",getegid());
	int pid = fork();
	printf("Parent process ID is %d.\n",getpid());
	printf("Child process with parent ID is %d.\n",getppid());
}
