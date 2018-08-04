#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void head(char *filename, int number_lines) {

    int i = 0;
    int ch;

    FILE *f = fopen(filename , "r");
    if (f == NULL) {
        printf("Error!\n");
    }

    while (i < number_lines) {
        ch = fgetc(f);
        if (ch == EOF) {
            fclose(f);
            return;
        }
        putchar(ch);
        if (ch == '\n') {
            i++;
        }
    }

    fclose(f);
}

int main(int argc, char *argv[]) {

    int number_lines = 0;
    char *filename;

    if (argc == 2) {
        number_lines = 10;
        filename = argv[1];
    } else if (argc == 4 && strcmp(argv[1], "-n") == 0) {
        number_lines = atoi(argv[2]);
        filename = argv[3];
    } else {
        printf("Error\n");
    }
    head(filename, number_lines);
    return 0;
}
