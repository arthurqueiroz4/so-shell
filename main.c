#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        
        puts(input);
    }
}