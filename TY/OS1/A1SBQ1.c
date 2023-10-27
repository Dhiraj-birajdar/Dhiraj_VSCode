// implement the c program to accept n integers to be sorted. main function creates child process using fork system call. parent process sorts the integers using bubble sort and waits for child process using wait system call. child process sorts the integers using insertion sort.
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
void bubble(int a[], int n)
{
    int t;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - i) - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
void insertion(int a[], int n)
{
    int i, j, t;
    for (i = 1; i < n; i++)
    {
        t = a[i];
        for (j = i - 1; j >= 0 && a[j] > t; j--)
            a[j + 1] = a[j];
        a[j + 1] = t;
    }
}
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d   ", a[i]);
}
int main()
{
    int n = 5, a[n], i = 0;
    printf("Enter 5 numbers : ");
    for (; i < n; i++)
        scanf("%d", &a[i]);
    display(a, n);
    printf("\n");
    pid_t pid = fork();
    if (pid == 0)
    {
        insertion(a, n);
        printf("\nchild process insertion sort\n");
        display(a, n);
    }
    else if (pid > 0)
    {
        bubble(a, n);
        wait(NULL);
        printf("\nparrent process bubble sort\n");
        display(a, n);
    }
    return 0;
}