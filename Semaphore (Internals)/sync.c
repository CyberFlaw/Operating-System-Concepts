#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t sem1,sem2;
int play=0;
pthread_mutex_t lock;

void *procedure(void *id);

void main(){
    
    pthread_t processes[3];
    int process_id[3] ={1,2,3};
    pthread_mutex_init(&lock,NULL);
    sem_init(&sem1,0,1);
    sem_init(&sem2,0,0);

    pthread_create(&processes[0],NULL,(void*)procedure,(void*)&process_id[0]);
    pthread_create(&processes[1],NULL,(void*)procedure,(void*)&process_id[1]);
    pthread_create(&processes[2],NULL,(void*)procedure,(void*)&process_id[2]);

    for(int i=0;i<3;i++){
        pthread_join(processes[i],NULL);
    }

    pthread_mutex_destroy(&lock);
    sem_destroy(&sem1);
    sem_destroy(&sem2);
}

void *procedure(void *id){
    if(*((int*)id) != 1){
        sem_wait(&sem1);
    }
    else
        sem_wait(&sem2);

    pthread_mutex_lock(&lock);
    printf("The Process id is: S%d\n",*((int*)id));

    play++;
    pthread_mutex_unlock(&lock);

    if(*((int*)id)!=1){
        sem_post(&sem1);
    }

    if(play>=2){
        sem_post(&sem2);
    }
}