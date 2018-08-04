#include <stdio.h>

int main(void) {

    int s[10];
    int i = 0;

    while (i < 10) {
        scanf("%d", &s[i]);
        i++;
    }
    i = 0;
    printf("Odd numbers were: ");
    while (i < 10) {
        if (s[i] % 2 != 0) {
            printf("%d ", s[i]);
        }
        i++;
    }
    printf("\n");
    printf("Even numbers were: ");
    i = 0;
    while (i < 10) {
        if (s[i] % 2 == 0) {
            printf("%d " , s[i]);
        }
        i++;
    }
    printf("\n");
    return 0;
}
