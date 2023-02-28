// p27-write a program to define value of PI & use it to find area and perimeter of circle
#include <stdio.h>
#define PI 3.141592
void main()
{
    int r;
    float ar, pr;
    printf("Enter radius of circle : ");
    scanf("%d", &r);
    ar = PI * r * r;
    pr = PI * 2 * r;
    printf("\nArea of circle is : %.2f\n", ar);
    printf("Perimeter of circle is : %.2f\n", pr);
}