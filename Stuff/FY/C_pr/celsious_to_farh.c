#include <stdio.h>
int CtoF (int c);
int main()
{
    int a;
    printf("Enter the temperature in celsious:\n");
    scanf("%d",&a);
    printf("%d celsious = %d fahrenheit\n",a,CtoF(a));
    
    
    
    return 0;
}

int CtoF (int c){
    int result;
    result=(c*9/5)+32;
    return result;
}