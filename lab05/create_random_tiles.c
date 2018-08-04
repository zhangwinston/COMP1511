#include <stdlib.h>
#include <time.h>
#include "farnarkle.h"


void create_random_tiles(int tiles[N_TILES]) {
    int i;
	
	srand(time(NULL));

    i = 0;
    while (i < N_TILES) {
        tiles[i] = rand() % MAX_TILE + 1;
        i = i + 1;
    }
}

