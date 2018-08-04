#include <stdio.h>

int main(void) {

    int s[10];
    int i = 0;

    while (i < 10) {
        scanf("%d", &s[i]);
        i++;
    }
    printf("Numbers were: ");
    i = 9;
    while (i >= 0) {
        printf("%d " , s[i]);
        i = i - 1;
    }
    printf("\n");
    return 0;
}
