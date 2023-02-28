int get_no(char *s)
{
    int n;
    printf("%s", s);
    scanf("%d", &n);
    return n;
}

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int fact(int n)
{
    if (n >= 1)
        return n * fact(n - 1);
    else
        return 1;
}

int pow_xy(int x, int a)
{
    if (a <= 1)
        return x;
    int p = x * pow_xy(x, --a);
    return p;
}

int sod(int n)
{
    int rem, sum = 0;
    while (n != 0)
    {
        rem = n % 10;
        sum += rem;
        n = n / 10;
    }
    return sum;
}