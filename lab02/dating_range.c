// Dating Age Ranges
// 6/03/2017
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>
	
int main(void) {
    int age, lower_bound_age, upper_bound_age;
    printf("Enter your age: ");
    scanf("%d", &age);
    lower_bound_age = age/2 +7;
    upper_bound_age = (age - 7)*2;
    if (age < 13) {
    	printf("You are too young to be dating.\n");
    } else if (age > 12) {
    	printf("Your dating range is %d to %d years old.\n", lower_bound_age, upper_bound_age);
    }
    return 0;
}
