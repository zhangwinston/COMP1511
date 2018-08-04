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
    j = 0;
    while (j < 10) {
        printf("%d ", s[j]);
        j++;
    }
    printf("\n");
    return 0;
}
            
