#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// to determine how long the application ran for in seconds
#include <time.h>

int count = 1;

// found that there is sometimes a difference between the executionTime and the total amount of print statements.
int totalCount = 0;  

void handler(int cignal){
  printf("Can't stop\n");
  totalCount ++;
  count = 0;
}

time_t start, stop;

void anotherHandler(int cignal){
  time(&stop);
  int executionTime = stop - start;
  printf("\nTotal execution time: %ds\n", executionTime);
  printf("Total prints: %d\n", totalCount);
  
  exit(1);
}

int main(int argc, char * argv[]){
  signal(SIGINT, anotherHandler);
  signal(SIGALRM, handler);
  time(&start);
  while (1) {
    alarm(1);
    while(count);
    count = 1;
  }
  return 0;
}