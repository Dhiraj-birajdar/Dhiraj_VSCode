#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_TOKENS 10

void execute_command(char *tokens[]) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(tokens[0], tokens);
        perror("Execution failed");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, NULL, 0);
    }
}

void search_file(char *filename, char *pattern, int disall) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_COMMAND_LENGTH];
    int line_number = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, pattern) != NULL) {
            if (disall) {
                printf("Line %d: %s", line_number, line);
            } else {
                printf("First occurrence of '%s' found in %s at line %d: %s", pattern, filename, line_number, line);
                fclose(file);
                return;
            }
        }
        line_number++;
    }

    fclose(file);
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];

    while (1) {
        printf("myshell$ ");
        fgets(command, sizeof(command), stdin);

        int token_count = 0;
        char *token = strtok(command, " \n");
        while (token != NULL && token_count < MAX_TOKENS) {
            tokens[token_count++] = token;
            token = strtok(NULL, " \n");
        }
        tokens[token_count] = NULL;

        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        if (strcmp(tokens[0], "search") == 0 && token_count >= 4) {
            char *file_name = tokens[2];
            char *pattern = tokens[3];
            int disall = (strcmp(tokens[1], "a") == 0);

            search_file(file_name, pattern, disall);
        } 
        else {
            execute_command(tokens);
        }
    }

    return 0;
}
