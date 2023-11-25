#include <stdio.h>
#include <string.h>

int main()
{
    int MAX_STRING = 100;
    int MAX_TOKEN = 10;
    char cmd[MAX_STRING];
    char *tokens[MAX_TOKEN];
    char *token;

    while(1)
    {
    printf("~myshell$-> ");
    fgets(cmd, MAX_STRING, stdin);

    int tcount = 0;
    token = strtok(cmd, " \n");
    while(token != NULL && tcount < MAX_TOKEN)
    {
        tokens[tcount++] = token;
        token = strtok(NULL, " \n");
    }
    tokens[tcount] = NULL;
    for(int i = 0;i<tcount;i++)
        printf("%s\n",tokens[i]);
    if(strcmp(tokens[0],"exit") == 0)
        break;
    printf("\n%d   '%s'\n",strcmp(tokens[0],"exit"),tokens[0]);
    // scanf("%s", &cmd);
    // printf(cmd);
    // printf(strtok(cmd, " "));
    }
}