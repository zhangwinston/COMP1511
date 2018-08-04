// A program which reads an input and removes all lowercase vowels when outputting
// 3/04/2017
// By Anthony Xu - z5165674@unsw.edu.au


#include <stdio.h>

int main(void) {

	int c;
	
	c = getchar();
	while (c != EOF) {
		if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
			putchar(c);
		}
		c = getchar();
	}
	return 0;
}
