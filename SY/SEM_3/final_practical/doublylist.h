#include<stdio.h> 
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *prev, *next;
} node;
node *create()
{
	int n, i;
	node *head = NULL, *temp, *new;
	printf("\nEnter the number of elements to be inserted : ");
	scanf("%d", &n);
	printf("\nEnter %d Elements : ", n);
	for (i = 0; i < n; i++)
	{
		new = (node *)malloc(sizeof(node));
		new->next = new->prev = NULL;
		scanf("%d", &new->data);
		if (!head)
			head = new;
		else
		{
			for (temp = head; temp->next != NULL; temp = temp->next);
			temp->next = new;
			new->prev = temp;
		}
	}
	return head;
}

void display(node *list)
{
	
		printf("\nElements of doubly linked list are :  ");
		for (; list != NULL; list = list->next)
			printf("%d  ",list->data);
		printf("\n");

}
