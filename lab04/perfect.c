// Prints all factors of n, the sum of the factors and states if n is a perfect number
// 18/03/2017
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>

int main(void) {
	
	int n, i, sum;
	printf("Enter number: ");
	scanf("%d", &n);

	i = 1;
	sum = 0;

	printf("The factors of %d are:\n", n);
	
	while (i <= n) {
		if (n % i == 0) {
			printf("%d\n", i);
			sum = sum + i;
		}
		i = i + 1;
	}
	printf("Sum of factors = %d\n", sum);
	
	if (sum - n == n) {
		printf("%d is a perfect number\n", n);
	} else {
		printf("%d is not a perfect number\n", n);
	}
	return 0;
}
