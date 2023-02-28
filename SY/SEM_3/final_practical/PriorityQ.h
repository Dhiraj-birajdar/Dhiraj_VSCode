#include<stdio.h>
typedef struct pq
{
    int data;
    int pri;
}pque;
int f,r;
void init()
{
    f=r=-1;
}
int isempty()
{
    if(r==-1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if(r==19)
        return 1;
    else
        return 0;
}
void addtoq(pque *q,int ele,int pri)
{
    if(isempty())
    {
        f=r=0;
        q[r].data=ele;
        q[r].pri=pri;
    }
    else
    {
        ++r;
        q[r].data=ele;
        q[r].pri=pri;
    }
}
void display(pque *q)
{
    int i;
    for(i=f;i<=r;i++)
        printf("\nelement : %d    priority : %d",q[i].data,q[i].pri);
}
void dqueue(pque *q)
{
    int i,t=f;
    for(i=f+1;i<=r;i++)
    {
        if(q[i].pri>q[t].pri)
            t=i;
    }
    if(t==r)
        r--;
    else
    {
        for(i=t;i<=r;i++)
        {
            q[i]=q[i+1];
        }
        r--;
    }
}