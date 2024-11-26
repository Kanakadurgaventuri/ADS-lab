#include<stdio.h>
#include<string.h>
int findmax(int n1, int n2)
{
    if (n1 >n2)
        return n1;
    else
        return n2;
}
int knapsack(int W, int wt[],int val[],int n)
{
    int f[n+1][W+1];
    int i,j;
    for(i =0;i<=n;i++)
    {
        for( j =0 ;j<=W;j++)
        {
            if(i==0 || j ==0)
            {
                f[i][j] =0;
            }
            else if(wt[i-1] <=j)
            {
                f[i][j] = findmax(f[i-1][j] ,val[i-1]+ f[i-1][j-wt[i-1]]);
            }
            else
                f[i][j] =f[i-1][j];
        }
    }
    return f[n][W];
}
int main()
{
    int val[5] ={70,20,50};
    int wt[5] = {11,12,13};
    int W =30;
    int len = sizeof(val)/sizeof(val[0]);
    printf("max profit : %d",knapsack(W,wt,val,len));
    return 0;
}
