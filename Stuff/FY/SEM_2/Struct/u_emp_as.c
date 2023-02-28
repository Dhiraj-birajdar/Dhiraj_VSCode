// WAP to accept employee info using union (emp_id, emp_name, emp_sallary)
#include <stdio.h>
union employee
{
    int emp_id;
    char emp_name[20];
    float emp_sallary;
}emp1;
void main()
{
    printf("Enter Employee ID \n");
    scanf("%d",&emp1.emp_id);
    printf("Employee ID : %d\n",emp1.emp_id);
    printf("Enter Employee Name \n");
    scanf("%s",emp1.emp_name);
    printf("Employee Name : %s\n",emp1.emp_name);
    printf("Enter Employee Sallary \n");
    scanf("%f",&emp1.emp_sallary);
    printf("Employee Sallary : %f\n",emp1.emp_sallary);
}