#include <stdio.h>
void display(char *l)
{
    int i;
    printf("\n");
    for (i = 0; i < 15; i++)
    {
        printf("%c", l[i]);
        if ((i + 1) % 5 == 0)
            printf("\n");
    }
    printf("\n");
}
int main()
{
    char l[] = {'1', '|', '2', '|', '3', '4', '|', '5', '|', '6', '7', '|', '8', '|', '9'}, c;
    printf("---|| Tic Tac Toe ||---\n");
    display(l);
    int i;
    while (1)
    {
        printf("Player 1 (#): ");
        scanf(" %c",&c);
        for (i = 0; i < 15; i++)
            if (l[i] == c)
            {
                l[i] = '#';
                break;
            }
        display(l);
        if ((l[0] == l[2] && l[2] == l[4]) || (l[5] == l[7] && l[7] == l[9]) || (l[10] == l[12] && l[12] == l[14]) || (l[0] == l[5] && l[5] == l[10]) || (l[2] == l[7] && l[7] == l[12]) || (l[4] == l[9] && l[9] == l[14]) || (l[0] == l[7] && l[7] == l[14]) || (l[4] == l[7] && l[7] == l[10]))
        {
            printf("\n -----|| player 1 (#) won! ||-----\n");
            return 0;
        }
        printf("Player 2 (*): ");
        scanf(" %c",&c);
        for (i = 0; i < 15; i++)
            if (l[i] == c)
            {
                l[i] = '*';
                break;
            }
        display(l);
        if ((l[0] == l[2] && l[2] == l[4]) || (l[5] == l[7] && l[7] == l[9]) || (l[10] == l[12] && l[12] == l[14]) || (l[0] == l[5] && l[5] == l[10]) || (l[2] == l[7] && l[7] == l[12]) || (l[4] == l[9] && l[9] == l[14]) || (l[0] == l[7] && l[7] == l[14]) || (l[4] == l[7] && l[7] == l[10]))
        {
            printf("\n -----|| player 2 (*) won! ||-----\n");
            return 0;
        }
    }
}