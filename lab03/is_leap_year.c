// Is it a leap year? program
// 12/03/2017
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h> 

int main(void) {    
    int year;
    printf("Enter year: ");
    scanf("%d", &year);
    if (year % 4 != 0 || (year % 400 != 0 && year % 100 == 0 )) {
    	printf("%d is not a leap year.\n", year);
    } else {
    	printf("%d is a leap year.\n", year);
    }
    return 0;
}
