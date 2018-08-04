#include <stdio.h>

int main(int argc, char *argv[]) {

    int s[1000];
    int length;
    int i = 0;
    int j = 0;
    int count = 0;

    while (scanf("%d", &s[i]) != EOF) {
        i++;
    }
    length = i;
    i = 0;
    printf("Indivisible numbers: ");
    while (i < length) {
        j = 0;
        count = 0;
        while (j < length) {
            if (s[i] % s[j] != 0) {
                count++;
               if (count == length - 1) {
                    printf("%d ", s[i]);
                } 
            }
            j++;
        } 
        i++;
    }  
    printf("\n");
    return 0;
}
