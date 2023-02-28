//p20-create a structure employee (id, name, salary) accept details of n employees and display it in summary format.
#include <stdio.h>
struct employee
{
    int id;
    char name[30];
    float salary;
};

void main()
{
    int n,i;
    printf("Enter the no of employees : ");
    scanf("%d",&n);
    struct employee emp[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter id of No.%d employee : ",i+1);
        scanf("%d",&emp[i].id);
        printf("\nEnter name of No.%d employee : ",i+1);
        scanf("%s",emp[i].name);
        printf("\nEnter salary of No.%d employee : ",i+1);
        scanf("%f",&emp[i].salary);
    }
    printf("\n  ID  |  NAME  |  SALARY  |\n");
    for (i = 0; i < n; i++)
    {
        printf("%6d| %s| %.2f|\n",emp[i].id,emp[i].name,emp[i].salary);
    }
}