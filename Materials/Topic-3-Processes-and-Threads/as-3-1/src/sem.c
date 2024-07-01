#include "thread.h"

/*2: Avoiding race condition using semaphores*/
sem_t sem;

void* routine(){
	for(int i=0;i<N;i++){
		sem_wait(&sem);
		var++;
		sem_post(&sem);
	}
	return 0;
}

int main(){

	pthread_t t[2];
	printf("Usage: Two threads created to increment the value of N (1000000)\n"); 
	sem_init(&sem,0,1); //(pointer, init to 0 for single process, value of semaphore)
	for(int i=0;i<2;i++){
		pthread_create(&t[i],NULL,&routine,NULL);
	}
	
	for(int i=0;i<2;i++){
		pthread_join(t[i],NULL);	
	}
	printf("%d\n",var);	
	sem_destroy(&sem);
	return 0;
}
