#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main (int argc, char *argv[]) {
    printf("PID of exec1.c = %d\n", getpid());
    char *args[] = {"execprogram", NULL};
    execv("exec-2.c", args);
    printf("Back to exec1.c \n");
}