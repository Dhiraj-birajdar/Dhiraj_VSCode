#include<stdio.h>
void delay(unsigned int count)
    {
        int i, j;
        for (i = 0; i < count; i++)
            for (j = 0; j < 99999; j++);
    }
int main()
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("%d\n",i);
        delay(1000);
    }
}