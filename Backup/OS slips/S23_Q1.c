/*
Write a C program to illustrate the concept of orphan process. Parent process creates a 
child and terminates before child has finished its task. So child process becomes orphan 
process. (Use fork(), sleep(), getpid(), getppid())
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


void main()
{
	pid_t pid;
	pid = fork ();

	if (pid == 0)
	{
		printf("Child process PID : %d \n", getpid ());
		printf("orphan process Parent's PID : %d \n", getppid ());
		
		sleep(1);
	}
	else 
	{
		
		printf("Parents process PID : %d \n", getppid ());
		printf("Parents process child's PID : %d \n", pid);
	}
}