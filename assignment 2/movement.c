//Function written for COMP1511 assignment 2
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>
#include "trader_bot.h"
#include "trader.h"
#include <stdlib.h>

//Function to calculate the movement of bot
//if the distance is greater than max move
//distance moved is max move in respective direction
//(postive or negative)
int movement(struct bot *b, int distance) {
    int max_move = b->maximum_move;

    if (abs(distance) < max_move) {
        return distance;
    } else {
        if (distance < 0) {
            return -1*max_move;
        } else {                                            
            return max_move;
        }
    }
}
