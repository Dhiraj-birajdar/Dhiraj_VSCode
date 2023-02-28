#include <stdio.h>
#include<math.h>
#include<conio.h>

//int area_squre (int a);
int main()
{
    int a,b;
    printf("Enter the square side:\n");
    scanf("%d",&b);
    //a=area_squre(b);
    printf("Area of square is %lf\n",pow(b,2));
    
    return 0;
    getch();
}

// int area_squre (int a){
//     int asq;
//     asq=a*a;
//     return asq;
// }