// WAP to accept student info using structure (rno, name, percentage) display 3 student record
#include <stdio.h>
struct student
{
    int rno;
    char name[20];
    float percentage;
} s[3],*p;
void main()
{
    int i,e;
    p=s;
    for (i = 0; i < 3; i++)
    {
        printf("Enter Student %d Roll no. : \n", i + 1);
        scanf("%d", &s[i].rno);
        printf("Enter Student %d Name : \n", i + 1);
        scanf("%s", s[i].name);
        printf("Enter Student %d Percentage : \n", i + 1);
        scanf("%f", &s[i].percentage);
    }
    float gp=s[0].percentage;
    for (i = 0; i < 3; i++)
    {
        if (s[i].percentage>=gp)
        {
            gp=s[i].percentage;
            e=i;
        }
        // printf("Student %d Roll no: %d\tName: %s\tPercentage: %.2f\n", i + 1, s[i].rno, s[i].name, s[i].percentage);
    }
    printf("Student %d Roll no: %d\tName: %s\tPercentage: %.2f\n", i + 1, s[e].rno, s[e].name, s[e].percentage);
}