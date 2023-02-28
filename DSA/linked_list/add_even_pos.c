#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
};



void even_pos_addition(struct node *ptr)
{
    int i, sum = 0;
    for (i = 1; ptr != NULL; ptr = ptr->next, i++)
        if (i % 2 == 0)
            sum += ptr->data;
    printf("%d", sum);
}



int main()
{
    int i;
    struct node *h, *n, *p;
    h = (struct node *)malloc(sizeof(h));
    h->next = NULL;
    h->data = 1;
    for (i = 2; i < 6;  i++)
    {
        n = (struct node *)malloc(sizeof(n));
        n->next = h;
        n->data = i;
        h=n;
    }
 
    for (p = h; p != NULL; p = p->next)
        printf("%d    ", p->data);
    printf("\n");
    even_pos_addition(h);
}