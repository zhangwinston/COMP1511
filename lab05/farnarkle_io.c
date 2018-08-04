#include <stdio.h>
#include "farnarkle.h"

int read_tiles(int tiles[N_TILES]) {
	int i = 0, success = 1;

	while (i < N_TILES) {
		if (scanf("%d", &tiles[i]) == 1) {
		} else {
			success = 0;
		}
		i = i + 1;
	} 
	if (success == 1) {
		return 1;
	} else {
		return 0;
	}
}

void print_tiles(int tiles[N_TILES]) {
	int i = 0;
	while (i < N_TILES) {
		printf("%d ", tiles[i]);
		i = i + 1;
	}
    printf("\n");
}
