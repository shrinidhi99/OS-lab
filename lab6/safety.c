#include<stdio.h>
#include<stdlib.h>
int i,j,k,m,n,available[100],max[100][100],allocation[100][100],need[100][100],work[100],finish[100],safeSeq[100],count=0,P;
int p;
int found = 0;
void safe()
{
	for(i=0;i<m;i++)
	work[i] = available[i];
	for(i=0;i<n;i++)
	finish[i] = 0; // false
	
	while (count < n) 
    { 
        
        for (p = 0; p < n; p++) 
        { 
            if(count == P)
		{
			++n;
			printf("Enter number of resources of each type:\n");
			scanf("%d",&available[n-1]);
			printf("Enter maximum demand of this process:\n");
			for(j=0;j<m;j++)
			{
				scanf("%d",&max[n-1][j]);
			}
			printf("Enter number of processes of each type currently allocated to this process:\n");
			for(j=0;j<m;j++)
			{
				scanf("%d",&allocation[n-1][j]);
			}
			for(j=0;j<m;j++)
			{
				need[n-1][j] = max[n-1][j] - allocation[n-1][j];
			}
		}
            if (finish[p] == 0) 
            { 
                
                for (j = 0; j < m; j++) 
                    if (need[p][j] > work[j]) 
                        break; 
  
                
                if (j == m) 
                { 
                    
                    for (k = 0 ; k < m ; k++) 
                        work[k] += allocation[p][k]; 
  
                    
                    safeSeq[count++] = p;
  
                  
                    finish[p] = 1; 
  
                    found = 1; 
                } 
            } 
        } 
  
        
        if (found == 0) 
        { 
            printf("System is not in safe state"); 
            break; 
        }
    }

    printf("System is in safe state.\nSafe sequence is: "); 
    for (i = 0; i < n ; i++) 
        printf("%d ",safeSeq[i]); 
}
void main()
{
	
	printf("Enter the number of processes and number of resources:\n");
	scanf("%d %d",&n,&m);
	printf("Enter number of resources of each type:\n");
	for(i=0;i<m;i++)
	scanf("%d",&available[i]);
	printf("Enter maximum demand of each process:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter number of processes of each type currently allocated to each process:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
    printf("After how many processes do you need to request for a resource:\n");
	scanf("%d",&P);	
	safe();

	// resource allocation
	int arr[100], index;
	printf("Enter the process number for resource requested: \n");
	scanf("%d",&index);
	printf("Enter the requested instance of each: \n"); 
	for(i=0;i<m;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<m;i++)
	{
		if(need[index][i]<arr[i] || arr[i] > available[i])
		{
			printf("Cannot request.\n");
			break;		
		}
	}
	if(i==m)
	{
		for(i=0;i<m;i++)
		{
			allocation[index][i] += arr[i];
			available[i] -= arr[i];
			need[index][i] -= arr[i];
		}
		safe();
	}
}
