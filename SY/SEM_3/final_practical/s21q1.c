#include <stdio.h>
#include <string.h>
#include "cststack.h"
main()
{
    STACK s;
    char string[MAX];
    int i;
    initstack(&s);
    printf("\nEnter string of character : ");
    gets(string);
    for (i = 0; string[i] != '\0'; i++)
    {
        if (isfull(&s))
            printf("\nStack is full");
        else
            push(&s, string[i]);
    }
    printf("\nReversed string of character : ");
    while (!isempty(&s))
        printf("%c", pop(&s));
}