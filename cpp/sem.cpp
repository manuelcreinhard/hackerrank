using namespace std;
#include <iostream>
#include <string.h>
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>  /* Semaphore */
#include "sem.h"


sem_t mutex;
int counter;

int main(){
	int i[2];
	pthread_t thread_a;
	pthread_t thread_b;
	
	i[0] = 0;
	i[1] = 1;
	sem_init(&mutex,0,1);
	
	pthread_create(&thread_a, NULL, (void *) &handler, (void *) &i[0]);
	pthread_create(&thread_b, NULL, (void *) &handler, (void *) &i[1]);
	
	pthread_join(thread_a,NULL);
	pthread_join(thread_b,NULL);
}
