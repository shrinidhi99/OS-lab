#include<stdio.h>
#include<stdlib.h>
void main()
{
	int pages[100], N, flag=0, frames,i,j,k, filled[100], HIT = 0, MISS = 0;
	printf("Enter number of frames: ");
	scanf("%d",&frames);
	printf("Enter number of pages: ");
	scanf("%d",&N);
	printf("Enter a sequence of %d pages: ",N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&pages[i]);
	}
	for(i=0;i<frames;i++)
	filled[i] = -1;
	// now we have the sequence. Apply LRU
	for(i=0;i<N;i++)
	{
		flag = 0;
		for(j=0;j<frames;j++)
		{
			if(filled[j] == pages[i])
			{
				printf("Page HIT\n");
				flag = 1;
				++HIT;				
				break;
			}
		}
		if(flag == 0) // MISS
		{
			++MISS;
			printf("Page FAULT\n");
			if(i<frames)
			{
				for(k=0;k<frames;k++)
				{
					if(filled[k] == -1)
					{
						filled[k] = pages[i];
						break;
					}
				}				
			}
			else
			{
				for(k=0;k<frames-1;k++)
				{
					filled[k] = filled[k+1];
				}
				filled[frames-1] = pages[i];
			}
		}
		if(flag == 1) // HIT
		{
			int key = 0,key2=0;
			if(i<frames)
			{			
				for(k=0;k<frames;k++)
				{
					if(filled[k] == -1)
					{
						filled[k] = pages[i];
						key = k;						
						break;
					}
				}
				for(k=0;k<key-1;k++)
				{
					if(filled[k] == pages[i])
					{
						filled[k] = -1;
						key2 = k;
						break;
					}
				}
				for(k=key2;k<key;k++)
				filled[k] = filled[k+1];
			}
			else
			{
				for(k=0;k<frames;k++)
				{
					if(filled[k] == pages[i])
					{
						key = k;						
						break;
					}
				}
				for(k=key;k<frames-1;k++)//  0 1 2 3 4 5
				{
					filled[k] = filled[k+1];
				}
				filled[frames-1] = pages[i];
			}				
		}
		for(k=0;k<frames;k++)
		printf("%d ",filled[k]);
		printf("\n");
	}
	printf("HIT = %d and FAULT = %d.\n",HIT,MISS);
}
