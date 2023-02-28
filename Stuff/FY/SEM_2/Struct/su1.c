#include <stdio.h>
#include <string.h>
union student
// struct student
{
    int id;
    // int id,a,d;
    char name[20];
    float percentage;
};
// } record;   // optional

int main()
{
    // struct student record={0};     // optional
    union student record/*={51,2,3,"dhiraj",443.44}*/;
    // struct student record={1,2,3,"dhiraj",443.44};
    char t[20];
//?<<<<<<<<<<<<<<<<<  hardcoded  <<<<<<<<<<<<<<<<<<<<<<<
    // record.id=1;
    // strcpy(record.name,"Dhiraj");
    // record.percentage=80.23;
//?<<<<<<<<<<<<<<<<<  hardcoded  <<<<<<<<<<<<<<<<<<<<<<<


//*<<<<<<<<<<<<<<<<<<<<  user input  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    // scanf("%s",record.name);
    printf("enter name\n");
    gets(t);
    strcpy(record.name,t);
    printf("Enter id\n");
    scanf("%d",&record.id);
    printf("Enter percentage\n");
    scanf("%f",&record.percentage);
//*<<<<<<<<<<<<<<<<<<<<  user input  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    printf("student id = %d\n",record.id);
    // printf("student a = %d\n",record.a);
    // printf("student d = %d\n",record.d);
    printf("student name = %s\n",record.name);
    printf("student %%  = %.2f\n",record.percentage);
    return 0;
}