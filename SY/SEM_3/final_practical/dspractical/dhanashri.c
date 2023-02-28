#include<stdio.h>
#include "stststack.h"
int main(void)
{
	stack s1,s2;
	init(&s1);
	init(&s2);
	int n,num,i,j,size,number;
	printf("\nHow many elements in stack1:");
	scanf("%d",&n);
	printf("\nEnter the element in push:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		push(&s1,num);
	}
	printf("\nHow many element in stack2:");
	scanf("%d",&size);
	printf("\nEnter the element in push:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&number);
		push(&s2,number);
	}
	stack t1,t2;
	init(&t1);
	init(&t2);
	while(!isempty(&s1) && !isempty(&s2) && (peek(&s1) && peek(&s2)))
	{
		push(&t1,pop(&s1));
		push(&t2,pop(&s2));
	}
	if(isempty(s1) && isempty(s2))
	{
		printf("\nStack are identical:");
	}
	else
	{
		printf("\nNot equal:");
	}
	while(!isempty(&t1))
	push(&s1,pop(&t1));
	while(!isempty(&t2))
	push(&s2,pop(&t2));
}
