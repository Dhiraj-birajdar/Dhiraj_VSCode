#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head=NULL;
void even_display(struct node *ptr)
{
    printf("Even elements in single linked list are : ");
    for(;ptr->next != NULL;ptr = ptr->next)
        if(ptr->data%2==0)
            printf("\t%d",ptr->data);
}
int main()
{
    node *temp,*new;
    int i=10;
    while(i)
    {
        new =( node* ) malloc(sizeof(node));
        new->next=NULL;
        new->data=i;
        if(head==NULL)
            head = new;
        else
        {
            for(temp=head;temp->next!=NULL;temp=temp->next);
            temp->next=new;
        }
        i--;
    }
    even_display(head);
    return 0;
}