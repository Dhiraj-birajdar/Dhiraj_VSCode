#include<stdio.h>
int i;
int prime(int n)
{
   if(i==1)
   {
   	return 1;
   }
   else if(n%i==0)
   {
   	return 0;
   }
   else
   {
   	 i--;
     printf("%d ",i);
   	return prime(n);
   }

	
}
void pri(void);
int main()
{

	printf("hi\n");

	while(0);
	
		printf("2. hi\n");
	
	// int n,count;
	// printf("Enter The Number To Check Prime Or Not:\n");
	// scanf("%d",&n);
	// i=n/2;
	// count=prime(n);
	// if(count==1)
	// {
	// 	printf("Prime Number");
		
	// }
	// else
	// {
	// 	printf("Not Prime No");
	// }

	return 0;
}