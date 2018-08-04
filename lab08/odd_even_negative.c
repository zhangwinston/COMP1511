#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int s[1000];
    int j = 0;
    int i;

    while (j < 1000) {
        scanf("%d", &s[j]);
        if (s[j] < 0) {
            break;
        }        
        j++;
    }
    i = j;
    printf("Odd numbers were: ");
    j = 0;
    while (j < i) {
        if (s[j] > 0 && s[j] % 2 == 1) {
            printf("%d ", s[j]);
        }
        j++;
    }
    printf("\n");

    printf("Even numbers were: ");
    j = 0;
    while (j < i) {
        if (s[j] > 0 && s[j] % 2 == 0) {
            printf("%d ", s[j]);
        }
        j++;
    } 
    printf("\n");
    return 0;
}
            
