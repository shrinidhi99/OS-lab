# include <stdio.h>
# include <pthread.h>
#include<stdlib.h>
#include<unistd.h>
# define BufferSize 10

void *Producer();
void *Consumer();

int BufferIndex=0;
char *BUFFER;

pthread_cond_t Buffer_Not_Full=PTHREAD_COND_INITIALIZER;
pthread_cond_t Buffer_Not_Empty=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_t ptid,ctid;
int Np=0,Nc=0;
int main()
{    
    int i;
    
    BUFFER=(char *)malloc(sizeof(char) * BufferSize);            
    printf("Enter number of producers and number of consumers:\n");
    scanf("%d %d",&Np,&Nc);
	for(i=0;i<Np;i++)    
	pthread_create(&ptid,NULL,Producer,NULL);
	for(i=0;i<Nc;i++)
    	pthread_create(&ctid,NULL,Consumer,NULL);
    
    pthread_join(ptid,NULL);
    pthread_join(ctid,NULL);
        
    
    return 0;
}

void *Producer()
{    
	int i;
    for(i=0;i<1;i++)
    {
        pthread_mutex_lock(&mutex);
        if(BufferIndex==BufferSize)
        {                        
            pthread_cond_wait(&Buffer_Not_Full,&mutex);
	    sleep(1);        
	}                        
        BUFFER[BufferIndex++]='@';
        printf("Produce %ld : %d \n",ptid,BufferIndex);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&Buffer_Not_Empty);        
    }    
    
}

void *Consumer()
{
	int i;
    for(i=0;i<1;i++)
    {
        pthread_mutex_lock(&mutex);
        if(BufferIndex==-1)
        {            
            pthread_cond_wait(&Buffer_Not_Empty,&mutex);
	    sleep(1);
        }                
        printf("Consume %ld : %d \n",ctid,BufferIndex--);        
        pthread_mutex_unlock(&mutex);        
        pthread_cond_signal(&Buffer_Not_Full);                
    }    
}

