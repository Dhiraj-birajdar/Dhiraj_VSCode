//also repeated in slip no :- 18 , 

/*
Write the program to simulate FCFS CPU-scheduling. The arrival time and first CPU burst for different n number of processes should be input to the algorithm. Assume that 
the fixed IO waiting time (2 units). The next CPU-burst should be generated randomly. 
The output should give Gantt chart, turnaround time and waiting time for each process. 
Also find the average waiting time and turnaround time.
*/


#include <stdio.h>

typedef struct PCB
{
	int pid, arrival, burst, finish, start;
	int avg, avg1;
}NODE;


void pline (int x);
void display (int num, NODE * p);


void main()
{
	int i, num, j , n;
	float avg = 0.0, sum = 0.0;
	NODE p[10], temp;

	printf("\n Enter the total number of process :");
	scanf("%d", &num);
	printf("\n PID\t AT\t BT\n");

	for(i=0; i<num; i++)
	{
		printf("P[%d]", i+1);
		scanf("\t%d\t%d", &p[i].arrival, &p[i].burst);

		p[i].pid = i+1;
	}

	for(i=0; i<num; i++)
	{
		for(j=0; j<num-i-1; j++)
		{
			if(p[j].arrival > p[j+1].arrival)
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}

	for(i=0; i<num; i++)
	{
		sum = sum + p[i].burst;
		p[i].finish = sum;
	}
	sum = 0;
	pline (50);

	printf("PID \t AT \t BT \t FT \t ST \t WT \t TAT \n");

	pline(50);

	for(i=0; i<num; i++)
	{
		if(i == 0)
		{
			p[i].start = p[i].arrival;
		}
		else
		{
			p[i].start = p[i-1].finish;
		}

	printf("p[%d] \t %d \t %d \t %d \t %d \t %d \t %d\n",p[i].pid , p[i].arrival , p[i].burst , p[i].finish , p[i].start , p[i].start-p[i].arrival , p[i].finish - p[i].arrival);

	sum+=p[i].finish;
	}
		
		pline(50);
		float sum1 = 0;
		int sum2 = 0;

		for(i=0; i<num; i++)
		{
			p[i].avg = p[i].finish - p[i].arrival;
			p[i].avg1 = p[i].start - p[i].arrival;
			sum1 += p[i].avg;
			sum2 += p[i].avg1;
		}

		printf("\n");
		printf("Your Gaintt chart is : \n");
		
		display(num, p);
		
		printf("\n");
		printf("\nAverage of Turnaround time is = %.2f\n",sum1/num);
		printf("\nAverage of waiting time = %d",sum2/num);
}


	

void pline(int x)
{
	int i ;
	for(i=0; i<x; i++)
	{
		printf(" - ");
	}
		printf("\n");
}




void display(int num , NODE *p)
{
	pline(16 * num);

	for(int i=0; i<num; i++)
	{
		if(i==0)
			printf("| \t p[%d] \t",p[i].pid);
		else
			printf("| \t p[%d] \t",p[i].pid);
	}
	printf("|");
	printf("\n");
	pline(16*num);

		for(int i=0; i<num+1; i++)
		{
			if(i==0)
				printf("| \t %d \t",i);
			else
				printf("| \t %d \t",p[i-1].finish);
		}
}
