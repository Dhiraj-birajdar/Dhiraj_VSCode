// #include <stdio.h>
// #include <string.h>
// typedef struct student
// {
//     int roll_no;
//     char name[20];
//     float percentage;
// } record;

// int main()
// {
//     record id,*pid;
//     pid=&id;

// //*===============================================
//     (*pid).roll_no=1;
//     strcpy((*pid).name,"dhiraj");
//     (*pid).percentage=81;
// //!<<<<<<<<<<<<<<<<<<<<  OR  >>>>>>>>>>>>>>>>>>>>>>
//     pid->roll_no=5;
//     strcpy(pid->name,"niraj");
//     pid->percentage=90;
// //*===============================================

//     printf("student id = %d\n",id.roll_no);
//     printf("student name = %s\n",id.name);
//     printf("student \% = %.2f\n",id.percentage);
//     return 0;
// }




#include <stdio.h>
#include <string.h>

int main()
{
    char a[20];
    int b;
    float c;

    printf("Enter id\n");
    scanf("%d",&b);
    printf("enter name\n");
    gets(a);
    // strcpy(record.name,t);
    printf("Enter percentage\n");
    scanf("%f",&c);
//*<<<<<<<<<<<<<<<<<<<<  user input  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    printf("student id = %d\n",b);
    printf("student name = %s\n",a);
    printf("student %%  = %.2f\n",c);
    return 0;
}