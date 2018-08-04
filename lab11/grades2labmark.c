#include <stdio.h>
#include <stdlib.h>

double grades2labmark(char grades[]) {

    double sum = 0.0;
    int i = 0;
    
    while (grades[i] != '\0') {
        if (grades[i] == '+') {
            sum = sum + 0.2;
        } else if (grades[i] == 'A') {
            sum = sum + 1.0;
        } else if (grades[i] == 'B') {
            sum = sum + 0.8;
        } else if (grades[i] == 'C') {
            sum = sum + 0.5;
        } else if (grades[i] == '.') {
            sum = sum + 0;
        }
        i++;
    }
    return sum;
}

int main (int argc, char *argv[]) {
    
    double sum = grades2labmark(argv[1]);
    
    if (sum < 10) {
        printf("%.1lf\n", sum); 
    } else {
        printf("10.0\n");
    }
    return 0;
}
