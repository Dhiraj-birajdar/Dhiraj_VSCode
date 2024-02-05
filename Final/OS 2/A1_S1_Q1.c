// Assignment 1: Slot 1
// Q I) Add the following functionalities in your program
// a) Accept Available
// b) Display Allocation, Max
// c) Display the contents of need matrix
// d) Display Available

#include <stdio.h>

int main()
{
    int allocation[][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}},
        max[][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}},
        available[3],
        need[5][3];

    printf("Enter available resource instances for (A B C): ");
    scanf("%d%d%d", &available[0], &available[1], &available[2]);
    printf("\nAllocation Matrix\n----------------\nPi | A | B | C |\n----------------\n");
    for (int i = 0; i < 5; i++)
    {
        printf("P%d |", i);
        for (int j = 0; j < 3; j++)
        {
            printf(" %d |", allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
        printf("\n");
    }
    printf("----------------\n");

    printf("\nMax Matrix\n----------------\nPi | A | B | C |\n----------------\n");
    for (int i = 0; i < 5; i++)
    {
        printf("P%d |", i);
        for (int j = 0; j < 3; j++)
        {
            printf(" %d |", max[i][j]);
        }
        printf("\n");
    }
    printf("----------------\n");

    printf("\nNeed Matrix\n----------------\nPi | A | B | C |\n----------------\n");
    for (int i = 0; i < 5; i++)
    {
        printf("P%d |", i);
        for (int j = 0; j < 3; j++)
        {
            printf(" %d |", need[i][j]);
        }
        printf("\n");
    }
    printf("----------------\n");

    printf("\nAvailable Matrix\n------------\n A | B | C |\n------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %d |", available[i]);
    }
    printf("\n");
    printf("------------\n");

    return 0;
}