// Finding all the leap years within a range of years
// 12/03/2017	
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>

int main(void) {

    int start_year, finish_year, leap_year;
    printf("Enter start year: ");
    scanf("%d", &start_year);    
    printf("Enter finish year: ");
    scanf("%d", &finish_year);

	leap_year = start_year - 1;

	printf("The leap years between %d and %d are: ", start_year, finish_year);
	while (leap_year >= start_year - 1 && leap_year <= finish_year - 1) { 
		leap_year = leap_year + 1; 
		if ((leap_year % 4 == 0 && leap_year % 100 != 0) || leap_year % 400 == 0) {
			printf("%d ", leap_year);
		}
	}
	printf("\n");
    return 0;
}
