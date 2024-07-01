#include "thread.h"

/* 1: Avoiding race condition using mutex */
pthread_mutex_t mutex; 

void* routine(){
	for(int i=0;i<N;i++){
		pthread_mutex_lock(&mutex);
		var++;
		pthread_mutex_unlock(&mutex);
	}
	return 0;

	
}

int main(){

	pthread_t t[2];
	printf("Usage: Two threads created to increment the value of N (1000000)\n"); 
	pthread_mutex_init(&mutex,NULL);
	for(int i=0;i<2;i++){
		pthread_create(&t[i],NULL,&routine,NULL);
	}
	
	for(int i=0;i<2;i++){
		pthread_join(t[i],NULL);	
	}
	pthread_mutex_destroy(&mutex);
	printf("%d\n",var);	
	
	return 0;
}
