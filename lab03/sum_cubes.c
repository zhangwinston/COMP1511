// Finding the sum of cubes
// 13/03/2017
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h> 

int main(void) {
	
	int n, c, sum, cube;
	printf("Sum how many cubes? ");
	scanf("%d", &c);

	n = 1;
	sum = 0;
	while (n <= c) {
		printf("%d^3", n);
		if (n <= c - 1 ) {
			printf(" + ");
		}
	    sum = sum + n * n * n;
	    n = n + 1;
	}
	printf(" = %d\n", sum);
	return 0;
}
