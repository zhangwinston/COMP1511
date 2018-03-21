// Code to print out the image of a PBM file in 0's and 1's
// Written by Anthony Xu - z5165674@unsw.edu.au
// for COMP1511 week 7 lab exercise - 2017

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
