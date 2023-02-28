#include <stdio.h>
#include <stdlib.h>
typedef struct employee
{
    char ename[20];
    int age;
} emp;
int readfile(emp *);
void selectionsort(emp *, int);
void display(emp *, int);
main()
{
    int n;
    emp a[100];
    n = readfile(a);
    printf("\nData Before Sorting: \n");
    display(a, n);
    selectionsort(a, n);
    printf("\n\nData After Sorting: \n");
    display(a, n);
}
int readfile(emp *a)
{
    char fname[20];
    int i;
    FILE *fp;
    printf("Enter file name: ");
    scanf("%s", fname);
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("Error in opening File");
        exit(0);
    }
    for (i = 0; !feof(fp); i++)
        fscanf(fp, " %s %d", a[i].ename, &a[i].age);
    return i - 1;
}
void selectionsort(emp *a, int n)
{
    int i, j;
    emp temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(a[i].ename, a[j].ename) > 0)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void display(emp *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("\n%s %d", a[i].ename, a[i].age);
}