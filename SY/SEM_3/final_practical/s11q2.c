#include <stdio.h>
#include <stdlib.h>
#include"PriorityQ.h"
pque q[20];
int main()
{
    int ch,ele,pri;
    init();
    while(1)
    {
        printf("\n\n1. Add an element in queue with priority\n2. Delete an element from queue according to priority\n3. Display priority queue\n4. Exit\n\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(isfull(q))
                    printf("\nQueue is full");
                else
                {
                    printf("\nEnter data : ");
                    scanf("%d",&ele);
                    printf("\nEnter priority : ");
                    scanf("%d",&pri);
                    addtoq(q,ele,pri);
                    printf("\nElement added successfully");
                }
                break;
            case 2:
                if(isempty(q))
                    printf("\nQueue is empty");
                else
                {
                    dqueue(q);
                    printf("\nElement deleted successfully\n\nUpdated priority queue :");
                    display(q);
                }
                break;
            case 3:
                if(isempty(q))
                    printf("\nQueue is empty");
                else
                {
                    printf("\nElements of queue are : ");
                    display(q);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice ");
                
        }
    }
    return 0;
}