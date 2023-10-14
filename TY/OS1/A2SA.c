#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
char comm[100], *ptr;
char *args[10];
int tot;
int count(char *option, char *fname);
int sep_args();
int getcomm();
int take_action();
int main()
{
    do
    {
        printf("myshell$");
        getcomm();
        sep_args();
        take_action();
    } while (1);
    return 0;
}
int getcomm()
{
    int len;
    ptr = fgets(comm, 80, stdin);
    len = strlen(comm);
    comm[len - 1] = '\0';
    return 0;
}
int sep_args()
{
    int i, j;
    char *token;
    i = j = tot = 0;
    token = strtok(comm, " ");
    while (token != NULL)
    {
        args[tot] = (char *)malloc(20);
        strcpy(args[tot++], token);
        token = strtok(NULL, " ");
    }
    return 0;
}
int take_action()
{
    char str[100];
    pid_t pid;
    int status;
    ptr = comm;
    if (ptr == NULL)
        return 0;
    if (strlen(comm) <= 1)
        return 0;
    if (strcmp(args[0], "count") == 0)
        count(args[1], args[2]);
    else if ((pid = fork()) < 0)
    {
        printf("\n unable to create process");
        return 0;
    }
    else if (pid == 0)
    {
        execvp(args[0], args);
        strcpy(str, "./");
        strcat(str, args[0]);
        execvp(str, args);
        printf("\n %s:command not found", comm);
        return 0;
    }
    else
        waitpid(pid, &status, 0);
    return 0;
}
int count(char *option, char *fname)
{
    int ccnt, wcnt, lcnt, wflag;
    int ch;
    FILE *fp;
    int i;
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("\n unable to open file");
        exit(0);
    }
    ccnt = wcnt = lcnt = 0;
    wflag = 0;
    ch = fgetc(fp);
    while (ch != EOF)
    {
        ccnt++;
        if (ch == ' ' || ch == '\t')
        {
            if (wflag == 0)
            {
                wcnt++;
                wflag = 1;
            }
        }
        else if (ch == '\n')
        {
            lcnt++;
            if (wflag == 0)
            {
                wcnt++;
                wflag = 1;
            }
        }
        else
        {
            wflag = 0;
        }
        ch = fgetc(fp);
    }
    if (wflag == 0)
    {
        wcnt++;
        lcnt++;
    }
    fclose(fp);
    if (strcmp(option, "c") == 0)
    {
        printf("\n Total characters=%d\n", ccnt);
    }
    else if (strcmp(option, "w") == 0)
    {
        printf("\n Total words=%d\n", wcnt);
    }
    else if (strcmp(option, "l") == 0)
    {
        printf("\n Total lines=%d\n", lcnt);
    }
    else
        printf("\n invalid option");
    return 0;
}