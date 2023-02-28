#include <stdio.h>
float avg(int a,int b,int c);

int main()
{
    int a,b,c,ag;
    printf("Enter 3 nos:\n");
    scanf("%d%d%d",&a,&b,&c);
   // ag=avg(a,b,c);
    printf("Average is %f\n",avg(a,b,c));
    


    return 0;
}

float avg(int a,int b,int c){
    float ag;
    ag=(float)(a+b+c)/3;
    return ag;
}
