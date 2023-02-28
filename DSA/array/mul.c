/*#include <stdio.h>
#define mult(a, b, c) (a * b * c)
void upper(char *a)
{
    int i;
    for (i = 0; a[i] != '\0'; i++)
    {
        // if (a[i] >= 97 && a[i] <= 122)
        if (97 <= a[i] <= 122)
            a[i] = a[i] - 32;
        else if (65 <= a[i] <= 90)
            a[i] = a[i] + 32;
        // printf("\n1.%s", a);
    }
    printf("\n%s", a);
}
int main()
{
    int i;
    char a[20] = "dhiraj";
    printf("Enter 3 no : ");
    scanf("%s", a);
    printf("%s", a);
    upper(a);
    return 0;
}
*/
// #include <stdio.h>
// void main()
// {
//     int a=1, b=2;
//     printf("Enter 2 no : ");
//     scanf("%d%d", &a, &b);
//     if (a > 0&&b>0 && !(a > b))
//         printf("sum : %d",a+b);
//     else
//         printf("invalid input");
// }

// #include<stdio.h>
// #define VALUE(Y) (Y*Y)
// int main()
// {
// int i=3,j;
// j=VALUE(5-2+2);  //  5-2+2*5-2+2
// printf("%d\n",j);
// }

// #include <stdio.h>
// #include <string.h>
// struct Data
// {
//     char str[10];
//     // int i;
//     // float f;
//     // double a;
// };
// void main()
// {
//     struct Data x;
//     printf("Memory size occupied by data : %d\n", sizeof(x));
//     // printf("deci to hex : %d -> %x\nhex to deci : %x -> %d",100,100,0x41,0x41);
// }

// #include <stdio.h>
// void rev(char *p)
// {
//     int i;
//     for(i=1;*(p+1)!='\0';i++,p++);
//     for(;i>=1;i--,p--)
//         printf("%c",*p);
// }
// void main()
// {
//     char ch[]="54321";
//     rev(ch);
// }

/*-------------------*********#include <stdio.h>
#include <string.h>
void reverseStr(char *str)
{

    char *begin, *end, ch, *q = str;
    begin = str;
    end = str;
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }

    for (int i = 0; i < (len - 1); i++)
    {
        end++;
    }
    for (int i = 0; i < len / 2; i++)
    {
        ch = *end;
        *end = *begin;
        *begin = ch;
        begin++;
        end--;
    }
    // printf("dfjdfjhfj\n");
    printf("%s\n", q);
}

int main()
{
    char str[20] = "dhiraj";
    // scanf("%s", str);
    reverseStr(str);
    // printf("%s", str);
    return 0;
}--------------------------*/

// void main()
// {
//     int r = 5, c = 4, i, j;
//     // printf("Enter row and column no respectivly : ");
//     // scanf("%d%d", &r, &c);
//     for (i = 1; i <= r; i++)
//     {
//         for (j = 1; j <= c; j++)
//         {
//             if (j < i)
//                 printf("#  ");
//             // printf("%d  ",2*j);
//             else
//                 printf("*  ");
//             // printf("%d  ",2*j-1);
//         }
//         printf("\n");
//     }
//         printf("\n");
//     for (i = 1; i <= r; i++)
//     {
//         for (j = 1; j <= c; j++)
//         {
//             if ((i < r&&i>1)&&(j>1&&j<c))
//                 printf("#  ");
//             else
//                 printf("%d  ",j);
//         }
//         printf("\n");
//     }
//         printf("\n");
//     for (i = 1; i <= r; i++)
//     {
//         for (j = c; j > 0; j--)
//         {
//             if (j < i)
//                 printf("#  ");
//             else
//                 printf("*  ");
//         }
//         printf("\n");
//     }

//     printf("\n%d   %d  ",NULL,sizeof(NULL));
//     printf("\n%d   %d  ",0,sizeof(0));
// }

// #include <stdio.h>
// int main()
// {
//     int i;
//     unsigned char c = '\0';
//     for (i = 0; i <= 255; i++, c++)
//         printf("%c  %d  %x  %o\n", c, c, c, c);

//     // printf("%d  %d  %d  ",NULL==0,NULL<0,NULL>0);
//     return 0;
// }


#include <stdio.h>
#include <ctype.h>

int main()
{
    int i,a[5],n;
    printf("\nEnter data : ");
    scanf("%d",&n);



    return 0;
}
