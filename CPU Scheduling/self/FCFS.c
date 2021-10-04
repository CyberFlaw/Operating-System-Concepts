#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Process
{
    int id;
    int burst_time;
    struct Process *next;
};

void display(struct Process *head) {
    struct Process *temp = head;
    if(temp == NULL) {
        printf("No processes scheduled!\n");
    } else {
        printf("Processes scheduled are:\n");
        printf("Process ID\tBurst Time\n");
        while(temp != NULL) {
            printf("%d\t%d\n", temp->id, temp->burst_time);
            temp = temp->next;
        }
    }
}

void push(struct Process *front, struct Process *rear, int process_id, int burst_time) {
    struct Process *temp = (struct Process*)malloc(sizeof(struct Process));
    temp->id = process_id;
    temp->burst_time = burst_time;
    temp->next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = temp;
    } else if (rear->next == NULL) {
        rear->next = temp;
        rear = rear->next;
        rear->next = NULL;
    }
}

void pop(struct Process *head, struct Process *rear) {
    if(head == rear) 
        head = rear = NULL;
      else if(head == NULL && rear == NULL) 
        printf("No processes scheduled!\n");
      else 
        head = head->next;
    
    display(head);
}

void main() {
    int process_count, choice;
    bool state = true;

    struct Process *rear = NULL;
    struct Process *front = NULL;

    printf("Enter the number of processes: ");
    scanf("%d", &process_count);

    for(int i = 0; i < process_count; i++) {
        int burst_time = 0;
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &burst_time);

        push(front, rear, i, burst_time);
    }
}