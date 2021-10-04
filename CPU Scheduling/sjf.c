#include<stdio.h>

void main()
{
	int n,w[100],tot[100],i,j,awt,atot; float avwt,avtot;
	struct{
	int p,bt; }
	sjf[10],temp;
    
	printf("Enter the number of Processes:"); scanf("%d",&n);
	for(i=1;i<=n;i++) {
		printf("Enter the Burst time for Process%d : ",i); scanf("%d",&sjf[i].bt);
		sjf[i].p=i;
	}

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(sjf[j].bt>sjf[i].bt) {
			  temp=sjf[i];
			  sjf[i]=sjf[j];
			  sjf[j]=temp;
			}

	w[1]=0;
	tot[1]=sjf[1].bt;
	for(i=2;i<=n;i++) 
	  tot[i]=tot[i-1]+sjf[i].bt;

	awt=0;
	atot=0;

	for(i=1;i<=n;i++) {
	  w[i]=tot[i]-sjf[i].bt; awt+=w[i]; atot+=tot[i];
	}
	avwt=(float)awt/n;
	avtot=(float)atot/n;

	printf("\nProcessId\tWaiting time\t TurnaroundTime");
	for(i=1;i<=n;i++)
	  printf("\n\t%d\t\t%d\t\t%d",sjf[i].p,w[i],tot[i]);

	printf("\n\nTotal Waiting Time :%d",awt);
	printf("\nTotal Turnaround Time :%d",atot);
	printf("\nAverage Waiting Time :%.2f",avwt);
	printf("\nAverage Turnaround Time :%.2f\n",avtot); 

}	
