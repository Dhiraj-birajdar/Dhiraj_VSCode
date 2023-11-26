//also repeated in slip no :- 22 , 

/*
Write the program to simulate Non-preemptive Priority scheduling. The arrival time and 
first CPU-burst and priority for different n number of processes should be input to the 
algorithm. Assume the fixed IO waiting time (2 units). The next CPU-burst should be 
generated randomly. The output should give Gantt chart, turnaround time and waiting 
time for each process. Also find the average waiting time and turnaround time. 
*/



#include <stdio.h>
#include<string.h>

struct input
{
	char pname[10];
	int bt, at, tbt, ft, p;
} tab[10];

struct gantt
{
	char pname[10];
	int start, end;
} g[30], g1[30];

int n, i, time, prev, k;


void printoutput()
{
	int TWT = 0, TTAT = 0;
	float ATAT, AWT;
	printf("\nPname\tAT\tBT\tpriority\tFT\tWT\tTAT");
	for (i = 0; i < n; i++)
	{
		printf("\n%d\t%d", tab[i].ft-tab[i].at-tab[i].bt , tab[i].ft - tab[i].at);
		
        TWT = TWT + (tab[i].ft - tab[i].at - tab[i].bt);
		TTAT = TTAT + (tab[i].ft - tab[i].at);
	}

	printf("\nTotal WT: %d", TWT);
	printf("\nTotal TAT:%d", TTAT);
	AWT = (float)TWT / n;
	ATAT = (float)TTAT / n;
	printf("\nAverage WT: %f", AWT);
	printf("\nAverage TAT:%f", ATAT);
}


void sort()
{
	int pass;
	struct input temp;
	for (pass = 1; pass < n; pass++)
	{
		for (i = 0; i < n - pass; i++)
		{
			if (tab[i].at > tab[i + 1].at)
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
		}
	}
}


int arrived(int time)
{
	for (i = 0; i < n; i++)
	{
		if (tab[i].at <= time && tab[i].tbt != 0)
		return 1;
	}
	return 0;
}


int gethighpriority(int time)
{
	int processpos, min = 99;
	for (i = 0; i < n; i++)
	{

		if (tab[i].at <= time && tab[i].tbt != 0 && tab[i].p < min)
		{
			min = tab[i].p;
			processpos = i;
		}
	}
	return processpos;
}


void processinput()
{
	int finish = 0, j;
	k = 0;
	while (finish != n)
	{
		if (arrived(time))
		{
			i = gethighpriority(time);
			for (j = 0; j < tab[i].bt; j++)
			{
				time++;
				tab[i].tbt--;
				g[k].start = prev;
				g[k].end = time;
				prev = time;
				strcpy(g[k++].pname, tab[i].pname);
				tab[i].ft = time;
				if (tab[i].tbt == 0)
				{
					finish++;
					break;
				}
			}
		}
		else
		{
			time++;
			g[k].start = prev;
			g[k].end = time;
			strcpy(g[k++].pname, "idle");
			prev = time;
		}

	}
}


void ganttchart()
{
	int i, j = 0;
	printf("\ngantt chart is:\n");
	g1[0] = g[0];
	for (i = 1; i < k; i++)
	{
		if (strcmp(g[i].pname, g1[j].pname) == 0)
			g1[j].end = g[i].end;
		else
		{
			j++;
			g1[j] = g[i];
		}
	}
	printf("\nStart\tpname\tEnd");
	for (i = 0; i <= j; i++)
	{
		printf("\n%d\t%s\t%d", g1[i].start, g1[i].pname, g1[i].end);
	}
}



int main()
{
	printf("\nEnter No of Processes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("\nEnter Process Name: ");
		scanf("%s", tab[i].pname);
		printf("Arrival Time:");
		scanf("%d", &tab[i].at);
		printf("Burst Time: ");
		scanf("%d", &tab[i].bt);
		tab[i].tbt = tab[i].bt;
		printf("Enter the Priority:");
		scanf("%d", &tab[i].p);
	}


	sort();
	processinput();
	printoutput();
	ganttchart();
}
