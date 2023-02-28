#include <stdio.h>
#include <string.h>
typedef struct student
{
    int id;
    char name[20];
    float percentage;
} record;

int main()
{
    // struct student record={0};
    record id={3,"dhiraj",88.44};


    // printf("enter name\n");
    // gets(record.name);

    printf("student id = %d\n",id.id);
    printf("student name = %s\n",id.name);
    printf("student \% = %.2f\n",id.percentage);
    return 0;
}