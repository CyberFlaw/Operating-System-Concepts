#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main () {
    fork();
    printf("Hello World \n PID = %d\n", getpid());
}