#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define TRUE 1


int main() {
  while (TRUE) {
    printf("$ - ");
    char *input = malloc(100);
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, "exit") == 0) {
      puts("Desligando...");
      break;
    }

    char *command;
    char **args = malloc(90);

    if (strlen(input) > 1) {
        command = strtok(input, " ");
        args[0] = command;
        int i = 1;
        while (args[i] == NULL) {
            args[i] = strtok(NULL, " ");
            i++;
        }
    }

    pid_t child_pid;
    if ((child_pid = fork()) == 0) {
      execvp(command, args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(child_pid, &status, 0);
    }
  }
}