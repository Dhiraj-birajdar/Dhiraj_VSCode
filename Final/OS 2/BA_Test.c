// Assignment 1: Slot 2 
// Q I) Modify above program so as to include the following: 
// a) Accept Request for a process 
// b) Resource request algorithm 
// c) Safety algorithm  
// Consider a system with ‘n’ processes and ‘m’ resource types. Accept number of instances for every resource type. For each process accept the allocation and maximum requirement matrices. Write a program to display the contents of need matrix and   to check if the given request of a process can be granted immediately or not.

#include <stdio.h>
void printArrays();
int isAvailable(int p);
void updateArrays(int p);
// int allocation[10][10], max[10][10], available[10], need[10][10],finish[10] = {0}, request[10], rpn, p, r;

int allocation[][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}},
        max[][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}},
        available[3] = {3, 3, 2},
        need[5][3],
        finish[5] = {0},
        request[]={1, 0, 2},
        p = 5, r = 3,
        rpn = 1;

int main()
{
    // printf("Enter no of processes and resource types: ");
    // scanf("%d%d", &p, &r);

    //Accepting no of allocations and max requirement for processes
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            // printf("\nEnter no of allocations and max requirement for P%d of resource %c: ",i,j+65);
            // scanf("%d%d",&allocation[i][j],&max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    //Accepting no of instances available for all resource types
    // for(int i = 0; i<r; i++){
    //     printf("\nEnter no of instances available for resource type %c: ",65+i);
    //     scanf("%d",&available[i]);
    // }
    printf("All arrays before solution: ");
    printArrays();

    // printf("\nEnter process no for request: ");
    // scanf("%d",&rpn);
    // printf("\nEnter request resource for P%d: ",rpn);
    // for(int i = 0; i<r; i++){
    //     scanf("%d",&request[i]);
    // }

    int flag = 1;
    for(int i = 0; i<r; i++){
        if(!(request[i] <= need[rpn][i]) || !(request[i] <= available[i]))
            flag = 0;
    }

    //return if allocation cannot be done
    if(!flag){
        printf("\nRequest cannot be granted.");
        return 1;
    }

    //updating all arrays according to request
    for(int i = 0; i<r; i++){
        available[i] -= request[i];
        allocation[rpn][i] += request[i];
        need[rpn][i] -= request[i];
    }
    printf("\n\n\nAns:->\nAfter updating arrays for request P1: (1,0,2): ");
    printArrays();
    int safeSequence[10], round = 0;
    for(int i = 0, count = 1, j=0;; i = (count%p), count++){

        if(i == p-1){
            int done = 1;
            for(int i = 0; i<p; i++){
                if(finish[i] == 0){
                    done = 0;
                    break;
                }
            }
            if(done){
                printf("\n\nFinal Ans:\nYes, the System is in safe state. so request can be granted immediately.\nSafe Sequence: ");
                for(int i = 0; i<p; i++)
                    printf("P%d  ",safeSequence[i]);
                printf("\n\n");
                return 0;
            }
        }

        if(finish[i])
            continue;

        if(isAvailable(i)){
            updateArrays(i);
            printf("\n%d) Process(%d) completed, it will release resources.\nupdated arrays:",count,i);
            printArrays();
            finish[i] = 1;
            safeSequence[j++] = i;
        }else{
            printf("\n%d)Process(%d) has to wait.",count, i);
        }

        printf("\nFinish = ");
        for(int x = 0; x<p; x++)
            printf("P%d:%c  ",x,finish[x]?'T':'F');
        printf("\n\n***********************************************************************");

        
        // count++;
    }
    return 0;
}




//Updates allocation array, need array, available array
void updateArrays(int p){
    for(int i = 0; i<r; i++){
        available[i] += allocation[p][i];
        allocation[p][i] = 0;
        need[p][i] = 0;
        max[p][i] = 0;
    }
}

//checks if need of process is less than available resources
int isAvailable(int p){
    int flag = 1;
    for(int i = 0; i<r; i++){
        if(!(need[p][i] <= available[i]))
            return 0;
    }

    return 1;
}

//function to print all arrays
void printArrays(){
char dash[]= "----------------", header[]="Pi | A | B | C |";
// printf("\n%1$16s  %2$-16s  %3$-16s\n%4$16s  %4$16s  %4$16s\n%5$16s  %5$16s  %5$16s\n%4$16s  %4$16s  %4$16s\n","Allocation Array","Max Array", "Need Array","----------------","Pi | A | B | C |");
printf("\n%16s  %-16s  %-16s\n%16s  %16s  %16s\n%16s  %16s  %16s\n%16s  %16s  %16s\n","Allocation Array","Max Array", "Need Array",dash,dash,dash,header,header,header,dash,dash,dash);
    for (int i = 0; i < p; i++)
    {
        printf("P%d |", i);
        for (int j = 0; j < r; j++)
        {
            printf(" %d |", allocation[i][j]);
        }
        printf("  ");

        printf("P%d |", i);
        for (int j = 0; j < r; j++)
        {
            printf(" %d |", max[i][j]);
        }
        printf("  ");

        printf("P%d |", i);
        for (int j = 0; j < r; j++)
        {
            printf(" %d |", need[i][j]);
        }
        printf("\n");

    }
    // printf("%1$16s  %1$16s  %1$16s","----------------"); 
    printf("%16s  %16s  %16s",dash,dash,dash); 

     printf("\n\nAvailable Array\n------------\n A | B | C |\n------------\n");
    for (int i = 0; i < r; i++)
    {
        printf(" %d |", available[i]);
    }
    printf("\n");
    printf("------------\n");

}