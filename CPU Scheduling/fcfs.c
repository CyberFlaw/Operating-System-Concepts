#include<stdio.h>  

void main()
{
	int n,b[10],t=0,i,w=0,r=0,a=0;
	float avg,avg1;

	printf("\nEnter number of processes:");
	scanf("%d",&n);
	
	printf("\nEnter the burst times : \n");
	for(i=1;i<=n;i++) 
	  scanf("%d",&b[i]);

	printf("\n Gantt chart ");
	for(i=1;i<=n;i++)
	  printf("P%d\t",i);

	printf("\n\nProcess BurstTime WaitingTime TurnaroundTime\n");
	for(i=1;i<=n;i++)
	{
		t=t+w;
		r=r+b[i];
		printf("P%d\t\t%d\t\t%d\t\t%d\t\t\n",i,b[i],w,r);
		w=w+b[i];
		a=a+r;
	}

	avg=(float)t/n;
	avg1=(float)a/n;

	printf("\n Average WaitingTime is %f",avg); 
	printf("\nAverage TurnaroundTime is %f\n",avg1);
}
