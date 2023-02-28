#include <stdio.h>
int main()
{
    int s1=80, s2=81, s3=82, s4=81, s5=80, s;
    float p;
    // printf("ENTER 5 SUBJECT MARKS:");
    // scanf("%d%d%d%d%d", &s1, &s2, &s3, &s4, &s5);
    s = s1 + s2 + s3 + s4 + s5;
    p = (float)s / 5;
    printf("S1:%d S2:%d S3:%d S4:%d S5:%d \nTOTAL:%d \nPERCENTAGE:%.2f", s1, s2, s3, s4, s5, s, p);
    return 1;
}