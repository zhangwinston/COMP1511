#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int s[10];
    int j = 0;

    while (j < 10) {
        scanf("%d", &s[j]);
        j++;
    }
    printf("Odd numbers were: ");
    j = 0;
    while (j < 10) {
        if (s[j] % 2 == 1) {
            printf("%d ", s[j]);
        }
        j++;
    }
    printf("\n");

    printf("Even numbers were: ");
    j = 0;
    while (j < 10) {
        if (s[j] % 2 == 0) {
            printf("%d ", s[j]);
        }
        j++;
    }
    printf("\n");
    return 0;
}
            
