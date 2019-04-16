#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
	int val;
	int distance;
	int accessed;
}A[100];
void sstf(int head,int N)
{
	int i,j,k=0,seek=0,min=10000;
	for(i=0;i<N;i++)
	{
		// picking the nearest request that has not yet been accessed
		for(j=0;j<N;j++)
		{
			if(A[j].accessed == 0 && A[j].distance < min)
			{
				min = A[j].distance;
				k = j;
			}
		}
		// moving the head
		if(A[k].val < head)
		printf("\n<-- Moving left\n");
		else
		printf("\nMoving right -->\n");
		head = A[k].val;
		printf("%d ",head);
		A[k].accessed = 1;
		seek += A[k].distance;
		min = 10000;
		for(j=0;j<N;j++)
		{
			if(A[j].accessed == 0)
			A[j].distance = abs(A[j].val - head);
		}						
	}
	printf("Number of seek operations = %d.\n",seek);
}
void main()
{
	int N,i,j,k,head;
	printf("Enter the number of request sequence: ");
	scanf("%d",&N);
	printf("Enter %d requests: ",N);
	for(i=0;i<N;i++)
	scanf("%d",&A[i].val);
	printf("Enter the head position: ");
	scanf("%d",&head);
	for(i=0;i<N;i++)
	{
		A[i].accessed = 0;
		A[i].distance = abs(A[i].val - head);
	}
	printf("%d ",head);
	sstf(head,N);
}
