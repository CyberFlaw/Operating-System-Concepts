#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<fcntl.h>


void writter(){
    void *shared_memory;
    char buff[100];
    int shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT); 
    shared_memory=shmat(shmid,NULL,0);
    printf("Enter some data to write to shared memory : \n");
    int fd=open("test.txt",O_RDONLY);
    read(fd,shared_memory,100);

    printf("You wrote : %s\n",(char *)shared_memory);
}

void reader(){
    int i;
    void *shared_memory;
    int shmid=shmget((key_t)2345, 1024, 0666);
    shared_memory=shmat(shmid,NULL,0);
    printf("Data read from shared memory is : %s\n",(char *)shared_memory);
}

int main(){
    pid_t pid=fork();
    if(pid>0)
        writter();
    else if(pid==0)
        reader();
}