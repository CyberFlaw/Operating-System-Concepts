#include <stdio.h>
#include <stdlib.h>

void fcfs(){
    int header, total=0, prev, n=0, temp, i, p;
    int *req;

    FILE *f;
    if ((f = fopen("input.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    while (!feof(f)){
        fscanf(f, "%d\n", &temp);
        n++;
    }
    
    rewind(f);

    i = 0;
    req = (int*)malloc(n * sizeof(int));

    while (!feof(f)){
        fscanf(f, "%d\n", req + i);
        i++;
    }

    printf("Enter current header position: ");
    scanf("%d", &header);

    p = n;
    i = 0;

    while (p > 0){
        total += abs(header - req[i]); 
        header = req[i]; 
        i++;
        p--; 
    }

    printf("Total Head movements: %d\n", total);
    fclose(f);
}



void scan() {

    int header, total=0, prev, n=0, temp, i, p, init;
    int *req;
 
    FILE *f;
    if ((f = fopen("input.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
  
    while (!feof(f)){
        fscanf(f, "%d\n", &temp);
        n++;
    }
    rewind(f);

    i = 0;
    req = (int*)malloc(n * sizeof(int));
    while (!feof(f)){
        fscanf(f, "%d\n", req + i);
        i++;
    }

    printf("Enter current header position: ");
    scanf("%d", &header);

    for (i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (req[i] < req[j]){
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    for (int j=0; j<n; j++){
        if (req[j] <= header) {
            init = j;
        } else {
            break;
        } 
    }

    p = n;
    i = init+1;

    while (p > 0){
 
        while (i < n) {
            total += abs(header - req[i]); 
            header = req[i]; 
           i++;
            p--;
        }


        total += abs(header - 199);
        header = 199;
        i = init;

        while (i >= 0) {
            total += abs(header - req[i]); 
            header = req[i]; 
            i--;
            p--; 
        }    
   }

    printf("Total Head movements: %d\n", total);
    fclose(f);

}

void cscan(){

    int header, total=0, prev, n=0, temp, i, p, init;
    int *req;

    FILE *f;
    if ((f = fopen("input.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    while (!feof(f)){
        fscanf(f, "%d\n", &temp);
        n++;
    }

    rewind(f);

    i = 0;
    req = (int*)malloc(n * sizeof(int));
    while (!feof(f)){
        fscanf(f, "%d\n", req + i);
        i++;
    }


    printf("Enter current header position: ");
    scanf("%d", &header);

    for (i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (req[i] < req[j]){
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    for (int j=0; j<n; j++){
        if (req[j] <= header) {
            init = j;
        } else {
            break;
        } 
    }

    p = n;
    i = init+1;
    while (p > 0){
        while (i < n) {
            total += abs(header - req[i]);
            header = req[i];
            i++;
            p--;
        }
        total += abs(header - 199) + 199; 
        header = 0;
        i = 0;  

        while (i <= init) {
            total += abs(header - req[i]);
            header = req[i];
            i++;
            p--;
        }      
    }

    printf("Total Head movements: %d\n", total);
    fclose(f);
}

void main (){
    int flag=1, menu=4;
    while (flag){
        printf("-----------------Menu----------------\n1. FCFS\n2. SCAN\n3. C-SCAN\n4. Exit\nSelect:");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1: 
            printf("\n---------------FCFS disk Scheduling--------------------\n");
            fcfs();
            break;

        case 2: 
            printf("\n---------------SCAN disk Scheduling--------------------\n");
            scan();
            break;
        case 3: 
            printf("\n---------------C-SCAN disk Scheduling--------------------\n");
            cscan();
            break;
        case 4:
            flag=0;
            break;
        default:
            printf("Invalid Menu\n");
            break;
        }
    }
}