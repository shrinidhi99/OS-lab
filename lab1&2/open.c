#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
#include<errno.h>
void main()
{
int i,j,k;
char *c = (char *) calloc(100, sizeof(char)); 
i = open("file1.txt",O_RDONLY);
printf("%d\nFile has opened for reading only.\n",i);
j = read(i,c,0);
printf("File file1.txt has been opened and %d bytes are read.\n",j);
if(close(i) < 0)  
{ 
	printf("Error while closing file");  
}
else
printf("file1.txt has been closed.\n"); 
i = creat("file2.txt",S_IWUSR);
printf("Mode: Write %d\n",i); 
i = open("file2.txt",O_WRONLY | O_CREAT);
printf("%d\nFile has opened for writing only.\n",i);
k = write(i,"Shrinidhi\n",strlen("Shrinidhi\n"));
if(close(i) < 0)  
{ 
	printf("Error while closing file");  
}
else
printf("file2.txt has been closed.\n");  
i = open("file.txt",O_RDWR | O_CREAT);
printf("%d\nFile has opened for reading and writing.\n",i);
if(close(i) < 0)  
{ 
	printf("Error while closing file");  
}
else
printf("file.txt has been closed.\n");  
i = open("file1.txt",O_EXCL);
printf("%d\nFile has opened and its creation was prevented if it already existed.\n",i);
if(close(i) < 0)  
{ 
	printf("Error while closing file");  
}
else
printf("file1.txt has been closed.\n");  
i = open("file.txt",O_RDONLY | O_CREAT);
printf("%d\nFile file.txt has opened for reading only.\n",i);
j = read(i,c,strlen("Shrinidhi\n"));
c[j] = '\0';
printf("File file.txt has been opened and %d bytes are read.\nString read: %s\n",j,c);
	if(close(i) < 0)  
	{ 
		printf("Error while closing file");  
	}
	else
	printf("file2.txt has been closed.\n");  
	
exit(0);
}

