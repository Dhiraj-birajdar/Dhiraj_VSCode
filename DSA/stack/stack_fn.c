#include<stdio.h>
struct stack
{
    int a[5],sp;
}stk;
void inti()
{
    stk.sp=-1;
}
push(int i)
{

}
void main()
{
    int ch,d;
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Exit\n\nEnter choice : ");
        switch (ch)
        {
        case 1:
            if(stk.sp>4)
            printf("\nEnter data to push : ");
            scanf("%d",d);
            push(d);
            break;
        
        default:
            break;
        }
    }
}