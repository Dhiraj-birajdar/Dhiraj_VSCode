#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
 node *head = NULL,*temp, *ptr, *end;
void display();
void bubblesort();
int main()
{
    int n, i;
    printf("\nEnter the number of elements to be inserted : ");
    scanf("%d", &n);
    printf("\nEnter %d Elements : ", n);
    for (i = 0; i < n; i++)
    {
        ptr = (node *)malloc(sizeof(node));
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        if (!head)
            head = ptr;
        else
        {
            for (temp = head; temp->next != NULL; temp = temp->next);
            temp->next = ptr;
        }
    }
    printf("\nUnsorted linked list : ");
    display();
    bubblesort();
    printf("\nSorted linked list : ");
    display();
}
void bubblesort()
{
    int t;
    for (end = NULL; head->next != end; end = temp)
    {
        for (temp = head; temp->next != end; temp = temp->next)
        {
            ptr = temp->next;
            if (temp->data > ptr->data)
            {
                t = temp->data;
                temp->data = ptr->data;
                ptr->data = t;
            }
        }
    }
}
void display()
{
    node *temp;
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d   ", temp->data);
}