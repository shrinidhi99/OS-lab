#include<stdio.h>
#include<fcntl.h>
void main()
{
    int fd=creat("foo.txt",S_IRWXU|S_IWUSR|S_IRGRP|S_IROTH);
    printf("fd  = %d\n",fd);
}