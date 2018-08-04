#include <stdio.h>

int main(void) {

    int s[10];
    int i = 0;

    while (i < 10) {
        scanf("%d", &s[i]);
        i++;
    }
    printf("Numbers were: ");
    i = 0;
    while (i < 10) {
        printf("%d " , s[i]);
        i++;
    }
    printf("\n");
    return 0;
}
