#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <semaphore.h>


#define N 1000000
int var;  // global variable 

void* routine();


