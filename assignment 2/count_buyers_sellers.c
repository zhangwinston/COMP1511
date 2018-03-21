// Function written for COMP1511 assignment 2
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>
#include "trader_bot.h"
#include "trader.h"

//Function that counts the number of buyers in the world
int count_buyers(struct bot *b) {
    struct location *cur = b->location->next;
    struct location *start = b->location;
    int counter = 0;
    if (start->type == LOCATION_BUYER) {
        counter++;
    }
    while (cur != start) {
        if (cur->type == LOCATION_BUYER) {
            counter++;
        }
        cur = cur->next;
    }
    return counter;
}
