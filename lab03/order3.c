// Ordering three integers
// 12/03/2017
// By Anthony Xu - z561674@unsw.edu.au

#include <stdio.h>

int main(void) {
    int a, b, c;

    printf("Enter integer: ");
    scanf("%d", &a);
    printf("Enter integer: ");
    scanf("%d", &b);
    printf("Enter integer: ");
    scanf("%d", &c);
    printf("The integers in order are: ");

    if (a <= b && b <= c) {
        printf("%d %d %d\n", a, b, c);
    } else if (b <= a && a <= c) {
    	printf("%d %d %d\n", b, a, c); 
    } else if (c <= b && b <= a) {
    	printf("%d %d %d\n", c, b, a);
    } else if (a <= c && c <= b) {
    	printf("%d %d %d\n", a, c, b);
    } else if (c <= a && a <= b) {
    	printf("%d %d %d\n", c, a, b);
    } else {
    	printf("%d %d %d\n", b, c, a);
    }
    return 0;
}
