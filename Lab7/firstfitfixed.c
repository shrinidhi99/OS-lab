#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,j,k,blockSize[100],processSize[100],M,N,PNo[100],BNo[100],isAlloc[100];
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
//	for(i=0;i<N;i++)
//	{
//		if(BNo[i] != 101)
//		printf("%d\t%d\t\t%d\n",PNo[i],processSize[i],BNo[i]);
//		else
//		printf("%d\t%d\t\tNot Allocated\n",PNo[i],processSize[i]);
//	}
	
	// now the algorithm begins
	printf("PNo.\tProcess Size\tBlockNo.\n");	
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(blockSize[j]>=processSize[i] && isAlloc[j] == 0)
			{
				isAlloc[j] = 1;
				BNo[i] = j; // assigning the block for a process
				blockSize[j] = blockSize[j]-processSize[i];
				break;
			}
		}
		if(BNo[i] == 101)
		printf("%d\t%d\t\tNot Allocated\n",PNo[i],processSize[i]);
		else
		printf("%d\t%d\t\t%d\n",PNo[i],processSize[i],BNo[i]);
	}
	
	//for(i=0;i<N;i++)
	
		//if(BNo[i] != 101)
		
		//else
		
}
