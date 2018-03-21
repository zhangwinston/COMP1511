// Function written for COMP1511 assignment 2
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>
#include "trader_bot.h"
#include "trader.h"

//Function written for week 10 lab exercises
//Checks for the nearest fuel station
//Returns closest distance to fuel station
int nearest_fuel(struct bot *b) {
    int backwards = 1;
    int forwards = 1;
    struct location *current = b->location;
    
    current = b->location->next;
    while (current->type != LOCATION_PETROL_STATION) {
        forwards++;
        current = current->next;
    }
    
    current = b->location->previous;
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

//Function written for COMP1511 assignment 2
//Checks for the nearest buyer
//Returns closest distance to buyer
int nearest_buyer(struct bot *b) {
    int backwards = 1;
    int forwards = 1;
    struct location *current = b->location;
    
    current = b->location->next;
    while (current->type != LOCATION_BUYER) {
        forwards++;
        current = current->next;
    }
    
    current = b->location->previous;
    while (current->type != LOCATION_BUYER) {
        backwards++;
        current = current->previous;
    }    
    if (backwards < forwards) {
        return (-1) * backwards;
    } else {
        return forwards;
    }
}
