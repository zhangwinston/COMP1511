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

	int x, y , z;
	x = a;
	y = b;
	z = c;
	
	(a < b) && (x = a, y = b);
	(a >= b) && (x = b, y = a);
	(c >= y) && (z = c);
	(c < y) && (z = y);
	(c < y) && (y = c);
	(c < x) && (y = x);
	(c < x) && (x = c);

	printf("The integers in order are: %d %d %d\n", x, y, z);
	

	return 0;
}
