#include <stdio.h>

int main(void) {

    int s[1000];
    int i = 0;

    while (scanf("%d", &s[i]) == 1) {
        i++;
    }
    int length = i;
    i = 0;
    int a[1000];
    while (i < length) {
        a[i] = s[i];
        i++;
    }
    i = 0;
    int j = 0;
    int counter = 0;
    printf("Indivisible numbers: ");
    while (i < length) {
        counter = 0;
        j = 0;
        while (j < length) {
            if (s[i] % a[j] == 0) {
                counter++;
            }
            j++;
        }
        if (counter == 1) {
            printf("%d ", s[i]);
        }
        i++;
    }
    printf("\n");
    return 0;           
}
