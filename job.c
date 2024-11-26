#include<stdio.h>
#define MAX 10
typedef struct Job
{
    char id[5];
    int deadline;
    int profit;
}Job;
void jobsquencingwithDeadline(Job jobs[],int n);
int minValue(int x, int y)
{
    if(x<y)
        return x;
    return y;
}
int main(void)
{
    int i,j;
    Job jobs[5]=
    {
        {"j1",2,60},
        {"j2",1,100},
        {"j3",3,20},
        {"j4", 2,40},
        {"j5",1,20},
    };
    Job temp;
    int n =5;
    for(i=1;i<n;i++)
    {
        for(j=0; j<n-i;j++)
        {
            if(jobs[j+1].profit> jobs[j].profit)
            {
                temp = jobs[j+1];
                jobs[j+1]=jobs[j];
                jobs[j] =temp;
            }
        }
    }
    printf("%10s %10s %10s\n","JOb","Deadline","profit");
    for(i=0;i<n;i++)
    {
        printf("%10s %10i %10i\n",jobs[i].id,jobs[i].deadline,jobs[i].profit);
    }
    jobsquencingwithDeadline(jobs,n);
    return 0;
}
void jobsquencingwithDeadline(Job jobs[],int n)
{
    int i,j,k,maxprofit;
    int timeslot[MAX];
    int filledTimeslot = 0;
    int dmax =0;
    for (i = 0; i < MAX; i++) {
        timeslot[i] = -1;
    }

    for(i=0;i<n;i++)
    {
        if(jobs[i].deadline >dmax)
            dmax=jobs[i].deadline;
    }
    printf("\ndmax : %d\n",dmax);
    for(i=1;i<=n;i++)
    {
        k= minValue(dmax,jobs[i-1].deadline);
        while(k>0)
        {
            if(timeslot[k]==-1)
            {
                timeslot[k] = i-1;
                filledTimeslot ++;
                break;
            }
            k--;
        }
        if(filledTimeslot==dmax)
            break;
    }
    printf("\n required jobs: ");
    for(i=1;i<=dmax;i++)
    {
        printf("%s",jobs[timeslot[i]].id);
        if(i<dmax)
        {
            printf("-->");
        }
    }
    maxprofit = 0;
    for(i=1;i<=dmax;i++)
        if (timeslot[i] != -1)
            maxprofit += jobs[timeslot[i]].profit;
    printf("max profit: %d\n",maxprofit);
}
