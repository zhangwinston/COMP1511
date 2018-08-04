// Positive integers divisible by 3 or 5
// 18/03/2017
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>

int main(void) {
	
	int n, i;

	printf("Enter number: ");
	scanf("%d", &n);
	
	i = 3;
	while (i < n) {
		if (i % 3 == 0) {
			printf("%d\n", i);
		} else if (i % 5 == 0) {
			printf("%d\n", i);
		}
		i = i + 1;
	}
	return 0;
}
