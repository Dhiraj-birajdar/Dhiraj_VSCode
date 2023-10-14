#include<stdio.h>
#include<unistd.h>
// #include<sys/types.h>
void main()
{
    printf("PID of execv1 : %d\n",getpid());
    char *arg[] = {"process", "2",NULL};
    execv("./execv2", arg);
    printf("back to execv1");
}

//  v is for the command line arguments. these are passed as an array of pointers to the function.
// int exect(const char *path, char *const argv[]);