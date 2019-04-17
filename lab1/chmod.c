#include<stdio.h>
#include<sys/stat.h>
int main(){
	printf("%d\n",chmod("foo.txt", S_IRUSR));
}