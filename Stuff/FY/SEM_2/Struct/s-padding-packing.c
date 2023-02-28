#include <stdio.h>
#pragma pack(1)
typedef struct student
{
    char i;
    int l;
    char p;
    double a;
    // char o;
    // double s;
    // int d;
    // char r[5];
} stu;

int main()
{
    stu s1;
    printf("size of s1 = %d\n", sizeof(s1));
    return 0;
}