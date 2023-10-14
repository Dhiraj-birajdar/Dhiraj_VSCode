#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
void hello();
void t()
{
    for(char c = 'a'; c<'z';c++)
    {
        printf("%c",c);
        sleep(1);
        printf("\b");
    }
}
int main()
{
    t();
    // hello();
}
void hello()
{
    char s[] = "hello world";
    char str[12];
    for (int i = 0; i < strlen(s); i++)
    {
        for (char j = 'a'; j <= 'z'; j++)
        {
            if (s[i] == ' ')
            {
                printf("%c",j);
                break;
            }
            else if (s[i] == j)
            {
                printf("\b");
                printf("%c ",j);
                break;
            }
            else
            {
                printf("%c", j);
                sleep(0.5);
                printf("\b");
            }
        }
    }
}
