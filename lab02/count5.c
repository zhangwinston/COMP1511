// Converting Numbers to Words
// 6/03/2017
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>

int main(void) {
    int number;
    printf("Please enter an integer: ");
    scanf("%d", &number);
    if ((number < 1)) {
    	printf("You entered a number less than one.\n");
    } else if ((number > 5)) {
    	printf("You entered a number greater than five.\n");
    } else if (number == 1) {
    	printf("You entered one.\n");
    } else if (number == 2) {
    	printf("You entered two.\n");
    } else if (number == 3) {
    	printf("You entered three.\n");
    } else if (number == 4) {
    	printf("You entered four.\n");
    } else if (number == 5) {
    	printf("You entered five.\n");
    }
    return 0;
}
