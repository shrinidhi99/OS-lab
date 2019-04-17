#include<stdio.h>
#include <sys/types.h>
#include <unistd.h> 
int main(){
	uid_t pid =getuid();
	gid_t pid1 =getgid();
	printf("%d\n",chown("foo.txt",pid,pid1));

}