// Program for COMP1511 assignment 2
// Creating a bot to buy and sell things for the greatest profit
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>
#include "trader_bot.h"
#include "trader.h"
#include <string.h>
#include <stdlib.h>

#define OUT_OF_TIME 5
#define PERCENTAGE_OF_FUEL 0.25

// Function that names the bot
char *get_bot_name(void) {
    return "AntBot";
}

// Function that controls the bot's movement
void get_action(struct bot *b, int *action, int *n) {
    
    struct location *current_location = b->location;

    int fuel_capacity = b->fuel_tank_capacity;
    int fuel = b->fuel*1.0;
    int turns_left = b->turns_left;
    
    // When the bot is at the start
    if (current_location->type == LOCATION_START) {
        *action = ACTION_MOVE;
        if (b->cargo == NULL) {                                     //Checks to see if the bot is carrying anything
            int distance = move_best_seller(b);                     //if it is empty, find commodity that will sell for highest price
            int temp = movement(b, distance);                       //go to location that sells that commodity
            *n = temp;
        } else {                                                    //If the cargo isn't empty
            int check = check_quantity(b);                          //check_quantity(b) checks the world to see if there are any
            if (check == 0) {                                       //buyers that will buy the commodity the bot is carrying
                int distance = get_dump(b);                         //if not, dump the cargo
                int temp = movement(b, distance);
                *n = temp;
            } else {                                                //if it can find a buyer, move to that buyer
                int distance = move_best_buyer(b);                  //if distance is greater than maximum move, distance will be maximum move
                int temp = movement(b, distance);                   //This code is used repeatedly throughout the program
                *n = temp;
            }
        }
    }

    if (current_location->type == LOCATION_PETROL_STATION) {        
        if (current_location->quantity == 0) {                      //Moves to another fuel station if the current station has run out
            *action = ACTION_MOVE;
            int distance = nearest_fuel(b);
            int temp = movement(b, distance);
            *n = temp;
        } else {
            if (fuel <= fuel_capacity*PERCENTAGE_OF_FUEL) {         //Buys fuel if it has less than PERCENTAGE_OF_FUEL of the capacity
                if (turns_left > OUT_OF_TIME) {                     
                    *action = ACTION_BUY;
                    *n = fuel_capacity - fuel;
                } else {
                    *action = ACTION_MOVE;                          //Doesn't buy fuel if there are less than 5 turns left
                    *n = 0;
                }
            } else {
                if (b->cargo != NULL) {
                    int check = check_quantity(b);
                    if (check == 0) {
                        *action = ACTION_MOVE;
                        int distance = get_dump(b);
                        int temp = movement(b, distance);
                        *n = temp;
                    } else {
                        *action = ACTION_MOVE;
                        int distance = move_best_buyer(b);
                        int temp = movement(b, distance);
                        *n = temp;
                    }
                } else {
                    *action = ACTION_MOVE;
                    int distance = move_best_seller(b);
                    int temp = movement(b, distance);
                    *n = temp;
                }
            }
        }
    }

    
    if (current_location->type == LOCATION_SELLER) {
        if (current_location->quantity == 0) {                      //If location has been exhausted (not selling anymore)
            if (fuel <= fuel_capacity*PERCENTAGE_OF_FUEL) {
                *action = ACTION_MOVE;
                int distance = nearest_fuel(b);
                int temp = movement(b, distance);
                *n = temp;
            } else {
                *action = ACTION_MOVE;
                if (b->cargo == NULL) {
                    int distance = move_best_seller(b);
                    int temp = movement(b, distance);
                    *n = temp;
                } else {
                    int check = check_quantity(b);
                    if (check == 0) {
                        int distance = get_dump(b);
                    int temp = movement(b, distance);
                    *n = temp;
                    } else {
                        int distance = move_best_buyer(b);
                        int temp = movement(b, distance);
                        *n = temp;
                    }
                }
            }
        } else {
            if (fuel <= fuel_capacity*PERCENTAGE_OF_FUEL) {         //If bot needs fuel
                if (b->cargo == NULL) {                             //but doesn't have any cargo
                    int buyers = check_buyers(b);                   //check if there are locations that will buy the commodity
                    if (buyers == 1) {                              
                        *action = ACTION_BUY;
                        int number = check_buyer_quantity(b);
                        *n = number;
                    } else if (buyers != 0) {
                        *action = ACTION_BUY;
                        *n = current_location->quantity;
                    } else {
                        *action = ACTION_MOVE;                      //If there are no locations buying that commodity
                        int distance = nearest_fuel(b);
                        int temp = movement(b, distance);
                        *n = temp;
                    }
                } else {
                    *action = ACTION_MOVE;
                    int distance = nearest_fuel(b);
                    int temp = movement(b, distance);
                    *n = temp;
                }
            } else {
                if (b->cargo == NULL) {
                    int buyers = check_buyers(b);                   //Checks if there are places that will buy the commodity
                    if (buyers == 1) {                              //This code is mainly for small worlds with only one buyer
                        *action = ACTION_BUY;
                        int number = check_buyer_quantity(b);       //Buys the quantity of the buying location
                        *n = number;
                    } else if (buyers != 0) {
                        *action = ACTION_BUY;
                        *n = current_location->quantity;            //Buys the amount the location is selling
                    } else {
                        *action = ACTION_MOVE;
                        int distance = move_best_seller(b);
                        int temp = movement(b, distance);
                        *n = temp;
                    }
                } else if (b->cargo != NULL) {
                    int check = check_quantity(b);
                    if (check == 0) {
                        *action = ACTION_MOVE;
                        int distance = get_dump(b);
                        int temp = movement(b, distance);
                        *n = temp;
                    } else {
                        *action = ACTION_MOVE;
                        int distance = move_best_buyer(b);
                        int temp = movement(b, distance);
                        *n = temp;
                    }
                }
            }
        }
    }

    if (current_location->type == LOCATION_BUYER) {
        if (current_location->quantity == 0) {                      //If location has been exhausted (not buying anymore)
            *action = ACTION_MOVE;
            if (fuel <= fuel_capacity*PERCENTAGE_OF_FUEL) {
                int distance = nearest_fuel(b);
                int temp = movement(b, distance);
                *n = temp;
            } else {
                if (b->cargo != NULL) {
                    int check = check_quantity(b);
                    if (check == 0) {
                        int distance = get_dump(b);
                        int temp = movement(b, distance);
                        *n = temp;
                    } else {
                        int distance = move_best_seller(b);
                        int temp = movement(b, distance);
                        *n = temp;
                    }
                } else {
                    *action = ACTION_MOVE;
                    int distance = move_best_seller(b);
                    int temp = movement(b, distance);
                    *n = temp;
                }
            }
        } else {
            if (fuel <= fuel_capacity*PERCENTAGE_OF_FUEL) {
                if (b->cargo != NULL) {
                    if (strcmp(b->cargo->commodity->name, current_location->commodity->name) == 0) {        //Checks if the location commodity is the same as the cargo commodity before selling
                        *action = ACTION_SELL;
                        *n = b->cargo->quantity;
                    } else {
                        *action = ACTION_MOVE;
                        int distance = nearest_fuel(b);
                        int temp = movement(b, distance);
                        *n = temp;
                    }
                } else {
                    *action = ACTION_MOVE;
                    int distance = nearest_fuel(b);
                    int temp = movement(b, distance);
                    *n = temp;
                }
            } else {
                if (b->cargo != NULL) {
                    if (strcmp(b->cargo->commodity->name, current_location->commodity->name) == 0) {
                        *action = ACTION_SELL;
                        *n = b->cargo->quantity;
                    } else {
                        int check = check_quantity(b);
                        if (check == 0) {
                            *action = ACTION_MOVE;
                            int distance = get_dump(b);
                            int temp = movement(b, distance);
                            *n = temp;
                        } else {
                            *action = ACTION_MOVE;
                            int distance = move_best_buyer(b);
                            int temp = movement(b, distance);
                            *n = temp;
                        }
                    }
                } else {
                    *action = ACTION_MOVE;
                    int distance = move_best_seller(b);
                    int temp = movement(b, distance);
                    *n = temp;
                }
            }
        }
    }

    if (current_location->type == LOCATION_OTHER) {
        *action = ACTION_MOVE;
        if (fuel <= fuel_capacity*PERCENTAGE_OF_FUEL) {
            *action = ACTION_MOVE;
            int distance = nearest_fuel(b);
            int temp = movement(b, distance);
            *n = temp;
        } else {
            if (b->cargo != NULL) {
                int check = check_quantity(b);
                if (check == 0) {
                    int distance = get_dump(b);
                    int temp = movement(b, distance);
                    *n = temp;
                } else {
                    int distance = move_best_buyer(b);
                    int temp = movement(b, distance);
                    *n = temp;
                }
            } else {
                int distance = move_best_seller(b);
                int temp = movement(b, distance);
                *n = temp;
            }
        }
    }

    if (current_location->type == LOCATION_DUMP) {
        if (b->cargo != NULL) {                                 //Dumps commodity if there are no places to sell it
            int check = check_quantity(b);
            if (check == 0) {
                *action = ACTION_DUMP;
                *n = b->cargo->quantity;
            } else {
                *action = ACTION_MOVE;
                int distance = move_best_buyer(b);
                int temp = movement(b, distance);
                *n = temp;
            }
        } else {
            *action = ACTION_MOVE;
            int distance = move_best_seller(b);
            int temp = movement(b, distance);
            *n = temp;
        }
    }
}
