// Printing an input integer into a decomposition of prime factors
// 20/03/2017
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>

int main(void) {
	
	int n, a, x, integer;
	printf("Enter number: ");
	scanf("%d", &integer);
		
	
	a = 2;
	x = 0;
	n = integer;

	while (a < integer) {
		if (n % a == 0) {
			if (x == 0) {
				printf("The prime factorization of %d is:\n", integer);
			} else { 
				printf(" * ");
			}
			printf("%d", a);
			n = n / a;
			x = x + 1;	
		} else {
			a = a + 1;
		}
	}
	if (x == 0) {
		printf("%d is prime\n", integer);
	} else { 
		printf(" = %d\n", integer);
	}
	return 0;
}



