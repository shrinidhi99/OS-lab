#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
void main()
{
int i;
i = creat("file1.txt",S_IRUSR);
printf("Mode: Read %d\n",i);
i = creat("file2.txt",S_IWUSR);
printf("Mode: Write %d\n",i);
i = creat("file3.txt",S_IXUSR);
printf("Mode: Execute %d\n",i);
}
