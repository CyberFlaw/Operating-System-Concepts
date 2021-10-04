#include<stdio.h>

void main()
{
    int f,n,faults=0,p[25],fr[10],ar[25],time[25],i,j,k,flag,min,temp;

    printf("Enter the number of pages : ");
    scanf("%d",&n);

    printf("Enter the reference string : ");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);

    printf("Enter the frame number : ");
    scanf("%d",&f);

    for(i=0;i<f;i++)
        fr[i]=-1;
    for(i=0;i<25;i++)
        ar[i]=-1;
        
    printf("\nPages\t\tFrames\n\n");;
    for(i=0;i<n;i++)
    {
        printf("%d\t\t",p[i]);

        ar[p[i]]++;
        time[p[i]]=i;
        flag=1;
        k=fr[0];

        for(j=0;j<f;j++) {

            if(fr[j]==-1||fr[j]==p[i]) {
                if(fr[j]!=-1)
                    faults++;
                flag=0;
                fr[j]=p[i];
                break;
            }
            if(ar[k]>ar[fr[j]])
                k=fr[j];
        }
        
        if(flag) {
            min=25;
            for(j=0;j<f;j++) {
                if(ar[fr[j]]==ar[k] && time[fr[j]]<min) {
                    temp=j;
                    min=time[fr[j]];
                }
            }
            ar[fr[temp]]=0;
            fr[temp]=p[i];
        }

        for(j=0;j<f;j++)
            printf("%d\t",fr[j]);
        printf("\n");
    }

    printf("\n\nNumber of page fault : %d\n",faults);
}