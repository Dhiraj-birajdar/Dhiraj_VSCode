#include <stdio.h>

int main()
{
    int c;
    float sp, cp, p, l;
    printf("** enter choice **\n[1] Profit\n[2] loss \n[3] exit\n");
    scanf("%d", &c);

    while (c == 1 || c==2)
    {
        printf("Enter Selling price : ");
        scanf("%f", &sp);
        printf("Enter Cost price : ");
        scanf("%f", &cp);
        float pr = sp - cp, lo = cp - sp;

        if (c == 1)
        {
            p = (pr / cp) * 100;
            printf("profit is %f\%", p);
            return 0;
        }
        else if (c == 2)
        {
            l = (lo / cp) * 100;
            printf("loss is %f\%", l);
            return 0;
        }
    }
    printf("bye");
}