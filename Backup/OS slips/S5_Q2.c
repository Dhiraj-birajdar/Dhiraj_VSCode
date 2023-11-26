//also repeated in slip no :- 8 

/*
Write a C program that behaves like a shell which displays the command prompt ‘myshell$’. It 
accepts the command, tokenize the command line and execute it by creating the child process. 
Also implement the additional command ‘search’ as

myshell$ search f filename pattern : It will search the first occurrence of pattern in the given 
file
myshell$ search c filename pattern : It will count the number of occurrence of pattern in the 
given file
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TOKENS 10
#define MAX_COMMAND_LENGTH 100


int search(char *option, char *pattern, char *filename)
{
    char line[1024], *ptr;
    int cnt = 0;
    FILE *fp;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("\nUnable to open the file\n");
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        switch (*option)
        {
        case 'f':
             ptr = strstr(line, pattern);
            if (ptr != NULL)
            {
                printf("%s\n", line);
                //fclose(fp);
                return 0; // Stop searching after finding the first occurrence
            }
            break;

        case 'c':
            ptr = strstr(line, pattern);
            while (ptr != NULL)
            {
                cnt++;
                ptr = ptr + strlen(pattern);
                ptr = strstr(ptr, pattern);
            }
            break;

        default:
            printf("Invalid option: %c\n", *option);
            fclose(fp);
            exit(1); // forcefully terminate if some error happens
        }
    }
    if (*option == 'c')
        printf("\nThe search string %s occurs %d times\n", pattern, cnt);
    fclose(fp);
}


void main()
{
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];
    char *token;
    char *delimiters = " \t\n";

    while (1)
    {
        printf("myshell$ ");

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }

        int token_count = 0;
        token = strtok(command, delimiters);

        while (token != NULL && token_count < MAX_TOKENS - 1)
        {
            tokens[token_count] = token;
            token = strtok(NULL, delimiters);
            token_count++;
        }
        tokens[token_count] = NULL;

        if (token_count >= 4 && strcmp(tokens[0], "search") == 0)
        {
            search(tokens[1], tokens[2], tokens[3]);
        }
        else
        {
            pid_t pid = fork();

            if (pid < 0)
            {
                perror("fork");
            }
            else if (pid == 0)
            {
                if (execvp(tokens[0], tokens) == -1)
                {
                    printf("command not found\n");
                }
            }
            else
            {
                int status;
                waitpid(pid, &status, 0);
            }
        }
    }
}