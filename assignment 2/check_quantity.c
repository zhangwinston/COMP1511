// Function written for COMP1511 assignment 2
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>
#include "trader.h"
#include "trader_bot.h"
#include <string.h>
#include <stdlib.h>

//Function that checks for a location willing to buy the cargo commodity
//Returns number of locations available
//eg. 0 = no places willing to buy
int check_quantity(struct bot *b) {
    struct location *cur = b->location;
    struct location *start = b->location;
    int counter = 0;

    if (cur->type == LOCATION_BUYER) {
        if (strcmp(cur->commodity->name, b->cargo->commodity->name) == 0) {
            if (cur->quantity != 0) {
                counter++;
            }
        }
    }
    cur = start->next;
    while (cur != start) {
        if (cur->type == LOCATION_BUYER) {
            if (strcmp(cur->commodity->name, b->cargo->commodity->name) == 0) {
                if (cur->quantity != 0) {
                    counter++;
                }
            }
        }
        cur = cur->next;
    }
    return counter;
}

//Function that checks for buyers that will buy commodity of where bot is
//eg. bot at LOCATION_SELLER selling computers
//Function checks if there are locations willing (quantity != 0) to buy computers
int check_buyers(struct bot *b) {
    struct location *cur = b->location;
    struct location *start = b->location;
    int counter = 0;

    if (cur->type == LOCATION_BUYER) {
        if (strcmp(cur->commodity->name, start->commodity->name) == 0) {
            if (cur->quantity != 0) {
                counter++;
            }
        }
    }
    cur = start->next;
    while (cur != start) {
        if (cur->type == LOCATION_BUYER) {
            if (strcmp(cur->commodity->name, start->commodity->name) == 0) {
                if (cur->quantity != 0) {
                    counter++;
                }
            }
        }
        cur = cur->next;
    }
    return counter;
}

//Function that checks for location that can still buy commodities
//Returns amount it is willing to buy
int check_buyer_quantity(struct bot *b) {
    struct location *cur = b->location;
    struct location *start = b->location;
    struct location *temp;

    cur = start->next;
    while (cur != start) {
        if (cur->type == LOCATION_BUYER) {
            if (strcmp(cur->commodity->name, start->commodity->name) == 0) {
                if (cur->quantity != 0) {
                    temp = cur;
                }
            }
        }
        cur = cur->next;
    }
    return temp->quantity;
}
