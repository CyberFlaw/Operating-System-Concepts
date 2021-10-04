#include<stdio.h>

int findLRU(int time[],int n)
{
    int i,min=time[0],pos=0;
    
    for(i=1;i<n;i++) {
        if(time[i]<min) {
            min=time[i];
            pos=i;
        }
    }
    return pos;
}

void main()
{
    int i,j, n,f,fr[20],p[50],count=0,time[10],flag1,flag2,pos,faults=0;

    printf("Enter the number of pages : ");
    scanf("%d",&n);

    printf("Enter the reference string : ");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);

    printf("Enter the frame number : ");
    scanf("%d",&f);

    for(i=0;i<f;i++)
        fr[i]=-1;

    printf("\nPages\t\tFrames\n\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t",p[i]);
        flag1=flag2=0;

        for(j=0;j<f;j++) {
            if(fr[j]==p[i]) {
                count++;
                time[j]=count;
                flag1=flag2=1;
                break;
            }
        }
        
        if(flag1==0) {
            for(j=0;j<f;j++) {
                if(fr[j]==-1) {
                    count++;
                    faults++;
                    fr[j]=p[i];
                    time[j]=count;
                    flag2=1;
                    break;
                }
            }
        }

        if(flag2==0) {
            pos=findLRU(time,f);
            count++;
            faults++;
            fr[pos]=p[i];
            time[pos]=count;
        }

        for(j=0;j<f;j++)
            printf("%d\t",fr[j]);
        printf("\n");
    }
    printf("\n\nTotal Page Faults : %d\n", faults);

}
