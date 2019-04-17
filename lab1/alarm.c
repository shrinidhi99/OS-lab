#include  <stdio.h>
#include  <signal.h>


void  ALARMhandler(int sig)
{
  signal(SIGALRM, SIG_IGN);          
  printf("Hello\n");
  signal(SIGALRM, ALARMhandler);     
}

int main(int argc, char *argv[])
{
  signal(SIGALRM, ALARMhandler);
  alarm(2);                    
}