//p20-create a structure stationary (srno, name, qntaty) accept details of n stationarys and display it in summary format.
#include <stdio.h>
struct stationary
{
    int srno;
    char name[30];
    int qntaty;
    float rate;
    float total;
};

void main()
{
    int n,i;
    printf("Enter the no of stationarys : ");
    scanf("%d",&n);
    struct stationary stat[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter srno of %d stationary : ",i+1);
        scanf("%d",&stat[i].srno);
        printf("\nEnter name of %d stationary : ",i+1);
        scanf("%s",stat[i].name);
        printf("\nEnter qntaty of %d stationary : ",i+1);
        scanf("%d",&stat[i].qntaty);
        printf("\nEnter rate of %d stationary : ",i+1);
        scanf("%f",&stat[i].rate);
        // printf("\nEnter total of %d stationary : ",i+1);
        // scanf("%f",&stat[i].total=stat[i].qntaty*stat[i].rate);
        stat[i].total=stat[i].qntaty*stat[i].rate;
    }
    printf("\nsrno|  NAME  |  qntaty  |  rate | total |\n");
    for (i = 0; i < n; i++)
    {
        printf("%3d| %s| %4d| %.2f| %.2f|\n",stat[i].srno,stat[i].name,stat[i].qntaty,stat[i].rate,stat[i].total);
    }
}