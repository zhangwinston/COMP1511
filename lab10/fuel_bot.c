#include <stdio.h>
#include "trader_bot.h"
#include <string.h>
#include <stdlib.h>

char *get_bot_name(void) {
    return "Fuel Bot";
}

void get_action(struct bot *b, int *action, int *n) {

    struct location *current = b->location;
    
    if (current->type == LOCATION_PETROL_STATION) {
        if (b->fuel < b->fuel_tank_capacity) {
            *action = ACTION_BUY;
            *n = b->fuel_tank_capacity - b->fuel;
        } else {
            *action = ACTION_MOVE;
            *n = b->maximum_move;
        }
    } else {
        int distance = nearest_fuel(b);
        *action = ACTION_MOVE;
        if (abs(distance) < b->maximum_move) {
            *n = distance;
        } else {
            if (distance < 0) {
                *n = -1*b->maximum_move;
            } else {
                *n = b->maximum_move;
            }
        }
    }
}
