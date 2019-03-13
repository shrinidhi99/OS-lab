// priority scheduling non preemptive
#include<stdio.h>
#include<stdlib.h>
int sorted(int priority[], int junk[], int k)
{
	int i,min=0;
	for(i=0;i<k;i++)
	{
		if(priority[junk[min]]<priority[junk[i]])
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
	int N,at[100],bt[100],priority[100],i,j,k,Pno[100],time,junk[100],min,n=0,AT[100],BT[100],PNO[100],prior[100],tat[100],ct[100],wt[100];
	printf("Enter the number of processes: ");
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		Pno[i] = i;
		printf("Enter AT, BT and Priority of process %d: ",i);
		scanf("%d %d %d",&at[i],&bt[i],&priority[i]);
	}
	j=at[1];
	for(i=1;i<=N;i++)
	{
		if(j>at[i])
		j = at[i];
	}
	for(i=1;i<=N;i++)
	j = j + bt[i];
	
	for(time=0;time<=j;)
	{
		k=0;
		for(i=1;i<=N;i++)
		{
			if(at[i]<=time && bt[i]!=0 && priority[i]!=0)
			{
				junk[k] = i;
				k++;
			}
		}
		if(k>0)
		{
			min = sorted(priority,junk,k);
			time = time + bt[min];
			AT[n]= at[min];
			BT[n]= bt[min];
			PNO[n]= min;
			prior[n] = priority[min];
			n++;
			bt[min]=0;
			priority[min] = 0;
			min=0;
		}
		else
		time = time + 1;	
	}
	completion(AT,BT,ct,n);
	turnaround(AT,ct,tat,n);
	waiting(wt,tat,BT,n);
	printf("Process\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",PNO[i],AT[i],BT[i],prior[i],ct[i],tat[i],wt[i]);
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
