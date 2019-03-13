#include<stdio.h>
#include<stdlib.h>
void main()
{
	int pages[100], N, flag=0, frames,i,j,k, filled[100], HIT = 0, MISS = 0, future[100];
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
	{
		filled[i] = -1;
		future[i] = 0;
	}
	// now we have the sequence. Apply Optimal replacement algorithm
	for(i=0;i<N;i++)
	{
		flag=0;
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
		if(flag == 0) // FAULT
		{
			printf("Page FAULT\n");
			++MISS;
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
				for(k=0;k<frames;k++)
				{
					future[k] = 0;
					for(j=i;j<N;j++)
					{
						if(pages[j] != filled[k])
						{
							++future[k];
						}
						if(pages[j] == filled[k])
						break;
					}
				}
				int max = 0;
				for(k=0;k<frames;k++)
				{
					if(future[max]<future[k])
					max = k;
				}
				// now replace the element
				filled[max] = pages[i];
			}
		}
		// in case of HIT nothing is replaced
		for(k=0;k<frames;k++)
		printf("%d ",filled[k]);
		printf("\n");
	}
	printf("HIT = %d and FAULT = %d.\n",HIT,MISS);
}
