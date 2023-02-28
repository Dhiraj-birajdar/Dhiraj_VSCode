#include <stdio.h>
#include <stdlib.h>
#define newnode new = (node *)malloc(sizeof(node))

void display();
void delete_first();
void delete_last();
void delete_pos(int pos);

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = 0, *temp, *new;
int c, i;

int main()
{
    node *new;
    int ch, pos;
    for (i = 1; i <= 10; i++)
    {
        newnode;
        new->data = i;
        new->next = 0;
        if (!head)
            head = new;
        else
        {
            for (temp = head; temp->next; temp = temp->next)
                ;
            // for(temp=head;temp->next!=0;temp=temp->next);
            temp->next = new;
        }
    }
    display();

    do
    {
        printf("\n1.delete first\n2.delte last\n3.enter position\n4.exit\nenter choice : ");
        scanf("%d", &pos);
        switch (pos)
        {
        case 1:
            delete_first();
            break;
        case 2:
            delete_last();
            break;
        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            if (pos > 1 && pos <= c)
                delete_pos(pos);
            else
                printf("\nError -> enter position between 2 to %d\n", c);
            break;
        case 4:
            printf(" :) :) :) :) :) :)");
            exit(1);
        default:
            printf("\nError -> invalid choice\n");
        }
    } while (1);
    return 0;
}
void delete_pos(int pos)
{
    node *pre;
    for (pre = temp = head, i = 1; i != pos; i++, pre = temp, temp = temp->next)
        ;
    printf("pre data : %d    temp data : %d\n", pre->data, temp->data);
    pre->next = temp->next;
    free(temp);
    display();
}

void display()
{
    // for(c=0,temp=head;temp!=0;temp=temp->next,c++)
    for (c = 0, temp = head; temp; temp = temp->next, c++)
        printf("data : %.2d    address : %p\n", temp->data, temp->next);
    printf("list length : %d\n", c);
}

void delete_first()
{
    if (!head)
        printf("list is empty");
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    display();
}

void delete_last()
{
    if (!head)
        printf("list is empty");
    else
    {
        for (temp = head; temp->next->next; temp = temp->next);
        free(temp->next);
        temp->next = 0;
    }
    display();
}
