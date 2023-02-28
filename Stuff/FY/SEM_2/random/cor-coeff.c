// PROGRAM TO CALCULATE CORRELATION COEFFICIENT BETWEEN X AND Y.
#include <stdio.h>
#include <math.h>
int main()
{
    int n, sum_u = 0, sum_v = 0, sum_u2 = 0, sum_v2 = 0, sum_uv = 0;
    printf("Enter the number(n) of values n = ");
    scanf("%d", &n);
    int x[n], y[n], u[n], v[n], u2[n], v2[n], uv[n];
    printf("Enter the values of (x) with space : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
        u[i] = (x[i] - x[0]);
        u2[i] = (u[i] * u[i]);
        sum_u += u[i];
        sum_u2 += u2[i];
    }
    printf("Enter the values of (y) with space : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
        v[i] = (y[i] - y[0]);
        v2[i] = (v[i] * v[i]);
        sum_v += v[i];
        sum_v2 += v2[i];
        uv[i] = (u[i] * v[i]);
        sum_uv += uv[i];
    }
    printf("  x     y     u     v     u2    v2    uv\n");
    for (int j = 0; j < n; j++)
    {
        printf("%5.1d  %5.1d  %5.1d  %5.1d  %5.1d  %5.1d  %5.1d\n", x[j], y[j], u[j], v[j], u2[j], v2[j], uv[j]);
    }
    printf("    Total     %5.1d  %5.1d  %5.1d  %5.1d  %5.1d\n\n", sum_u, sum_v, sum_u2, sum_v2, sum_uv);

    float u_bar = (sum_u / (float)n), v_bar = (sum_v / (float)n);
    double r;

    r = (sum_uv - (n * u_bar * v_bar)) / (sqrt((sum_u2 - n * (u_bar * u_bar)) * (sum_v2 - n * (v_bar * v_bar))));

    printf("u = x - %d\tv = y - %d\n", x[0], y[0]);
    printf("u- = %.2f\tv- = %.2f\n\nCorrelation coefficient between x and y is  %.4lf\n\n", u_bar, v_bar, r);
    getchar();
}