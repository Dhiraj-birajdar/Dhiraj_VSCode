#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *n)
{
    printf("\n");
    for(;n;n=n->next)
        printf("%d,  ",n->data);
}
void reverse(struct node *n)
{
    struct node *n1=n->next;
    n->next=NULL;
    for(;n1->next;n)
}
int main()
{
    int i,n;
    struct node *head,*new,*temp;
    printf("\nEnter no of nodes : ");
    scanf("%d",&n);
    printf("\nEnter %d elements : ",n);
    for(i=0;i<n;i++)
    {
        new =(struct node*)malloc(sizeof(new));
        scanf("%d",&new->data);
        new->next=NULL;
        if (!head)
            head = new;
        else
        {
            for(temp=head;temp->next;temp=temp->next);
            temp->next=new;
        }
    }
    display(head);
    reverse(head);
}