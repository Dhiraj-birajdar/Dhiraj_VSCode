//Q1. Write a program that reverses a string of characters. The function should use a stack library (cststack.h). Use a static implementation of the stack.

#include<stdio.h>
#include<string.h>
#include"cststack.h"

int main()
{
	char str[100],stack[100];
	
	int i;
	printf("\nEnter a string of characters : ");
	gets(str);
	printf("\nString before reversal : %s",str);
	initstack();
	for(i=0;str[i]!='\0';i++)
	{
		if(isfull())
			printf("\nStack is full");
		else
			push(str[i]);
	}

	reversestack(str);
	printf("\nString after reversal : %s",str);
	
}



