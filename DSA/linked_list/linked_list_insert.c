#include<stdio.h>
#include<stdlib.h>
#define newnode new=(node*)malloc(sizeof(node))

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head=0,*new,*temp;
int i,pos,c;

void insert_first();
void insert_pos();
void insert_last();
void display();
void get_data();

void main()
{
    char ch;
    for(i=1;i<=5;i++)
    {
        newnode;
        new->data=i*2;
        new->next=0;
        if(head==0)
            head=temp=new;
        else
        {
            while(temp->next)
                temp=temp->next;
            temp->next=new;
        }
    }
    
    display();
    do
    {
        printf("\n1.first\n0. last\nposition\nEnter position : ");
        scanf("%d",&pos);
        if(pos==1)
            insert_first();
        else if(pos==0)
            insert_last();
        else if(pos>c||pos<0)
            printf("\ninvalid position\n");
        else
            insert_pos();
        fflush(stdin);
        printf("Do you want to continue (y/n) : ");
        scanf("\n%c",&ch);
    } while (ch=='y'||ch=='Y');
    display();
}

void insert_first()
{
    get_data();
    temp=head;
    head=new;
    new->next=temp;
}

void insert_pos()
{
    get_data();
    for(i=2,temp=head;i<pos;i++,temp=temp->next);
    new->next=temp->next;
    temp->next=new;
}

void insert_last()
{
    get_data();
    for(temp=head;temp->next!=0;temp=temp->next);
    temp->next=new;
}

void get_data()
{
    newnode;
    printf("Enter data : ");
    scanf("%d",&new->data);
    new->next=0;
}

void display()
{
    printf("\nList elements :  ");
    for(c=0,temp=head;temp!=0;c++,temp=temp->next)
        printf("%d  ",temp->data);
    printf("\nList length : %d\n",c);
}
