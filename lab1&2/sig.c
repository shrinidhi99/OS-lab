#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void han()
{
printf("hi\n");
}
void main()
{
signal(SIGINT, han);
while(1)
{
printf("11");
sleep(1);
}
}
