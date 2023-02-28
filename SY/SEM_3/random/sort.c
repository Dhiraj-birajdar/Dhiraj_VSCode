#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dhiraj.h"
int main(int argc[],char *argv[])
{

    int i, j, c = 0, t, l1[] = {7, 0, 2, 0, 9, 6, 6, 1, 3, 4}, l[10];
    // int l2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},l1[]=l;

    printf("%s\n",argv[0]);
    printf("%d\n",argc);

    srand(time(0));
    // int ti=time(0);
    // printf("%d\n",ti);
    for ( i = 0; i < 10; i++)
        l[i]=rand()%100;
    int f=fact(5);
    printf("%d",f);
    for (i = 0; i < 10; i++)
        l1[i] = l[i];

    for (i = 1; i < 10; i++)
    {
        for (j = i; j < 10; j++)
        {
            if (l[c] >= l[j])
            {
                t = l[c];
                l[c] = l[j];
                l[j] = t;
            }
        }
        c = i,j = i + 1;
    }
    printf("\n\n**************** FINAL ************\n");
    printf("Before\t\tAfter\n\n");
    for (i = 0; i < 10; i++)
        printf("l[%d]:%d\t\tl[%d]:%d\n", i, l1[i], i, l[i]);
}