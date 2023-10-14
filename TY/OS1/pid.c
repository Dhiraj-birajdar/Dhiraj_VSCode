#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void main()
{
    int pid = fork();
    // wait(NULL); // suspends parent process until child executes
    pid_t wait(); // synchronizes parent with child process
    if(pid > 0)
        printf("This is parent process");
    else if(pid == 0)
        printf("This is child process");
    else if(pid < 0)
        fprintf(stderr, "fork failed");
    printf("\tPID : %d\tFork returns : %d\n",getpid(),pid);
}
// fork returns (positive int) child process id to parent process
// fork returns (0) to  child process
// fork returns (negative int) to parent process if fork fails