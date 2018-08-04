#include <stdio.h>
#include "captcha.h"

void print_image(int height, int width, int pixels[height][width]) {

    int i = height - 1;
    int j;

    while (i >= 0) {
        j = 0;
        while (j < width) {
            if (pixels[i][j] == 1) {
                printf("*");
            } else if (pixels[i][j] == 0) {
                printf(".");
            }
            j++;
        }
        printf("\n");
        i = i - 1;
    }
}
