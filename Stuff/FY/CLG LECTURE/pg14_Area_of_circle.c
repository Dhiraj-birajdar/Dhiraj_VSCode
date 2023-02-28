#include <stdio.h>
int main()
{
    float r, ac;
    printf("ENTER THE RADIUS:");
    scanf("%f", &r);
    ac = 3.14 * r * r;
    printf("AREA OF CIRCLE:%f", ac);
    return 0;
}