#define N_TILES 4
#define MAX_TILE 8

int read_tiles(int tiles[N_TILES]);
void print_tiles(int tiles[N_TILES]);
int count_farnarkles(int sequence1[N_TILES], int sequence2[N_TILES]);
int count_arkles(int sequence1[N_TILES], int sequence2[N_TILES]);
void create_random_tiles(int tiles[N_TILES]);
