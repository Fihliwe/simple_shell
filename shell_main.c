#include "shell.h"


int main() {
    char input[INPUT_LENGTH];
    
    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            /** perror("fgets"); */
            exit(EXIT_FAILURE);
        }
        
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }
        
        if (strcmp(input, "exit") == 0) {
            _exit(0);
        }
        else if (strncmp(input, "cd", 2) == 0) {
            char *dir = input + 2;
            if (change_dir(dir) != 0) {
                perror("cd");
            }
            continue;
        }
        else if (strncmp(input, "alias", 5) == 0) {
        }
        else {
            int status = command_sep(input);
            if (status != 0) {
                printf("Command failed with exit code %d\n", status);
            }
        }
    }
    
    return 0;
}

