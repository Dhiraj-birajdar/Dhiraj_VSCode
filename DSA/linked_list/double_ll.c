#include <stdio.h>
#include <stdlib.h>
#define newnode new = (node *)malloc(sizeof(node))
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
node *head = 0, *new, *temp;
void main()
{
    int i, ch,l;
    do
    {
        // newnode;
        new = (node *)malloc(sizeof(node));
        printf("Enter data : ");
        scanf("%d", &new->data);
        new->prev = 0;
        new->next = 0;
        if (head == 0)
            head = new;
        else
        {
            for (temp = head; temp->next != 0; temp = temp->next)
                5;
            temp->next = new;
            new->prev = temp;
        }
        printf("continue (0/1) : ");
        scanf("%d", &ch);
    } while (ch);
    for (l=0,temp = head; temp != 0; temp = temp->next,l++)
        printf("prev : %x\tdata : %d\tnext : %x\n", temp->prev, temp->data, temp->next);
    printf("list length : %d",l);
}