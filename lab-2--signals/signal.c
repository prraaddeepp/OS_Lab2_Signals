/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int count = 1;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  count = 0;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  while (1){
      alarm(2); //Schedule a SIGALRM for 2 second
      while(count); //busy wait for signal to be delivered
      printf("Turing was right!\n");
      count = 2;
  }
  return 0; 
}