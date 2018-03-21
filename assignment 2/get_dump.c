// Function written for COMP1511 assignment 2
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>
#include "trader.h"
#include "trader_bot.h"

//Function that checks for the dump location
//Returns closest distance to dump
int get_dump(struct bot *b) {
    struct location *cur = b->location;
    struct location *start = b->location;
    int forwards = 1;
    int backwards = 1;
    cur = cur->next;
    while (cur->type != LOCATION_DUMP) {
        cur = cur->next;
        forwards++;
    }
    cur = start->previous;
    while (cur->type != LOCATION_DUMP) {
        cur = cur->previous;
        backwards++;
    }
    if (backwards < forwards) {
        return (-1) * backwards;
    } else {
        return forwards;
    }
}
