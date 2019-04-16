#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

// for single producer and single consumer
int mutex=1,x=0,full=0,empty=5;
int wait(int s)
{
	return --s;	
}
int signal(int s)
{
	return ++s;
}
void producer()
{
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	x++;
	printf("Producer produced process %d.\n",x);
	mutex = signal(mutex);	
}
void consumer()
{
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	printf("Consumer consumed process %d.\n",x);
	mutex = signal(mutex);
	x--;
}
void main()
{
	int i,j,k;
	for(;;)
	{	
		printf("Enter\n1.Producer\n2.Consumer\n3.Exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
			{
				if((mutex==1)&&(empty!=0))
				producer();
				else
				printf("Buffer is full!\n");
				break;
			}
			case 2:
			{
				if((mutex==1)&&(full!=0))
				consumer();
				else
				printf("Buffer is empty!\n");
				break;
			}
			case 3:
			{
				exit(0);			
			}
			default:
			printf("Wrong choice\n");
		}
	}
}

