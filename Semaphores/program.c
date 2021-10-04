#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEM 2
#define BUFFER_SIZE 2

sem_t empty,full;
int in=0,out=0,buffer[BUFFER_SIZE],i;
pthread_mutex_t mutex;

void *producer(void *pno){
	int item;
	for(i=0;i<MAX_ITEM;i++){
		item = rand();
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in] = item;
		printf("Producer %d : Insert item %d at %d\n",*((int*)pno),buffer[in],in);
		in = (in+1)%BUFFER_SIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}

void *consumer(void *cno){
	for(i=0;i<MAX_ITEM;i++){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item = buffer[out];
		printf("Consumer %d : Remove item %d from %d\n",*((int*)cno),item,out);
		out = (out+1)%BUFFER_SIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

void main(){
	pthread_t pro[MAX_ITEM],con[MAX_ITEM];
	pthread_mutex_init(&mutex,NULL);
	sem_init(&empty,0,BUFFER_SIZE);
	sem_init(&full,0,0);
	int a[MAX_ITEM] ={0,1};
	for(i=0;i<MAX_ITEM;i++){
		pthread_create(&pro[i],NULL,(void*)producer,(void*)&a[i]);
	}
	for(i=0;i<MAX_ITEM;i++){
		pthread_create(&con[i],NULL,(void*)consumer,(void*)&a[i]);
	}
	for(i=0;i<MAX_ITEM;i++){
		pthread_join(pro[i],NULL);
	}
	for(i=0;i<MAX_ITEM;i++){
		pthread_join(con[i],NULL);
	}

	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
}

