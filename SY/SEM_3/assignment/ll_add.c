#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
} *start = NULL;
void add_first();
void add_last();
void add_after(int no);
void add_before(int no);
void add_at_pos(int pos);
void display();
//------------------main--------------*************************
void main()
{
    printf("\n----/*/---- Program written by DHIRAJ BIRAJDAR ----/*/----\n");
    struct node *ptr, *temp;
    int i, pos, ch, no;
    for (i = 1; i <= 5; i++)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = i * 2;
        ptr->link = 0;
        if (start == NULL)
            start = temp = ptr;
        else
        {
            while (temp->link)
                temp = temp->link;
            temp->link = ptr;
        }
    }
    display();

    while (1)
    {
        printf("\n1.add first\n2.add last\n3.add at position\n4.add before\n5.add after\n6.exit\n\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add_first();
            break;
        case 2:
            add_last();
            break;
        case 3:
            printf("\nenter position : ");
            scanf("%d", &no);
            add_at_pos(no);
            break;
        case 4:
            printf("\nenter no : ");
            scanf("%d", &no);
            add_before(no);
            break;
        case 5:
            printf("\nenter no : ");
            scanf("%d", &no);
            add_after(no);
            break;
        case 6:
            printf("\n----/*/---- Program written by DHIRAJ BIRAJDAR ----/*/----");
            exit(1);
        default:
            printf("\nError -> invalid choice\n");
        }
        display();
    }
}
//-----------add first---------------
void add_first()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &ptr->info);
    ptr->link = start;
    start = ptr;
}
//-----------add at pos---------------**************************
void add_at_pos(int pos)
{
    struct node *ptr, *temp;
    int i;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &ptr->info);
    ptr->link = 0;
    if (pos == 1)
    {
        ptr->link = start;
        start = ptr;
    }
    else
    {
        // for (i = 2, temp = start; i < pos; i++, temp = temp->link);
        for (i = 1, temp = start; i < pos-1; i++, temp = temp->link);
        ptr->link = temp->link;
        temp->link = ptr;
    }
}
//-----------add last---------------******************************
void add_last()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &ptr->info);
    ptr->link = 0;
    for (temp = start; temp->link; temp = temp->link)
        ;
    temp->link = ptr;
}
//-----------add after---------------*******************************
void add_after(int no)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &ptr->info);
    ptr->link = 0;
    for (temp = start; temp; temp = temp->link)
        if (no == temp->info)
        {
            ptr->link = temp->link;
            temp->link = ptr;
            return;
        }
    printf("%d is not present in list.", no);
}
//-----------add before---------------***************************
void add_before(int no)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &ptr->info);
    ptr->link = 0;
    if (no == start->info)
    {
        ptr->link = start;
        start = ptr;
    }
    else
    {
        for (temp = start; temp->link!=NULL; temp = temp->link)
            if (temp->link->info == no)
            {
                ptr->link = temp->link;
                temp->link = ptr;
                return;
            }
    }
    printf("%d is not present in list.", no);
}
//-----------display---------------******************************
void display()
{
    int c;
    struct node *temp;
    printf("\nList elements :  ");
    for (c = 0, temp = start; temp != 0; c++, temp = temp->link)
        printf("%d  ", temp->info);
    printf("\nList length : %d\n", c);
}