#include <stdio.h>

int main(int argc, char *argv[]) {

    int s[1000];
    int j;
    int i = 0;

    while (scanf("%d", &s[i]) != EOF) {
        i++;
    }
    j = i;
    i = 0;
    printf("Odd numbers were: ");
    while (i < j) {
        if (s[i] % 2 != 0) {
            printf("%d ", s[i]);
        }
        i++;
    }
    printf("\n");

    printf("Even numbers were: ");
    i = 0;
    while (i < j) {
        if (s[i] % 2 == 0) {
            printf("%d ", s[i]);
        }
        i++;
    } 
    printf("\n");
    return 0;
}
            
