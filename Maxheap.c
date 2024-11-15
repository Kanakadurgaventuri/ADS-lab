#include<stdio.h>
#include<stdlib.h>
void build_heap();
void insert();
void deletemin();
void display();
void percolate_up(int m);
void percolate_down(int m);
int ch,i,heap[50],n,k,left,right,target,temp,parent;
int main()
{
    printf("\nHeap Operations");
    printf("\n1.Build Heap\n2.Insert\n3.Delete Min\n4.Display\n5.Exit");
    do
    {
        printf("\nChoose Operation: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:build_heap();
            display();
            break;
            case 2:insert();
            break;
            case 3:deletemin();
            break;
            case 4:display();
            break;

        }
    }while(ch!=0);
}
void build_heap()
{
    printf("Enter No of elements in heap: ",n);
    scanf("%d",&n);
    printf("\nEnter %d elements:\n",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&heap[i]);
    }
    for(i=n/2;i>0;i--)
    {
        percolate_down(i);
    }
}
void insert()
{
    printf("Enter Element: ");
    scanf("%d",&temp);
    n++;
    heap[n]=temp;
    printf("\nElement Inserted!!");
    percolate_up(n);
}
void deletemin()
{
    if(n>0)
    {
        printf("\nElement Deleted Is: %d",heap[i]);
        heap[i]=heap[n];
        heap[n]=0;
        n--;
        percolate_down(i);
    }
    else
    {
        printf("\n Heap is Empty");
    }
}
void display()
{
    if(n>0)
    {
        printf("\nThe Max-Heap is:\n");
        i=1;
        while(i<=n)
        {
            for(k=i;k<(2*i)&&k<=n;k++)
            {
                printf("\t%d\t",heap[k]);
            }
            printf("\n");
            i=k;
        }
    }
    else
    {
        printf("\nHeap is Empty");
    }
}
void percolate_up(int m)
{
    while(m>1)
    {
        parent=m/2;
        if(heap[parent]<heap[m])
        {
            temp=heap[m];
            heap[m]=heap[parent];
            heap[parent]=temp;
            m=parent;
        }
        else break;
    }
}
void percolate_down(int m)
{
    while((2*m)<=n)
    {
        left=2*m;
        right=2*m+1;
        if(right<=n && heap[right]<heap[left])
        {
            target=right;
        }
        else
        {
            target=left;
        }
        if(heap[target]>heap[m])
        {
            temp=heap[m];
            heap[m]=heap[target];
            heap[target]=temp;
            m=target;
        }
        else break;
    }
}


