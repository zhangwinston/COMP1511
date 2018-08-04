#include <stdio.h>
#include "farnarkle.h"

int main(void) {
    int hidden_sequence[N_TILES];
	int numGuesses = 1;
	int guess[N_TILES];
	int cf = 0;

    create_random_tiles(hidden_sequence);

	while (cf < N_TILES) {
		printf("Enter guess for turn %d: ", numGuesses);
		read_tiles(guess);
		numGuesses = numGuesses + 1;
		cf = count_farnarkles(hidden_sequence, guess);
		printf("%d farnarkles %d arkles\n", cf, count_arkles(hidden_sequence, guess));
	}
	printf("You win\n");	
	return 0;
}
