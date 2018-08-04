#include <stdio.h>
#include "trader_bot.h"

int nearest_fuel(struct bot *b) {

    int backwards = 0;
    int forwards = 0;
    struct location *current = b->location;
    
    current = b->location;
    while (current->type != LOCATION_PETROL_STATION) {
        forwards++;
        current = current->next;
    }
    
    current = b->location;
    while (current->type != LOCATION_PETROL_STATION) {
        backwards++;
        current = current->previous;
    }
    
    if (backwards < forwards) {
        return (-1) * backwards;
    } else {
        return forwards;
    }
}
