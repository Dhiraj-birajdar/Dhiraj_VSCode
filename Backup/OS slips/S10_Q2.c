// also repeated in slip no :-

/*
Write a C program that behaves like a shell which displays the command prompt ‘myshell$’. It
accepts the command, tokenize the command line and execute it by creating the child process.
Also implement the additional command ‘list’ as

myshell$ list f dirname: It will display filenames in a given directory.
myshell$ list i dirname: It will display filenames and their inode number for the files in a given
directory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_TOKENS 10

void list_files(char *dirname, int count_entries)
{
    struct dirent *entry;
    
    DIR *dp = opendir(dirname); //(DIR) is a structure that allows you to handle the functionality of directory or directory path by using its diffrenet inbuilt functions such as (opendir , etc)

    // counting the entries()
    while ((entry = readdir(dp)))
    {
        if (entry->d_name[0] != '.')
        {
            if (count_entries == 0)
            {
                printf("%s\n", entry->d_name);
            }
            else
            {
                struct stat st;
                char path[300];
                snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);  //get full path to the file/directory
                if (stat(path, &st) == 0)  //gets the file attributes (information about file) from the file and put them into buffer
                {
                    printf("%s: %d\n", entry->d_name, (int)st.st_ino);  //printing the filenames present in the directory and their respective inodes
                }
                else
                {
                    perror("stat");
                }
            }
        }
    }

    closedir(dp);
}

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];
    char *token;
    const char *delimiters = " \n\t"; // delimiters for tokenization

    while (1)
    {
        printf("myshell$ ");
        fflush(stdout);

        // To break out of the loop or to exit the execution of myshell ex:- pressing ctrl+c
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }

        // tokenizing the command
        int token_count = 0;
        token = strtok(command, delimiters); // breaks/splits the command into its individual string and store it into token

        while (token != NULL && token_count < MAX_TOKENS - 1)
        {
            tokens[token_count] = token;      // assigning individual token with its individual number into variable tokens
            token = strtok(NULL, delimiters); // continuing tokenizing
            token_count++;
        }
        tokens[token_count] = NULL; // Set the last token to NULL so the new input command will get tokenize as per the iterations

        if (token_count >= 3 && strcmp(tokens[0], "list") == 0) // checks if the first command is list or not
        {
            if (strcmp(tokens[1], "f") == 0)
            {
                list_files(tokens[2], 0);
            }
            else if (strcmp(tokens[1], "i") == 0)
            {
                list_files(tokens[2], 1);
            }
            else
            {
                printf("Invalid 'list' command format\n");
            }
        }

        else
        {
            // fork a child process to execute the command
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
                    perror("execvp");
                }
                exit(EXIT_FAILURE);
            }
            else
            {
                // parent process
                int status;
                waitpid(pid, &status, 0); //waits for child to completes its process
            }
        }
    }
    return 0;
}
