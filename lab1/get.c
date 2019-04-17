#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){

    int val;

    printf("This process is %d\n", getpid());
    printf("The real user ID is %d\n", getuid());
    printf("The effective user ID is %d\n", geteuid());
    printf("The group ID is %d\n", getgid());
    printf("The effective group ID is %d\n", getegid());
    printf("The process ID of parent of calling process is %d\n", getppid());


    if((val=fork())<0){
        printf("Problem creating new process\n");
        return 1;
    }
    //fork returns 0 to newly created process    
    if(val==0){
        printf("This process is %d\n", getpid());
        printf("The real user ID is %d\n", getuid());
        printf("The effective user ID is %d\n", geteuid());
        printf("The effective user ID is %d\n", getgid());
        printf("The effective user ID is %d\n", getegid());
        printf("The effective user ID is %d\n", getppid());
    }

    return 0;

}