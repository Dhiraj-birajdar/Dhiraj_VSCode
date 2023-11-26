//also repeated in slip no :- 16 , 24

/*
Q] Write a C program that behaves like a shell which displays the command prompt ‘myshell$’. It 
accepts the command, tokenize the command line and execute it by creating the child process. 
Also implement the additional command ‘count’ as


myshell$ count c filename: It will display the number of characters in given file
myshell$ count w filename: It will display the number of words in given file
myshell$ count l filename: It will display the number of lines in given file
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define MAX_COMMAND_LENGTH 100
#define MAX_TOKENS 10


//getting count as per the command (char,words,lines)
int count(char *option, char *filename)
{
    int ccnt = 0;
    int wcnt = 0, lcnt = 0;
    int ch;
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("\n Unable to open file\n");
        exit(0);
    }
    else
    {
        ch = fgetc(fp);
        while (ch != EOF)
        {
            if (ch != ' ' && ch != '\t' && ch != '\n')
                ccnt++;
            if (ch == ' ' || ch == '\t' || ch == '\n')
            {
                wcnt++;
            }

            if (ch == '\n')
            {
                lcnt++;
            }
            ch = fgetc(fp);
        }

        fclose(fp);
    }
    if (strcmp(option, "c") == 0)
    {
        printf("\nTotal characters=%d\n\n", ccnt);
    }
    else if (strcmp(option, "w") == 0)
    {
        printf("\nTotal words=%d\n\n", wcnt + 1); //added one just to get the remaining one word count
    }
    else if (strcmp(option, "l") == 0)
    {
        printf("\nTotal lines=%d\n\n", lcnt + 1); //added one just to get the remaining one line count
    }
    else
    {
        printf("\nInvalid option\n");
    }

    return 0;
}

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];
    char *token;
    const char *delimiters = " \n\t"; //delimiters for tokenization

    while (1) //keeping the shell running
    {
        printf("myshell$ ");
       

        if (fgets(command, sizeof(command), stdin) == NULL) //read the no of characters and stores in the command with the help of fgets and sizeof(command) gives the idea about the total size of the commands
        {
            break;
        }

        int token_count = 0;
        token = strtok(command, delimiters);
		//tokenizing the command
        while (token != NULL && token_count < MAX_TOKENS - 1) 
        {
            tokens[token_count] = token;
            token = strtok(NULL, delimiters);
            token_count++;
        }
        tokens[token_count] = NULL;

        if (token_count >= 3 && strcmp(tokens[0], "count") == 0)
        {
            count(tokens[1], tokens[2]); //cmd args call
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
                // Child process
                if (execvp(tokens[0], tokens) == -1)
                {
                    printf("command not found\n");
                }
            }
            else
            {
                // Parent process
                int status;
                waitpid(pid, &status, 0);
            }
        }
        
    }

    return 0;
}
