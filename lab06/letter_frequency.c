#include <stdio.h>
#include <string.h>
    
int main() {
    char sentence[200];
    int i = 0;
    int letter_counter = 0;
    int counter2 = 0;
    double letter_frequency[26] = {0};
    double sum = 0;
    
    while (fgets(sentence, 128, stdin) != NULL) {
        while (sentence[i] != '\0') {
            if (sentence[i] >= 'a' && sentence[i] <= 'z') {
                letter_frequency[sentence[i] - 'a']++;
                letter_counter++;
            }
            if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
                letter_frequency[sentence[i] - 'A']++;
                letter_counter++;
            }
            i++;
        }
        i = 0;
    }
    while (counter2 < 26) {
        sum = (letter_frequency[counter2]/(letter_counter));
        printf("'%c' %lf %.0lf\n", (counter2 + 'a'), sum, letter_frequency[counter2]);
        counter2++;
    }
    return 0;
}
