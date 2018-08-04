#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int s[1000];
    int i = 0;
    int x = 1;

    while (i < argc && x != argc) {
        s[i] = atoi(argv[x]);
        x++;
        i++;
    }
    int length = i;
    i = 0;
    printf("Odd numbers were: ");
    while (i < length) {
        if (s[i] % 2 != 0) {
            printf("%d ", s[i]);
        }
        i++;
    }
    printf("\n");
    printf("Even numbers were: ");
    i = 0;
    while (i < length) {
        if (s[i] % 2 == 0) {
            printf("%d " , s[i]);
        }
        i++;
    }
    printf("\n");
    return 0;
}
