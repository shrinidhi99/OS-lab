#include <sys/types.h>
#include <sys/stat.h> 
#include<stdio.h>
int main(){
	mode_t mode = umask(S_IWGRP) ;
	printf("%ulld\n",mode);
}