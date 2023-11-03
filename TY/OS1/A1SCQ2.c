// Q3 implement the c program to create a child process using fork(). using exec() system call, child process will execute the program specified  in set A(1) and parent will continue by printing message "i am parent"
#include <stdio.h>
// #include <sys/types.h>
// #include <sys/wait.h>
#include <unistd.h>
int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        char *arg[] = {"arg", NULL};
        execv("./A1SAQ1", arg);
    }
    else if (pid > 0)
    {
        printf("\nI am Parent (Main Process id : %d)\n", getpid());
    }
    return 0;
}