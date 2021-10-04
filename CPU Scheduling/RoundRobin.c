#include<stdio.h>
void main()
{
	int i,tbt=0,nop,ts=0,flag[20], rem[20];
	int from,wt[20],tt[20],b[20], twt=0,ttt=0;
	int dur;
	float awt,att;

	printf("Enter no. of Processes: ");
	scanf("%d",&nop);
	printf("Enter the time slice: ");
	scanf("%d",&ts);
	printf("Enter the Burst times..\n");
	for(i=0;i<nop;i++) {
		wt[i]=tt[i]=0;
		printf("P%d\t: ",i+1);
		scanf("%d",&b[i]);
		rem[i]=b[i];
		tbt+=b[i];
		flag[i]=0;
	}

	from=0;
	i=0;
	printf("\n\t Gantt Chart");
	printf("\n ProcessID\tFrom Time\tTo Time\n");

	while(from<tbt)
	{
	  if(!flag[i])
	  {
	    if(rem[i]<=ts) {
            dur=rem[i];
            flag[i]=1;
            tt[i]=dur+from;
            wt[i]=tt[i]-b[i];
	    } else {
            dur=ts;
            printf("%7d%15d%15d\n",i+1, from,from+dur);
            rem[i] -= dur;
            from += dur;
        }
	  }
	 i=(i+1)%nop;
	}
	
	for(i=0;i<nop;i++) {
		twt+=wt[i];
		ttt+=tt[i];
	}

	printf("\n\n Process ID \t Waiting Time \t Turn Around Time");
	for(i=0;i<nop;i++)
		printf("\n\t%d\t\t%d\t\t%d",i+1,wt[i],tt[i]);
	
	awt=(float)twt/(float)nop;
	att=(float)ttt/(float)nop;
    
	printf("\nTotal Waiting Time:%d",twt);
	printf("\nTotal Turn Around Time:%d",ttt);
	printf("\nAverage Waiting Time:%.2f",awt);
	printf("\nAverage Turn Around Time:%.2f\n",att);
}
