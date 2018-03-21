//Function for COMP1511 assignment 2
//By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trader_bot.h"
#include "trader.h"

//Finding a location that will buy for highest price, then moving to a location that sells that type of commodity
int move_best_seller(struct bot *b) {
    struct location *cur = b->location->next;
    struct location *start = b->location;
    struct location *best = b->location;
    int temp = 0;

    cur = start->next;
    while (cur != start) {                          
        if (cur->type == LOCATION_BUYER) {
            if (cur->quantity != 0) {
                if (cur->price > temp) {
                    temp = cur->price;                  //Searching for the location which will buy for the highest price
                    best = cur;                         //then saving the location
                }
            }
        }
        cur = cur->next;
    }
    if (start->type == LOCATION_BUYER) {
        if (start->price >= best->price) {
            best = start;
        }
    }
    cur = start->next;
    int forwards = 1;
    while (cur != start) {  
        if (cur->type == LOCATION_SELLER) {                                             //Finding the closest distance to get to a seller than sells the commodity of the "best" location
            if (strcmp(cur->commodity->name, best->commodity->name) == 0) {
                break;
            }
        }
        forwards++;
        cur = cur->next;
    }
    cur = start->previous;
    int backwards = 1;
    while (cur != start) {
        if (cur->type == LOCATION_SELLER) {
            if (strcmp(cur->commodity->name, best->commodity->name) == 0) {
                break;
            }
        }
        backwards++;
        cur = cur->previous;
    }

    if (backwards < forwards) {                                                         //Returns distance to the closest seller of that commodity
        return -1* backwards;
    } else {
        return forwards;
    }
}

//Function that looks for the buyer that will buy the cargo commodity for the highest price
//Moves to that location
int move_best_buyer(struct bot *b) {
    struct location *cur = b->location->next;
    struct location *start = b->location;
    struct location *best;
    int temp = 0;
    while (cur != start) {
        if (cur->type == LOCATION_BUYER) {
            if (strcmp(b->cargo->commodity->name, cur->commodity->name) == 0) {
                if (cur->quantity != 0) {
                    if (cur->price > temp) {
                        temp = cur->price;
                        best = cur;
                    }
                }
            }
        }
        cur = cur->next;
    }
    cur = start->next;
    int forwards = 1;
    while (cur != best) {
        forwards++;
        cur = cur->next;
    }
    cur = start->previous;
    int backwards = 1;
    while (cur != best) {
        backwards++;
        cur = cur->previous;
    }

    if (backwards < forwards) {
        return -1* backwards;
    } else {
        return forwards;
    }
}   
