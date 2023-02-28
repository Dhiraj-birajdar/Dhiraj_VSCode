// selection sort on name
#include <stdio.h>
#include <stdlib.h>
typedef struct employee
{
    char ename[20];
    int age;
}emp;
int readfile(emp *);
void selectionsort(emp *, int);
void display(emp *, int);
main()
{
    int n;
    emp a[100];
    n = readfile(a);
    display(a, n);
    selectionsort(a, n);
    printf("\nData After Sorting: ");
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
    for(i=0;!feof(fp);i++)
        fscanf(fp, " %s %d", a[i].ename, &a[i].age);
    return i - 1;
}
void selectionsort(emp *a, int n)
{
    int pass, key, i;
    emp temp;
    for (pass = 0; pass < n - 1; pass++)
    {
        key = pass;
        for (i = pass + 1; i < n; i++)
        {
            if (strcmp(a[key].ename, a[i].ename) > 0)
            {
                temp = a[key];
                a[key] = a[i];
                a[i] = temp;
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
