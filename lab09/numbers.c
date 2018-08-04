#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    char line[2048];
    int i = 0;
    int j;

    while (start <= end) {
        line[i] = start;
        i++;
        start++;
    }

    j = i;
    i = 0;

    FILE *f = fopen(argv[3], "w");
    if (f == NULL) {
        printf("Error!");
        return 1;
    }
    while (i < j) {
        fprintf(f, "%d\n", line[i]);
        i++;
    }

    fclose(f);
    return 0;
}    
