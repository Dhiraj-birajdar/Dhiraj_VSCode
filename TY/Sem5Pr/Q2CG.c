#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_TOKENS 10

void search_file(char *filename, char *pattern, int display_all_occurrences) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_COMMAND_LENGTH];
    int line_number = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, pattern) != NULL) {
            if (display_all_occurrences) {
                printf("Line %d: %s", line_number, line);
            } else {
                printf("First occurrence of '%s' found in %s at line %d: %s", pattern, filename, line_number, line);
                break;
            }
        }
        line_number++;
    }

    fclose(file);
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];
    char *token;

    while (1) {
        // Display command prompt
        printf("myshell$ ");
        fgets(command, sizeof(command), stdin);

        // Tokenize the command
        int token_count = 0;
        token = strtok(command, " \n");
        while (token != NULL && token_count < MAX_TOKENS) {
            tokens[token_count++] = token;
            token = strtok(NULL, " \n");
        }
        tokens[token_count] = NULL;  // Set the last token to NULL for execvp

        // Check for the exit command
        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        // Check for the search command
        if (strcmp(tokens[0], "search") == 0 && token_count >= 4) {
            char *file_name = tokens[2];
            char *pattern = tokens[3];
            int display_all_occurrences = (strcmp(tokens[1], "a") == 0);

            // Create a child process
            pid_t pid = fork();

            if (pid == -1) {
                perror("Fork failed");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                // Child process
                search_file(file_name, pattern, display_all_occurrences);
                exit(EXIT_SUCCESS);
            } else {
                // Parent process
                waitpid(pid, NULL, 0);
            }
        } else {
            // Execute other commands
            pid_t pid = fork();

            if (pid == -1) {
                perror("Fork failed");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                // Child process
                execvp(tokens[0], tokens);
                perror("Execution failed");
                exit(EXIT_FAILURE);
            } else {
                // Parent process
                waitpid(pid, NULL, 0);
            }
        }
    }

    return 0;
}
