// Finding the cubes from 1 to n
// 12/03/2017
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>

int main(void) {
     
    int n, i;
    printf("Enter how many cubes: ");
    scanf("%d", &i);
    n = 1;
    while (n <= i) {
        printf("%d^3 = %d\n", n, n * n * n);
    	n = n + 1;
    }
    return 0;
}
