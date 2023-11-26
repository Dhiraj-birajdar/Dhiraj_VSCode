//also repeated in slip no :- never repeated

/*
Q] write a C program to implement the shell which displays the 
command prompt "myshell$". It accepts the command , tokenize the 
command line and execute it by creating the child process. 
Also implement the additional command "typeline" as
typeline n filename = to print first n lines in the file
typeline a filename = to print all lines in the file
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_TOKENS 10

// performing actions as per the command
void typeline(char *option, char *filename)
{
    FILE *fp = fopen(filename, "r");
    char line[1024];
    if (strcmp(option, "a") == 0)
    {
        FILE *fp = fopen(filename, "r");
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            printf("%s\n", line);
        }
        fclose(fp);
    }
    // else
    // {
    int n = atoi(option);
    // if (n <= 0)
    // {
    //     printf("Invalid line count: %d\n", n);
    // }
    if (strcmp(option, "n"))
    {
        for (int i = 0; i < n; i++)
        {
            if (fgets(line, sizeof(line), fp) != NULL)
            {
                printf("%s\n", line);
            }
            else
            {
                break; // reached at the end of the file
            }
        }
    }
    fclose(fp);
}

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];
    char *token;
    const char *delimiters = " \n\t"; // delimiters for tokenization

    while (1) // keeping the shell running
    {
        printf("myshell$ ");

        if (fgets(command, sizeof(command), stdin) == NULL) // read the no of characters (by stdin) and stores in the (command) with the help of fgets and sizeof(command) gives the idea about the total size of the commands
        {
            break;
        }

        int token_count = 0;
        token = strtok(command, delimiters);
        // tokenizing the command

        while (token != NULL && token_count < MAX_TOKENS - 1)
        {
            tokens[token_count] = token;
            token = strtok(NULL, delimiters);
            token_count++;
        }
        tokens[token_count] = NULL;

        if (token_count >= 3 && strcmp(tokens[0], "typeline") == 0)
        {
            typeline(tokens[1], tokens[2]);
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
                // child process
                if (execvp(tokens[0], tokens) == -1)
                {
                    printf("command not found\n");
                }
            }
            else
            {
                // parent process
                int status;
                waitpid(pid, &status, 0);
            }
        }
    }
    return 0;
}
