#include<stdio.h> 
#include<fcntl.h> 
int main() 
{      
    // if file does not have in directory  
    // then file foo.txt is created. 
    int fd = open("foo.txt", O_RDONLY | O_CREAT);  
      
    printf("fd = %d\n", fd); 
    char *font = "Arial";
    int ret_val = ioctl(fd, SETFONT, font); 
    printf("%d\n",ret_val);
    return 0; 
} 