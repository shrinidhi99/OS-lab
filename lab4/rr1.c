#include<stdio.h>
struct rr
{   int id;
    int atm;
    int bst;
    int tat;
    int ct;
    int wt;
    int bst_t;
};

int main()
{int n,t=1,q;

    struct rr s[100],temp;
    printf("Enter the number of processes and the time quantum\n");
    scanf("%d%d",&n,&q);
   // printf("%d %d",n,q);
    int count=n;
    for(int i=0;i<n;i++)
    {   s[i].id=i+1;
        printf("Enter the arrival time for %d :",s[i].id);
        scanf("%d",&s[i].atm);
        printf("Enter the burst time for %d :",s[i].id);
        scanf("%d",&s[i].bst);
        s[i].bst_t=s[i].bst;

    }
    for (int i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (int j = 0; j < n-i-1; j++)  
           if (s[j].atm > s[j+1].atm) 
              {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
              }
        struct rr a[n+3];
        int p,i=0,k=0,res;
    while(count)
    {int flag=0;
     
     if(t<s[i].atm && i<n)
     {
      t=t+q;
      continue;}
      
     while(s[i].atm<=t && i<n)
     {
        a[i]=s[i];
        i++;
     }
    /* printf("value of ready queue at t=%d \n",t);
     for(int j=0;j<i;j++)
     {
      printf("p%d",a[j].id);
     }*/
     if(k>=i)
      {
        /*k=0;
        while(a[k].bst==-1)
          k++;*/
        k=k%i;
      }
      if(a[k].bst==-1)
        {k++;
          continue;}
    /*for(int j=0;j<i;j++)
    {
        if(a[j].bst<minn && a[j].bst!=-1)
            {minn=a[j].bst;
                p=j;}
    }*/
    if(a[k].bst!=-1) 
     {
      if(s[k].bst>q)
         s[k].bst=s[k].bst-q;
       else
         {res=s[k].bst;
          s[k].bst=0;
          flag=1;}
     }
    if(s[k].bst==0 && a[k].bst!=-1)
       { count--;
        s[k].ct=t+res;
        //printf("\n----------termination completion time= %d------\n",s[k].ct);
        a[k].bst=-1;}
        if(flag==1)
          t+=res;
        else
          t+=q;
        k++;
    
    }
    for(int i=0;i<n;i++)
       {s[i].tat=s[i].ct-s[i].atm;
        s[i].wt=s[i].tat-s[i].bst_t; 
        printf("p%d  arrival time=%d  burst time=%d  completion time=%d TAT=%d waiting time=%d",s[i].id,s[i].atm,s[i].bst_t,s[i].ct,s[i].tat,s[i].wt);
         printf("\n");
     }

}
