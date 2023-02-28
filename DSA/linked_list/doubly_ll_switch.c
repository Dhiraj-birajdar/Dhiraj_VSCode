#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *prev, *next;
} node;
node *start = NULL, *temp, *new;
int ncount;
void display();
void newnode();
void create_list();
void add_first();
void add_last();
void add_at_pos();
void add_after();
void add_before();
void del_first();
void del_last();
void del_info();
void del_at_pos();
void search();
int main()
{
    int ch;
    printf("|==============>>>    DOUBLY LINKED LIST MENU DRIVEN PROGRAM    <<<==============|\n");
    while (1)
    {
        printf("\n1. Create list\n2. Add node at first position\n3. Add node at last position\n4. Add node at given position\n5. Add node after given data\n6. Add node before given data\n7. Delete first node\n8. Delete last node\n9. Delete given data\n10. Delete node at given position\n11. Search data\n12. Display list\n13. Exit\n\n??---> Select operation : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_list();
            break;
        case 2:
            add_first();
            break;
        case 3:
            add_last();
            break;
        case 4:
            add_at_pos();
            break;
        case 5:
            add_after();
            break;
        case 6:
            add_before();
            break;
        case 7:
            del_first();
            break;
        case 8:
            del_last();
            break;
        case 9:
            del_info();
            break;
        case 10:
            del_at_pos();
            break;
        case 11:
            search();
            break;
        case 12:
            display();
            break;
        case 13:
            printf("\n<<=====/*/=====>> DHIRAJ BIRAJDAR <<=====/*/=====>>");
            exit(0);
        default:
            printf("\n!!!!--> Error < Enter valid option >\n");
        }
        display();
    }
    return 0;
}
void display()
{
    printf("\n--------------------------------------------------\n                   Linked list             \n--------------------------------------------------");
    for (temp = start, ncount = 0; temp; temp = temp->next, ncount++)
        printf("\n| %p    | %.2d |    %p |", temp->prev, temp->info, temp->next);
    printf("\n--------------------------------------------------");
    printf("\n         List length  :  [ %d ] nodes\n", ncount);
    printf("--------------------------------------------------\n");
}
void newnode()
{
    new = (node *)malloc(sizeof(node));
    printf("\nEnter data in newnode : ");
    scanf("%d", &new->info);
    new->prev = new->next = NULL;
}
void create_list()
{
    int i;
    for (i = 1; i <= 10; i++)
    {
        new = (node *)malloc(sizeof(node));
        new->info = i * 2;
        new->next = new->prev = NULL;
        if (start == 0)
            start = new;
        else
        {
            for (temp = start; temp->next; temp = temp->next);
            temp->next = new;
            new->prev = temp;
        }
    }

    // int i, n;
    // printf("\nHow many nodes you wish to create : ");
    // scanf("%d", &n);
    // new = (node *)malloc(sizeof(node));
    // printf("\nEnter %d elements : ", n);
    // scanf("%d", &new->info);
    // new->prev = new->next = NULL;
    // start = new;
    // for (i = 1, temp = start; i < n; i++, temp = temp->next)
    // {
    //     new = (node *)malloc(sizeof(node));
    //     scanf("%d", &new->info);
    //     new->prev = temp;
    //     temp->next = new;
    // }
    // display();
}
void add_first()
{
    newnode();
    if (!start)
        start = new;
    else
    {
        start->prev = new;
        new->next = start;
        start = new;
    }
}
void add_last()
{
    newnode();
    if (!start)
        start = new;
    else
    {
        for (temp = start; temp->next; temp = temp->next);
        temp->next = new;
        new->prev = temp;
    }
}
void add_at_pos()
{
    int p, i;
    printf("\n????--> Enter position : ");
    scanf("%d", &p);
    newnode();
    if (!start)
        start = new;
    else if (p == 1)
    {
        start->prev = new;
        new->next = start;
        start = new;
    }
    else
    {
        for (i = 1, temp = start; i < p-1; i++, temp = temp->next);
        new->next = temp->next;
        new->prev = temp;
        temp->next->prev = new;
        temp->next = new;
    }
}
void add_after()
{
    int data;
    newnode();
    printf("\n????--> Enter data after which node to be added : ");
    scanf("%d", &data);
    if (!start)
        printf("\n!!!!--> Error < List is empty >\n");
    else
    {
        for (temp = start; temp; temp = temp->next)
        {
            if (temp->info == data)
            {
                if (!temp->next)
                {
                    new->prev = temp;
                    temp->next = new;
                    return;
                }
                new->next = temp->next;
                new->prev = temp;
                temp->next->prev = new;
                temp->next = new;
                return;
            }
        }
        printf("\n=======>>> %d not found in list", data);
    }
}
void add_before()
{
    int data;
    newnode();
    printf("\n????--> Enter data before which node to be added : ");
    scanf("%d", &data);
    if (!start)
        printf("\n!!!!--> Error < List is empty >\n");
    else if (start->info == data)
    {
        new->next = start;
        start->prev = new;
        start = new;
    }
    else
    {
        for (temp = start->next; temp; temp = temp->next)
        {
            if (temp->info == data)
            {
                new->next = temp;
                new->prev = temp->prev;
                temp->prev->next = new;
                temp->prev = new;
                return;
            }
        }
        printf("\n=======>>> %d not found in list", data);
    }
}
void del_first()
{
    if (!start)
        printf("\n!!!!-> Error < List is empty >\n");
    else if (!start->next)
        free(start);
    else
    {
        start = start->next;
        free(start->prev);
    }
}
void del_last()
{
    if (!start)
        printf("\n!!!!--> Error < List is empty >\n");
    else if (!start->next)
        free(start);
    else
    {
        for (temp = start; temp->next; temp = temp->next);
        temp->prev->next = NULL;
        free(temp);
    }
}
void del_info()
{
    int data;
    printf("\n????--> Enter data to be deleted : ");
    scanf("%d", &data);
    if (!start)
        printf("\n!!!!--> Error < List is empty >\n");
    else if (start->info == data)
    {
        start = start->next;
        free(start->prev);
    }
    else
    {
        for (temp = start->next; temp; temp = temp->next)
        {
            if (temp->info == data)
            {
                if (!temp->next)
                {
                    temp->prev->next = NULL;
                    free(temp);
                    return;
                }
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(temp);
                return;
            }
        }
    }
}
void del_at_pos()
{
    int p, i;
    printf("\n????--> Enter position to be deleted : ");
    scanf("%d", &p);
    if (!start)
        printf("\n!!!!--> Error < List is empty >\n");
    else if(!start->next)
        free(start);
    else if (p == 1)
    {
        start = start->next;
        free(start->prev);
    }
    else
    {
        for (i = 2, temp = start->next;  (i < p); temp = temp->next,i++);
        if (!temp->next)
        {
            temp->prev->next = NULL;
            free(temp);
            return;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
    }
}
void search()
{
    int s, i;
    printf("\n????--> Enter data to search : ");
    scanf("%d", &s);
    for (i = 1, temp = start; temp; temp = temp->next, i++)
    {
        if (s == temp->info)
        {
            printf("\n=======>>> %d found at node %d & address %p\n", s, i, temp);
            return;
        }
    }
    printf("\n=======>>> %d not found in list\n", s);
}