#include "thread.h"



void* routine(){
	
	for(int i=0;i<N;i++){
		var++;
	}
	return 0;
}

int main(){

	pthread_t t[2];
	printf("Usage: Two threads created to increment the value of N (1000000)\n"); 
	for(int i=0;i<2;i++){
		pthread_create(&t[i],NULL,&routine,NULL);
	}
	
	for(int i=0;i<2;i++){
		pthread_join(t[i],NULL);	
	}
	printf("%d\n",var);	
	
	return 0;
}
