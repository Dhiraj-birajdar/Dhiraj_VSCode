#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
} *top = NULL,*temp;
void push(int n);
void pop();
int peek();
int isempty();
int main()
{
    int ch, n;
    while (1)
    {
        printf("\n\n1.push\n2.pop\n3.peek\n4.is empty\n5.exit\n\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter data to push : ");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (isempty())
                printf("\nStack is empty");
            else
                printf("\nTop element is : %d", peek());
            break;
        case 4:
            if (isempty())
                printf("\nStack is empty");
            else
                printf("\nStack is not empty");
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
}
void push(int n)
{
        temp = (struct stack *)malloc(sizeof(temp));
        temp->data = n;
        temp->next = top;
        top = temp;
        printf("\n%d pushed successfully ",n);
}
void pop()
{
    if (isempty())
        printf("\nStack is empty");
    else
    {
        temp=top;
        top=top->next;
        printf("\n%d pop successfully ",temp->data);
        free(temp);
    }
}
int peek()
{
    if (isempty())
    {
        printf("\nStack is empty");
        return 0;
    }
    else
        return top->data;
}
int isempty()
{
    if(!top)
        return 1;
    else
        return 0;
}
