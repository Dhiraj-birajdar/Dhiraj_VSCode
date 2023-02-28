#include <stdio.h>
int main()
{
    float x1=1,x2=2,x3=3,x4=4.0,x5=7,x=5;
    float fx1=2,fx2=4,fx3=8,fx4=16,fx5=128,s;

    s=(((x-x2)*(x-x3)*(x-x4)*(x-x5))/((x1-x2)*(x1-x3)*(x1-x4)*(x1-x5)))*fx1+(((x-x1)*(x-x3)*(x-x4)*(x-x5))/((x2-x1)*(x2-x3)*(x2-x4)*(x2-x5)))*fx2+(((x-x1)*(x-x2)*(x-x4)*(x-x5))/((x3-x1)*(x3-x2)*(x3-x4)*(x3-x5)))*fx3+(((x-x1)*(x-x2)*(x-x3)*(x-x5))/((x4-x1)*(x4-x2)*(x4-x3)*(x4-x5)))*fx4+(((x-x1)*(x-x2)*(x-x3)*(x-x4))/((x5-x1)*(x5-x2)*(x5-x3)*(x5-x4)))*fx5;
    char a="dhiraj";
    for(int i=0;i<7;i++)
    // printf("%c ",a[i]);
    printf("f(5) = %.4f  %x",s,64000);  // o/p : f(5) = 32.9333
}

// #include<stdio.h>  
// #include<stdlib.h>  
// int main(){  
// //  int n,i,*ptr,sum=0;    
// //     printf("Enter number of elements: ");    
// //     scanf("%d",&n);    
// //     ptr=(int*)calloc(n,sizeof(int));  //memory allocated using calloc    
// //     printf("before realloc size p : %d\n",sizeof(ptr));
// //     if(ptr==NULL)                         
// //     {    
// //         printf("Sorry! unable to allocate memory");    
// //         exit(0);    
// //     }    
// //     printf("Enter elements of array: ");    
// //     for(i=0;i<n;++i)    
// //     {    
// //         scanf("%d",ptr+i);    
// //         sum+=*(ptr+i);    
// //     }    
// //     printf("Sum=%d",sum);    
// //     free(ptr);    
// // return 0;  
    
// }    