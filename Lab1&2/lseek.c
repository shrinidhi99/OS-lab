#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include <fcntl.h>  
#include<errno.h>
void main()
{
	int i,j,k;
	char *c = (char *) calloc(100, sizeof(char)); 
	i = creat("file.txt",S_IWUSR);
	printf("Mode: Write %d\n",i);
	printf("%d\nFile has opened for writing only.\n",i);
	k = write(i,"Shrinidhi\n",strlen("Shrinidhi\n"));
	if(close(i) < 0)  
	{ 
		printf("Error while closing file");  
	}
	else
	printf("file2.txt has been closed.\n");  
	i = open("file.txt",O_RDONLY | O_CREAT);
	printf("%d\nFile file.txt has opened for reading only.\n",i);
	j = read(i,c,strlen("Shrinidhi\n"));
	c[j] = '\0';
	printf("File file.txt has been opened and %d bytes are read.\nString read: %s\n",j,c);
	// lseek()	
	k = lseek(i,0,SEEK_CUR);
	printf("lseek: %d\n",k);
	k = lseek(i,0,SEEK_END);
	printf("lseek: %d\n",k);
	k = lseek(i,0,SEEK_SET);
	printf("lseek: %d\n",k);
	// dup()	
	j = dup(i);
	printf("%d dup: \n",j);
	int n;
	// link()
	k = link("file.txt","file_link.txt");
	printf("Link(): %d\n",k);
	// unlink()	
	k = unlink("file_link.txt");
	printf("Unlink(): %d\n",k);	
	int a;
	//access()
	if(!(access("file.txt",F_OK)))
	{
		printf("file.txt exists.\n");
	}
	else
		printf("file.txt doesn't exists.\n");
	if(!(access("file.txt",R_OK)))
	{
		printf("file.txt exists as read only.\n");
	}
	else
		printf("file.txt is not read only.\n");
	if(!(access("file.txt",W_OK)))
	{
		printf("file.txt exists as write only.\n");
	}
	else
		printf("file.txt isn't write only.\n");
	if(!(access("file.txt",X_OK)))
	{
		printf("file.txt exists as execute only.\n");
	}
	else
		printf("file.txt is not execute only.\n");
	//chmod()	
	a = chmod("file.txt",S_IXUSR);
	printf("chmod(): %d\n",a);
	if(close(i) < 0)  
	{ 
		printf("Error while closing file\n");  
	}
	else
	printf("file2.txt has been closed.\n");  
	//chown()
	if(!(chown("file.txt",1002,27)))
	printf("chown() changed student to sudo.\n");
	else
	printf("Error\n");	
	//umask()
	printf("umask(): %d.\n",umask(S_IRUSR));
	//ioctl()
	//if(!(ioctl()))
	//execl()
	//if(execl(const char *path, const char *arg,.../* (char  *) NULL */))
	//wait()
	//exit()
	//getuid()
	//geteuid()
	//getgid()
	//getegid()
	//getpid()
	//getppid()
	//signal()
	//kill()
	//alarm()
	//chdir()	
}
