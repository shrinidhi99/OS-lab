#include<stdio.h>
#include<unistd.h>
void main()
{
	if(!chdir("17co145"))
	printf("Success\n");
	else
	printf("Failure\n");
}
