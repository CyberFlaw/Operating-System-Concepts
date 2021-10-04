#include <stdio.h>
 
int current[5][5], maximum_claim[5][5],remaining[5][5], available[5];
int allocation[5] = {0, 0, 0, 0, 0};
int maxres[5], safeArr[5], running[5], safe = 1;
int counter = 0, i, j, exec, resources, processes, k = 1, n = 0;
 
int main(){
	printf("Enter number of processes: ");
    	scanf("%d", &processes);
     	for (i = 0; i < processes; i++){
     	    running[i] = 1;
     	    counter++;
     	}
     	
     	printf("Enter number of resources: ");
     	scanf("%d", &resources);
     	printf("Enter Claim Vector:");
	for (i = 0; i < resources; i++){
		scanf("%d", &maxres[i]);
     	}
     	
   	printf("\nEnter Allocated Resource Table:\n");
	for (i = 0; i < processes; i++){
		for(j = 0; j < resources; j++){
			scanf("%d", &current[i][j]);
 		}
	}
	
     	printf("\nEnter Maximum Claim Table:\n");
     	for (i = 0; i < processes; i++){
        	for(j = 0; j < resources; j++){
        		scanf("%d", &maximum_claim[i][j]);
         	}
     	}
/*
	printf("\nThe Claim Vector is: ");
     	for (i = 0; i < resources; i++){
        	printf("\t%d", maxres[i]);
	}
     	printf("\nThe Allocated Resource Table:\n");
     	for (i = 0; i < processes; i++){
        	for (j = 0; j < resources; j++){
             		printf("\t%d", current[i][j]);
         	}
		printf("\n");
     	}
     	printf("\nThe Maximum Claim Table:\n");
     	for (i = 0; i < processes; i++){
        	for (j = 0; j < resources; j++){
        		printf("\t%d", maximum_claim[i][j]);
         	}	
         	printf("\n");
     	}
 */
	for (i = 0;i <processes; i++){
		for (j = 0; j < resources; j++){
			remaining[i][j] = maximum_claim[i][j] - current[i][j];
		}
	}
	
     	for (i = 0; i < processes; i++){
        	for (j = 0; j < resources; j++){
            		allocation[j] += current[i][j];
         	}
     	}
 /*
     	printf("\nAllocated resources:");
     	for (i = 0; i < resources; i++){
        	printf("\t%d", allocation[i]);
     	}
 */
     	for (i = 0; i < resources; i++){
        	available[i] = maxres[i] - allocation[i];
	}
 
     	printf("\nAvailable resources:");
     	for (i = 0; i < resources; i++){
        	 printf("\t%d", available[i]);
     	}
     	printf("\n");
 
     	while (counter != 0 && safe == 1){	
        	safe = 0;
         	for (i = n; i < processes; i++){
            		if (running[i]){
                		exec = 1;
                 		for (j = 0; j < resources; j++){
                  			if (remaining[i][j] > available[j]){
                         			exec = 0;
                        			break;
                     			}
                 		}
                 		if (exec){
					printf("\nProcess %d is executing..", i);
					if(n < processes-1){ n=i; n++;}
					else{ n=0;}
				     	running[i] = 0;
				     	safeArr[processes -counter] = i;
				    	counter--;
				    	safe = 1;
		 	
				    	for (j = 0; j < resources; j++){
				    		available[j] += current[i][j];
				    	}
                			break;
                 		}
            		}
       	}
        /*
         	if (!safe){
             		printf("\nThe processes are in unsafe state.\n");
             		break;
         	}
		else{
		     	printf("\nThe process is in safe state");
		     	printf("\nAvailable vector:");
	 
		     	for (i = 0; i < resources; i++){
		    		   printf("\t%d", available[i]);
		     	}
	 	
			printf("\n");
         	}
         	
         	
         */
     }
	if(counter == 0){
		printf("\n\nThe system is in a safe state!!\n");
            	printf("Safe Sequence : < ");
            	for( i = 0; i < processes; i++)
             	   printf("%d ", safeArr[i]);
            	printf(">\n");
     }else
            printf("\nThe system is in an unsafe state!!\n");
     
     return 0;
}
