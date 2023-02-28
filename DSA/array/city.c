#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct city
{
    char name[25];
    char std[10];
} city;
int main()
{
    int i, n = 742;
    city a[n];
    char ct[25];
    FILE *f = fopen("city.txt", "r");
    for (i = 0; i < n; i++)
        fscanf(f, "%s%s", a[i].name, a[i].std);
    fclose(f);
    printf("Enter city name : ");
    scanf("%s", ct);
    for (i = 0; i < n; i++)
    {
        if (!stricmp(ct, a[i].name))
        {
            printf("\nCity : %s\tSTD : %s\n", a[i].name, a[i].std);
            exit(0);
        }
    }
    printf("City \"%s\" not found. please enter valid city name.", ct);
    // for (i = 0; i < n; i++)
    //     printf("%-23s%s\n", a[i].name, a[i].std);
    return 0;
}