// Creating a chessboard using "*" and "-"
// 20/03/2017
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
			if (b % 2 == 0 && a % 2 != 0) {
				printf("*");
			} else if (b % 2 != 0 && a % 2 == 0) {
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
