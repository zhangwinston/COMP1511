#include "trader_bot.h"
int nearest_seller(struct bot *b);
int move_best_seller(struct bot *b);
int move_best_buyer(struct bot *b);
int check_quantity(struct bot *b);
int check_buyers(struct bot *b);
int count_buyers(struct bot *b);
int check_buyer_quantity(struct bot *b);
int nearest_buyer(struct bot *b);
int get_dump(struct bot *b);
int movement(struct bot *b, int distance);
