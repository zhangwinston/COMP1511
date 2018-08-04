#include <stdio.h>

int main(int argc, char *argv[]) {
    char line[4096];
    int i = 0;
    int j = 0;
    int palindrome = 0;

    printf("Enter a string: ");
    fgets(line, 4096, stdin);

    while (line[j] != '\0' && line[j] != '\n') {
        j++;
    }

    if (j == 0) {
        return 0;
    }
    j = j - 1;

    while (i < j) {
        if (line[i] != line[j]) {
            printf("String is not a palindrome\n");
            return 0;
        }
        i++;
        j--;
    }
    printf("String is a palindrome\n");

    return 0;
}
