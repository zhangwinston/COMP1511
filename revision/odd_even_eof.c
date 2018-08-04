#include <stdio.h>

int main(void) {

    int s[1000];
    int i = 0;

    while (scanf("%d", &s[i]) == 1) {
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
