#include <pthread.h>
#include <stdio.h>



void *waste_time(void *arg)
{
    printf("In waste_time %d\n", (int)arg);
    int i;
    unsigned long int max = (unsigned long int)arg;
    for (i = 0; i < max; i++)
    {
      if ((i % 1000) == 0)
      {
  //      printf("tid: %d i: %d, max: %ld\n", (int)pthread_self(), i, max);
      }
    }
    return (void *)42;
}

int main(int argc, char **argv)
{
  pthread_t pt;
  int i, j = 0;
    int NUM_THREADS = 5;
    for(i = 0; i< NUM_THREADS; i++) {
      pthread_create(&pt, NULL, waste_time, (void *)30000000);
    }
//  pthread_create(&pt, NULL, waste_time, (void *)20000000);
  printf("created! night-night\n");
    for(j = 0; j<NUM_THREADS; j++) {
    //    printf("\n should be calling pthread_join");
          pthread_join(pt, NULL);
     }
  for(i = 0; i < 100000000; i++) {
    if ((i % 1000) == 0) {
//      printf("i: %d\n", i);
    }
  }
  fflush(stdout);
  return 1;
}






/*
void *waste_time(void *arg)
{
    printf("In waste_time %d\n", (int)arg);
    int i;
    unsigned long int max = (unsigned long int)arg;
    for (i = 0; i < max; i++)
    {
      if ((i % 1000) == 0) 
      {
        printf("tid: %d i: %d, max: %ld\n", (int)pthread_self(), i, max);
      }
    }
    return (void *)42;
}

int main(int argc, char **argv)
{
  pthread_t pt;
  int i;
  pthread_create(&pt, NULL, waste_time, (void *)30000000);
  pthread_create(&pt, NULL, waste_time, (void *)20000000);
  printf("created! night-night\n");
  for(i = 0; i < 100000000; i++) {
    if ((i % 1000) == 0) {
      printf("i: %d\n", i);
    } 
  }
  fflush(stdout);
  return 43;
}
*/
