#include <stdio.h>
#include "farnarkle.h"

// If a farnarkle exists
int int_exists(int j, int match[N_TILES]) {
	int i = 0;
	while (i < N_TILES) {
		if ( j == match[i]) {
			return 1;
		}		
		i = i + 1;
	}
	return 0;
}

int count_arkles(int sequence1[N_TILES], int sequence2[N_TILES]) {

	int i, j, arkles, match[N_TILES] = {-1};
	
	i = 0;
	j = 0;
	arkles = 0;

	while (i < N_TILES) {
		match[i] = -1;
		i = i + 1;
	}

	i = 0;
	j = 0;
	
	while (i < N_TILES) {
		j = 0;
        while (j < N_TILES) {
			if (sequence1[i] == sequence2[j] && !int_exists(j, match)) {
				if ((sequence1[i] != sequence2[i]) && sequence1[j] != sequence2[j]) {
					match[i] = j;
					arkles = arkles + 1;
					break;		
				}
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return arkles;
}
