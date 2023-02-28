#include <stdio.h>
#define sqr(s) (s*s)
#define PI 3.14
// int binary(int bi);
int main()
{
const int pi=3.14;
int ar;
ar=pi*5*5;
printf("%d\n",ar);
printf("%d\n",3.14*5*5);
    printf("%d\n", sqr(2));
    // char name[20];
    // int ans;
    // printf("Enter your name : ");
    // gets(name);

    // printf("\nHi %s Are You Stupid ?   ( 1 = Yes or 2 = No )\nAnswer : ", name);
    // scanf("%d", &ans);

    // while (ans != 1)
    // {
    //     if (ans == 2)
    //     {
    //         printf("\nHi %s Don't lie. Are You Stupid ?   (1 = Yes or 2 = No )\nAnswer : ", name);
    //         scanf("%d", &ans);
    //     }
    //     else
    //     {
    //         printf("\nYou are Stupid. Aren't You ?\nAnswer : ");
    //         scanf("%d", &ans);
    //     }
    // }

    // printf("\nI knew it. Bye %s.", name);
    // getchar();
    char binary[15];
    int bi = 19, i = 0, no = 0;

    while (bi != 0)
    {
        if (bi % 2 == 0)
        {
            binary[i] = '0';
        }
        else
        {
            binary[i] = '1';
        }
        i++;
        bi = bi / 2;
        // return 0;
    }
    // printf("%c",binary[0]);

    for (int j = i; j > 0; j--)
    {
        printf("%c", binary[j - 1]);
    }
}

// int binary(int bi)
// {

// // bi = 5;

// }
