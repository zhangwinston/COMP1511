// Print a square with one loop
// 13/03/2017
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>

int main(void) {

	int x, n;
	printf("Square size: ");
	scanf("%d", &x);
	
	n = 0;
	while (n < x * x) {
		printf("*");
		n = n + 1;
		if (n % x == 0) {
			printf("\n");
		}
	}
	return 0;
}
