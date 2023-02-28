#include<stdio.h>
#include<string.h>
typedef struct city
{
	char city[20];
	int code;
}record;
record city[10];
int read_file(record *a)
{
	int i=0;
	FILE *fp;
	if((fp=fopen("cities.txt","r"))!=NULL)
	{
		while(!feof(fp))
		{
			fscanf(fp,"%s%d",a[i].city,&a[i].code);
			i++;
		}
	}
	return(i-1);
}
int l_search(record *a,int n,char x[20])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(a[i].city,x)==0)
		{
			printf("\n%s=%d\n",a[i].city,a[i].code);
			break;
		}
	}
	if(i==n)
    printf("\ncity not found");
}
int main()
{
	char x[20];
	int n;
	n=read_file(city);
	printf("\nEnter city to search : ");
	gets(x);
	l_search(city,n,x);
}
