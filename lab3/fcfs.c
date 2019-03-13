#include<stdio.h>
#include<stdlib.h>
void sort(int AT[], int BT[],int process)
{
	int i,j,temp1,temp2;
	for(i=1;i<=process;i++)
	{
		for(j=1;j<=process-i;j++)
		{
			if(AT[j]>AT[j+1])
			{
				temp1 = AT[j];
				AT[j] = AT[j+1];
				AT[j+1] = temp1;
				temp2 = BT[j];
				BT[j] = BT[j+1];
				BT[j+1] = temp2;
			}
		}
	}
}
void completion(int BT[], int CT[], int process)
{
	int i;
	CT[0] = 1;
	for(i=1;i<=process;i++)
	{
		CT[i] = CT[i-1] + BT[i];
	}
}
void turnaround(int AT[], int CT[], int TAT[], int process)
{
	int i;
	for(i=0;i<=process;i++)
	TAT[i] = CT[i] - AT[i];
} 
void waiting(int TAT[], int BT[],int WT[],int process)
{
	int i;
	for(i=0;i<=process;i++)
	WT[i] = TAT[i] - BT[i];
}
void main()
{
	int average_WT,average_TAT,i,j,k,process, AT[100],BT[100],CT[100],WT[100],TAT[100];
	printf("Enter the number of processes: ");
	scanf("%d",&process);
	AT[0] = 0;
	BT[0] = 1;
	for(i=1;i<=process;i++)
	{
		printf("Enter Arrival Time and Burst Time of process %d:\n",i);
		scanf("%d %d",&AT[i],&BT[i]);
	}
	printf("CPU is idle from %d to %d.\n",AT[0],BT[0]);
	sort(AT,BT,process);
	completion(BT,CT,process);
	turnaround(AT,CT,TAT,process);
	waiting(TAT,BT,WT,process);
	printf("Proc\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=1;i<=process;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,AT[i],BT[i],CT[i],TAT[i],WT[i]);
	}
	average_WT = 0;
	average_TAT = 0;
	for(i=1;i<=process;i++)
	{
		average_WT += WT[i];
		average_TAT += TAT[i];
	}
	average_WT = (average_WT)/(process);
	average_TAT = (average_TAT)/(process);
	printf("Average waiting time = %d.\n",average_WT);
	printf("Average turnaround time = %d.\n",average_TAT);
}	
