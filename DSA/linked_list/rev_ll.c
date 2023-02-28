#include<stdio.h>
#include<stdlib.h>
#define newnode new=(node*)malloc(sizeof(node))
void display();
void reverse_ll();
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head=0,*temp,*new;
int main()
{
    int i;
    for(i=1;i<=10;i++)
    {
        newnode;
        new->data=i;
        new->next=0;
        if(!head)
            head=new;
        else
        {
            for(temp=head;temp->next;temp=temp->next);
            // for(temp=head;temp->next!=0;temp=temp->next);
            temp->next=new;
        }
    }
    printf("\nBefore reverse : \n");
    display(head);
    reverse_ll(head);
    printf("\nAfter reverse : \n");
    display(head);
}
void reverse_ll(node *head)
{
    node *pre,*nxt,*cur;
    // for(pre=0,cur=nxt=head;nxt!=0;nxt=cur->next,cur->next=pre,pre=cur,cur=nxt);
    // head=pre;

    pre=0,cur=nxt=head;
    while(nxt!=0)
    {
        nxt=cur->next;
        cur->next=pre;
        pre=cur,cur=nxt;
    }
    head=pre;
}

void display(node *head)
{
    node *temp;
    // for(c=0,temp=head;temp!=0;temp=temp->next,c++)
    for(temp=head;temp;temp=temp->next)
        printf("data : %.2d\n",temp->data);
    // printf("list length : %d\n",c);
}

// <= >= === != -> <- 