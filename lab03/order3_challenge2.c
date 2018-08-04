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

	(a >= b) && (a = a + b) && (b = a - b) && (a = a - b);
	
	(a >= c) && (a = a + c) && (c = a - c) && (a = a - c);

	(b >= c) && (b = b + c) && (c = b - c) && (b = b - c); 

	printf("The integers in order are: %d %d %d\n", a, b, c);

	return 0;
}
