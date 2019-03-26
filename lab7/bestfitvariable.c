#include<stdio.h>
#include<stdlib.h>
void main()
{
	int min,i,j,k,t,blockSize[100],processSize[100],M,N,PNo[100],BNo[100],isAlloc[100],diff[100],internal,external;
	printf("Enter the number of blocks and number of processes: ");
	scanf("%d %d",&M,&N);
	printf("Enter %d block sizes: ",M);
	for(i=0;i<M;i++)
	{
		scanf("%d",&blockSize[i]);
		isAlloc[i] = 0; // initializing all blocks as free
	}
	printf("Enter %d process sizes: ",N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&processSize[i]);
		PNo[i] = i;
		BNo[i] = 101;
	}
	
	// algorithm begins
	printf("PNo.\tProcess Size\tBlockNo.\n");	
	for(i=0;i<N;i++)
	{
		k=0;
		for(t=0;t<M;t++)
		diff[t] = 100000;
		for(j=0;j<M;j++)
		{
			if(blockSize[j]>=processSize[i] && isAlloc[j]==0)
			{
				diff[k] = blockSize[j] - processSize[i]; 
				++k;
			}
		}
		if(k>0)
		{
			min = 0;
			for(t=0;t<k;t++)
			{
				if(diff[t]<diff[min])
				min = t;
			}
			for(t=0;t<M;t++)
			{
				if(blockSize[t]-processSize[i] == diff[min])
				{
					min = t; // here the block number is found
					break;				
				}
			}
			if(blockSize[min]-processSize[i] == 0)
				isAlloc[min] = 1;
			BNo[i] = min;
			blockSize[min] = blockSize[min]-processSize[i]; 
			printf("%d\t%d\t\t%d\n",PNo[i],processSize[i],BNo[i]);
		}
		else
		printf("%d\t%d\t\tNot Allocated\n",PNo[i],processSize[i]);
	}
}
