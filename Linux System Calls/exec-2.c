#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main (int argc, char *argv[]) {
    printf("%s %s \n", argv[0], argv[1]);
    printf("PID of process: %d\n", getpid());
}