#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
    pid_t pid;
    int retnice;
    retnice = nice(2);
    pid = fork();
    if (pid == 0)
    {
        retnice = nice(5);
        printf("Child gets higher CPU priority %d\n", retnice);
    }
    else
    {
        retnice = nice(10);
        printf("Parent gets lower CPU priority %d\n", retnice);
        sleep(1);
    }
}