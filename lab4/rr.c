// Round robin preemptive
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int no;
	int AT;
	int BT;
	int bt;
	int CT;
	int WT;
	int TAT;
}P[100],p[100];
int front = 0, rear = 0;
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
int enqueue(int A[], int item)
{
	if(front == 0 && rear == 0)
	{
		++front;
		++rear;
		A[front] = item;
	}
	else
	{
		A[++rear] = item;
	}
	return rear;
}
int dequeue(int A[])
{
	if(front == 0 || rear == 0 || front > rear)
	printf("Underflow\n");
	else
	{
		//A[front] = 0;
		++front;
	}
	return front;
}
void main()
{
	int tobe=0,i,N,j,CPUidle,time,k,junk[100],min,n=0,at[100],bt1[100],NO[100],wt[100],ct[100],tat[100],TQ=0, A[100];
	printf("Enter the number of processes: ");
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		P[i].no = i;
		printf("Enter Arrival time and Burst time of process %d: ",i);
		scanf("%d %d",&P[i].AT,&P[i].BT);
		P[i].bt = P[i].BT;
	}
	printf("Enter the time quantum of the process: ");
	scanf("%d",&TQ);
	j=at[1];
	for(i=1;i<=N;i++)
	{
		if(j>at[i])
		j = at[i];
	}	
	//printf("hi\n");	
	for(i=1;i<=N;i++)
	j = j + P[i].bt;
	min=0;
	//loop
	for(time=0;time<=j;)
	{
		k=0;
		for(i=1;i<=N;i++)
		{
			if(P[i].AT<=time && P[i].bt!=0 && i!=tobe)
			{
				A[++rear] = tobe;
				//rear = enqueue(A,P[i].no);
				//junk[k] = i;
				k++;
			}
			//if(tobe != 0 && front!=0)
			
		}
		A[++rear] = tobe;
		//rear = enqueue(A,tobe);
			k++;
		if(k>0)
		{
			//min = sorted(junk,k);
			printf("hi1\n");
			if(P[front].bt >= TQ)	
			time = time + TQ;
			else
			time = time + P[front].bt;
			
			at[n]=P[front].AT;
			bt1[n]=P[front].bt;
			NO[n]=P[front].no;
			n++;
			printf("hi2\n");
			if(P[front].bt >= TQ)
			{
				printf("hi3\n");
				P[front].bt = P[front].bt - TQ;
				tobe = P[front].no;
				++front;
			}
			else
			{
				printf("hi3\n");
				P[front].bt=0;
				++front;
			}
			//min=0;
		}
		else
		{	
			printf("CPU stall for %d units.\n",TQ);
			time = time + TQ;
		}	
	}
	printf("Process\tAT\tBT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",NO[i],at[i],bt1[i]);
	}
	
	/*completion(at,bt1,ct,N);
	turnaround(at,ct,tat,N);
	waiting(wt,tat,bt1,N);
	printf("Timeline as per CT:\n");	
	for(i=0;i<n;i++)	
	printf("P%d|",NO[i]);
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",NO[i],at[i],bt1[i],ct[i],tat[i],wt[i]);
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
	printf("Average turnaround time = %d.\n",average_TAT);*/
}


