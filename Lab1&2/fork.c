#include<stdio.h>
#include<unistd.h>
void main()
{
	fork();
	fork();
	printf("I forked.\n");
}
