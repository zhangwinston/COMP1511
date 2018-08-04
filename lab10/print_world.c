#include <stdio.h>
#include "trader_bot.h"

void print_world(struct bot *b) {
    
    int counter = 0;

    struct location *current = b->location;

    while (current != b->location || counter == 0) {
        counter = 1;
        printf("%s: ", current->name);
        if (current->type == LOCATION_START) {
            printf("start\n");
        } else if (current->type == LOCATION_SELLER) {
            printf("will sell %d units of %s for $%d\n", current->quantity, current->commodity->name, current->price);
        } else if (current->type == LOCATION_DUMP) {
            printf("dump\n");
        } else if (current->type == LOCATION_OTHER) {
            printf("other\n");
        } else if (current->type == LOCATION_PETROL_STATION) {
            printf("Petrol station %d units of available fuel for $%d\n", current->quantity, current->price);
        } else if (current->type == LOCATION_BUYER) {
            printf("will buy %d units of %s for $%d\n", current->quantity, current->commodity->name, current->price);
        }
        current = current->next;
    }
}
