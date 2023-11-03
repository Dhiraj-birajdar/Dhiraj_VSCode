// implement the c programs to create a child process using fork() display parent and child process id. child process will display message "i am Child process" and the parent process should display "i am parent process"
#include<stdio.h>
// #include<sys/types.h>
// #include<sys/wait.h>
#include<unistd.h>
int main()
{
    pid_t pid = fork();
    if(pid > 0)
        printf("\nI am Parent process\nParent process id : %d\n",getpid());
    if(pid == 0)
        printf("\nI am Child process\nChild process id : %d\n", getpid());
    return 0;
}