#include<stdio.h>
int main()
{
int a,b,c;

printf("ENTER TWO NUMBERS:");
scanf("%d %d",&a,&b);

c=a+b;
printf("A:%d B:%d SUM:%d",a,b,c);  // can be written as: printf("A:%d B:%d SUM:%d",a,b,a+b); without 3rd variable

}
