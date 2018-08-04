// Reading an integer n and printing it out in an n*n pattern in the shape of an "x"
// 18/03/2017
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>

int main(void) {

	int n, a, b;
	printf("Enter size: ");
	scanf("%d", &n);

	a = 0;

	while (a < n) {
		b = 0;
		while (b < n) {
			if (a == b || b == (n - a - 1)) {
				printf("*");
			} else { 
				printf("-");
			}
		b = b + 1;
		}
		if (a % n == 0 || b % n == 0) {
			printf("\n");
		}
		a = a + 1;
	}	
	return 0;
}
