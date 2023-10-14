#include<stdio.h>
#include<unistd.h>
#include<limits.h>
// #include<sys/types.h>
// #include<sys/wait.h>
#include<sys/resource.h>
void main()
{
    int pid, rnice;
    printf("press DEL to stop process \n");
    pid = fork();
    // for(;;)
    // {
    //     if(pid == 0)
    //     {
    //         rnice = nice(-5);
    //         printf("child gets higher cpu priority %d\n", rnice);
    //         sleep(1);
    //     }
    //     else
    //     {
    //         rnice = nice(4);
    //         printf("parent gets lower cpu priority %d\n", rnice);
    //         sleep(1);
    //     }
    // }
    if(pid == 0)
    {
        rnice = nice(-5);
        printf("child gets higher cpu priority %d  %d\n", rnice, getpriority(PRIO_PROCESS, getpid()));
        sleep(1);
    }
    else
    {
        rnice = nice(4);
        printf("parent gets lower cpu priority %d\n", rnice);
        sleep(1);
    }
}