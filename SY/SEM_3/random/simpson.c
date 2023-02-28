// #include <stdio.h>
// #define c(x) (x*x*x*x)
// int main()
// {
//     float y[7],ans,i;
//     int j;
//     for(i=0,j=0;i<=6;i+=1,j++)
//     {
//         y[j]=1.0/(c(i)+1.0);
//         printf("\ny[%d] = %f   ",j,y[j]);
//     }
//     ans=(3/8.0)*((y[0]+y[6])+3*(y[1]+y[2]+y[4]+y[5])+2*(y[3]));
//     printf("\nans : %f",ans);
//     printf("\n1 : %f",(y[0]+y[6]));
//     printf("\n2 : %f",3*(y[1]+y[2]+y[4]+y[5]));
//     printf("\n3 : %f",2*(y[3]));
//     printf("\n4 : %f",((y[0]+y[6])+3*(y[1]+y[2]+y[4]+y[5])+2*(y[3])));
//     return 0;
// }
#include <stdio.h>
#define d(x) (1/(x*x*x+x+1))
int main()
{
    float y[9],ans,i;
    int j;
    for(i=0,j=0;i<=2;i+=0.25,j++)
    {
        y[j]=d(i);
        printf("\ny[%d] = %f   ",j,y[j]);
        printf("\na(i) y[%d] = %f   ",j,d(i));
    }
    ans=(0.25/3)*((y[0]+y[8])+4*(y[1]+y[3]+y[5]+y[7])+2*(y[2]+y[4]+y[6]));
    printf("\n\nans : %f\n",ans);
    printf("\n1 : %f",(y[0]+y[8]));
    printf("\n2 : %f",4*(y[1]+y[3]+y[5]+y[7]));
    printf("\n3 : %f",2*(y[2]+y[4]+y[6]));
    long double pi=22/7.0;
    printf("\n3 : %lf",pi);
    return 0;
}