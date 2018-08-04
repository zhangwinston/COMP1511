#include <stdio.h>

int main(int argc, char *argv[]) {

    char line[4096];
    int i = 0;

    printf("Enter a string: ");

    if (fgets(line, 4096, stdin) != NULL) {
        i = 0;          
        while (i < 4096 && line[i] != '\n' && line[i] != '\0') {
            printf("%c\n", line[i]);
            i++;
        }
    }
    return 0;
}
