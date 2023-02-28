#include <stdio.h>

void test();
void test1();
void test2();
void cwlcnt();
void sort_s_d();
int main()
{
    // test();
    // void cwlcnt();
    sort_s_d();


}

//---------------================******* FUNCTIONS ********=================----------------//

void test()
{
    int a[] = {10, 11, -1, 56, 67, 5, 4};
    int *p = a, *q = &a[0] + 3; // *p=10, *q=56

    printf("%d %d %d\n", (*p)++, (*p)++, *(++p));
    printf("%d\n", *p);
    printf("%d\n", (*p)++);
    printf("%d\n", (*p)++);
    q--;
    printf("%d\n", (*(q + 2))--);
    printf("%d\n", *(p + 2) - 2);
    printf("%d\n", *(p++ - 2) - 1);
    printf("%d", *q);
}

void test1()
{
    int a[] = {3, 2, 67, 0, 56};
    int *p = &a[2];
    printf("%d %d %d %d\n", *--p, (*p)++, --(*p), *--p);

    int s = 5;
    printf("%d %d %d %d\n", --s, s++, --s, --s);

    printf("%d %d %d %d %d\n", s, ++s, s++, s++, ++s);
}

void test2()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int *j = &arr[4], *k = (arr + 4);
    printf("%d %d\n", j, k);
    if (k == j)
        printf("same\n");
    else
        printf("not same\n");
}

void cwlcnt()
{
    // declare variables
    char str[200];
    int line, word, ch;

    // initialize count variables with zero
    line = word = ch = 0;

    // read multiline string
    printf("Enter string terminated with ~ :\n");
    scanf("%[^~]", str);

    // check every character
    for (int i = 0; str[i] != '\0'; i++)
    {
        // if it is new line then
        // one line and one word completed
        if (str[i] == '\n')
        {
            line++;
            word++;
        }

        // else it is a character
        else
        {
            // if character is space or tab
            // then one word is also completed
            if (str[i] == ' ' || str[i] == '\t')
            {
                word++;
                ch++;
            }

            // it was not '\n', sapace or tab
            // it is a normal character
            else
            {
                ch++;
            }
        }
    }

    // display count values
    printf("\nCharacter counts = %d\n", ch);
    printf("Word counts = %d\n", word);
    printf("Line counts = %d\n", line);

}

void sort_s_d()
{
    char a[200],t;
    int i;
    printf("Enter string : \n");
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if (a[i]<a[i+1])
        {
            t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
            printf("%d  %s\n",i+1,a);
        }
    }
    puts(a);
}