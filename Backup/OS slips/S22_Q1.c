/*
Write a program that demonstrates the use of nice() system call. After a child process is 
started using fork(), assign higher priority to the child using nice() system call.
*/


#include <stdio.h>
#include <sys/types.h>

void main ()
{
	pid_t pid;
  	int retnice;
 	//retnice = nice(2);
	pid = fork();

	if (pid == 0)
	{
		retnice = nice(-1);
			
		printf("Child gets higher CPU priority : %d\n", retnice);	
	}
	else
	{
		retnice = nice(19);

		printf("Parent gets lower CPU priority : %d\n", retnice);

		sleep(1);
	}
} 
