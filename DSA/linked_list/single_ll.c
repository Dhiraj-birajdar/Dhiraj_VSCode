/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node
{
    int no;
    struct node *next;
}node;
void main()
{
    node *head=0,*new,*temp;
    int c,count=0,i,n=10;
    // do
    // {
    //     new=(node*)malloc(sizeof(node));
    //     printf("Enter no : ");
    //     scanf("%d",&new->no);
    //     new->next=0;
    //     if(head==0)
    //         head=temp=new;
    //     else
    //     {
    //         temp->next=new;
    //         temp=new;
    //     }
    //     printf("\nDo you want to continue (0,1) : ");
    //     scanf("%d",&c);
    // }while(c);
    // srand(time(0));
    printf("How many no : ");
    scanf("%d",&n);
    printf("\nEnter %d no : ",n);
    for(i=0;i<n;i++)
    {
        new=(node*)malloc(sizeof(node));
        // new->no=rand()%100;
        scanf("%d",&new->no);
        new->next=0;
        if(head==0)
            head=temp=new;
        else
        {
            temp->next=new;
            temp=new;
        }
    }
    temp=head;
    printf("\nLnked list elements : ");
    while (temp!=0)
    {
        printf("%d  ",temp->no);
        temp=temp->next;
        count++;
    }
    printf("\nlinked List length : %d nodes",count);
    
}
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void main()
{
    node *h=0,*t,*n;
    char c;
    do
    {
        n=(node*)malloc(sizeof(node));
        printf("Enter data : ");
        scanf("%d",&n->data);
        n->next=0;
        if(h==0)
            h=t=n;
        else
        {
            t->next=n;
            t=n;
        }
        fflush(stdin);
        printf("continue (y/n) : ");
        scanf("\n%c",&c);
    } while (c=='y'||c=='Y');
    t=h;
    while(t)
    {
        printf("%d  ",t->data);
        t=t->next;
    }
}