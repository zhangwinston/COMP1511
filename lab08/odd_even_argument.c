#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        
    int s[1000];
    int i = 0;
    int j = 1;

    while (j < argc) {
        while (i < j) {
            s[i] = atoi(argv[j]);
            i++;    
        }
        j++;
    }

    i = 0;
    printf("Odd numbers were: ");
    while (i < argc - 1) {
        if (s[i] % 2 == 1 || s[i] % 2 == -1) {
            printf("%d ", s[i]);
        }
        i++;
    }
    printf("\n");
    i = 0;
    printf("Even numbers were: ");
    while (i < argc - 1) {
        if (s[i] % 2 == 0) {
            printf("%d ", s[i]);
        }
        i++;
    } 
    printf("\n");
    return 0;
}
     
