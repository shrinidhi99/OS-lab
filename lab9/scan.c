#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
	int val;
	int accessed;
}A[100];
void main()
{
	int head,prevhead,i,j,k,N,size,seek=0;
	printf("Enter the number of requests: ");
	scanf("%d",&N);
	printf("Enter %d requests: ",N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i].val);
	}
	printf("Give the cylinder size: ");
	scanf("%d",&size);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(A[j].val > A[j+1].val)
			{
				k = A[j].val;
				A[j].val = A[j+1].val;
				A[j+1].val = k;
			}
		}
	}
	for(i=0;i<N;i++)
	printf("%d ",A[i].val);
	for(i=0;i<N;i++)
	A[i].accessed = 0;
	printf("Enter previous head position and the current head position: ");
	scanf("%d %d",&prevhead,&head);
	// now we will determine the direction of the head
	if(prevhead<head)
	{
		//then we need to move right till the end of the cylinder
		// check the next request in this direction		
		k=0;		
		for(i=0;i<N;i++)
		{
			if(A[i].val >= head)
			{	
				k=i;
				break;
			}
		}
		printf("%d\n%d\n",head,A[k].val);
		A[k].accessed = 1;
		head = A[k].val;
		seek += A[k].val;
		//printf("\n");
		for(i=k+1;i<N;i++)
		{
			if(A[i].accessed == 0)
			{
				printf("%d\n",A[i].val);
				A[i].accessed = 1;
				seek += A[i].val;
			}
		}
		seek += (size-1-A[N-1].val);
		printf("\nReached the rightmost end of the cylinder.\n");
		for(i=k-1;i>=0;i--)
		{
			if(A[i].accessed == 0)
			{
				printf("%d\n",A[i].val);
				A[i].accessed = 1;
				seek += A[i].val;
			}		
		}
		seek += (A[0].val - 0);
		printf("\nReached the leftmost end of the cylinder.\n");
	}
	else
	{
		//we need to move left till the start of the cylinder
		// check the next request in this direction
		k=0;		
		for(i=0;i<N;i++)
		{
			if(A[i+1].val >= head && A[i].val <= head)
			{	
				k=i;
				break;
			}
		}
		printf("%d\n%d\n",head,A[k].val);
		A[k].accessed = 1;
		head = A[k].val;
		seek += A[k].val;
		for(i=k-1;i>=0;i--)
		{
			if(A[i].accessed == 0)
			{
				printf("%d\n",A[i].val);
				A[i].accessed = 1;
				seek += A[i].val;
			}
		}
		seek += (A[0].val - 0);
		printf("\nReached the leftmost end of the cylinder.\n");
		for(i=k+1;i<N;i++)
		{
			if(A[i].accessed == 0)
			{
				printf("%d\n",A[i].val);
				A[i].accessed = 1;
				seek += A[i].val;
			}
		}
		seek += (size-1-A[N-1].val);
		printf("\nReached the rightmost end of the cylinder.\n");
	}
	printf("Total = %d.\n",seek);
}
