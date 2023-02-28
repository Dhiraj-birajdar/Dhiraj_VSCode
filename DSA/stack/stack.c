#include <stdio.h>

void main()
{
    int a[5], sp = -1, i, ch, data;
    while (1)
    {
        printf("\n1. push\n2. pop\n3.exit\n\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (sp == 4)
                printf("\nStack is full\n");
            else
            {
                printf("\nEnter data to push : ");
                scanf("%d", &data);
                // sp++;
                a[++sp] = data;
            }
            break;
        case 2:
            if (sp == -1)
                printf("\nStack is empty\n");
            else
                printf("\ntop data is %d", a[sp--]);
                // printf("\ntop data is %d", a[sp]),sp--;
            break;
        case 3:
            exit(1);
        default:
            printf("\nEnter valid choice");
        }
    }
}