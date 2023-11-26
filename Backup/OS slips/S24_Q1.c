/*
Implement the C program to accept n integers to be sorted. Main function creates child 
process using fork system call. Parent process sorts the integers using bubble sort and 
waits for child process using wait system call. Child process sorts the integers using 
insertion sort.
*/


#include<stdio.h>
#include<sys/types.h>

void child_I_sort(int a[] , int n)
{
	int  i,j,key;
		for(i=1; i<n; i++)
		{
			key=a[i];
				for(j=i-1; j>=0; j--)
				 {
				 	if(a[j]>key)
						a[j+1]=a[j];
					else
						break;
				 }								 								  					
			a[j+1]=key;
		}
}

void parent_B_sort(int a[] , int n)
{
	int j,i,temp;
		for(i=0; i<n-1; i++)
			for(j=0; j<n-i-1; j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
	                                a[j+1]=temp;
				}
			}
}


void main()
{
	pid_t pid;
	pid_t cpid;
	pid_t parentpid;
					
	int n,a[10],i;
		
		printf("\nenter the size of an array = ");
		scanf("%d",&n);
		
		printf("\nenter the elements of an array = ");
			for(i=0; i<n; i++)
				{
				    scanf("%d",&a[i]);
				}
					
					pid=fork();

					if(pid==0)
					{
						printf("\nprocess id of child process : %d\n",pid);
						child_I_sort(a,n);
						printf("sorted array from child process is = ");
							for(i=0; i<n; i++)
							printf("\t%d",a[i]);
									
					}
					else
					{
						printf("\nprocess id of parent process : %d\n",pid);
						parent_B_sort(a,n);
						printf("sorted array from parent process is =");
							for(i=0; i<n; i++)
							printf("\t%d",a[i]);
					}
}