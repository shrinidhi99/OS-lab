// shortest job first algorithm
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int no;
	int AT;
	int BT;
	int CT;
	int WT;
	int TAT;
}P[100],p[100];
int sorted(int junk[], int k)
{
	int i,min=0;
	for(i=0;i<k;i++)
	{
		if(P[junk[min]].BT>=P[junk[i]].BT)
		min = i;
	} 
	return junk[min];
}	
void completion(int at[],int bt[],int ct[],int N)
{
	int i;
	ct[0] = at[0]+bt[0];
	for(i=1;i<N;i++)
	{
		ct[i] = ct[i-1] + bt[i];
	}
}
void turnaround(int at[],int ct[],int tat[],int N)
{
	int i;
	for(i=0;i<N;i++)
	tat[i] = ct[i] - at[i];
} 
void waiting(int wt[],int tat[],int bt[],int N)
{
	int i;
	for(i=0;i<N;i++)
	wt[i] = tat[i] - bt[i];
}
void main()
{
	int i,N,j,CPUidle,time,k,junk[100],min,n=0,at[100],bt[100],NO[100],wt[100],ct[100],tat[100];
	printf("Enter the number of processes: ");
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		P[i].no = i;
		printf("Enter Arrival time and Burst time of process %d: ",i);
		scanf("%d %d",&P[i].AT,&P[i].BT);
	}
	//CPUidle = P[0].AT; // basically before the first process arrives, CPU is idle
	//printf("The CPU remains idle for %d seconds.\n",CPUidle);	
	j=P[1].AT;	
	printf("hi\n");	
	for(i=1;i<=N;i++)
	j = j + P[i].BT;
	min=0;
	for(time=1;time<=j;)
	{
		k=0;
		for(i=1;i<=N;i++)
		{
			if(P[i].AT<=time && P[i].BT!=0)
			{
				junk[k] = i;
				k++;
			}
		}
		if(k>0)
		{
			min = sorted(junk,k);
			time = time + 1;
			at[n]=P[min].AT;
			bt[n]=P[min].BT;
			NO[n]=P[min].no;
			n++;
			P[min].BT= P[min].BT - 1;
			min=0;
		}
		else
		time = time + 1;	
	}
	//for(i=0;i<N;i++)
	//{
	//	printf("%d\t%d\t%d\n",NO[i],at[i],bt[i]);
	//}
	
	completion(at,bt,ct,N);
	turnaround(at,ct,tat,N);
	waiting(wt,tat,bt,N);
	printf("Timeline as per CT:\n");	
	for(i=0;i<n;i++)	
	printf("P%d|",NO[i]);
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",NO[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	int average_WT = 0;
	int average_TAT = 0;
	for(i=0;i<n;i++)
	{
		average_WT += wt[i];
		average_TAT += tat[i];
	}
	average_WT = (average_WT)/(N);
	average_TAT = (average_TAT)/(N);
	printf("Average waiting time = %d.\n",average_WT);
	printf("Average turnaround time = %d.\n",average_TAT);
}


