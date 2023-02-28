#include <stdio.h>
#include <stdlib.h>
#include "doublylist.h"

int main()
{
	int ch, a;
	node *head = NULL;
	while (1)
	{
		printf("\n1. Create Doubly linked list\n2. Display Doubly linked list\n3. Exit\n\nEnter choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			head = create();
			break;
		case 2:
			if(!head)
				printf("\nList is empty\nFirst Create list \n");
			else
				display(head);
			break;
		case 3:
			exit(0);
		default:
			printf("\nInvalid choice\n");
		}
	}
}
