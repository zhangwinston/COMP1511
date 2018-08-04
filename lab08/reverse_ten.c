#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int s[10];
    int j = 0;

    while (j < 10) {
        scanf("%d", &s[j]);
        j++;
    }
    printf("Numbers were: ");
    j = 9;
    while (j >= 0) {
        printf("%d ", s[j]);
        j = j - 1;
    }
    printf("\n");
    return 0;
}
            
