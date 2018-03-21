// Written by andrewt@unsw.edu.au April 2017
// Sourced from COMP1511 sample solution to week 7 lab exercise - horizontal_balance.c
// Modified to give the vertical balance

#include <stdio.h>
#include "captcha.h"

double get_vertical_balance(int height, int width, int pixels[height][width]) {

    int row = 0;       
    int column = 0;
    double row_sum = 0;
    int black_pixels = 0;
    
    while (column < width) {
        row = 0;
        while (row < height) {
            if (pixels[row][column] == 1) {
                row_sum = row_sum + row;
                black_pixels++;
            }
            row++;
        }
        column++;
    }
    return (row_sum / black_pixels + 0.5) / height;
}


// Modified to check the vertical balance for the bottom half of the bouncing box
// Sourced from Andrew Taylor, COMP1511
double get_lower_vertical_balance(int height, int width, int pixels[height][width]) {

    int row = 0;       
    int column = 0;
    double row_sum = 0;
    int black_pixels = 0;
    
    while (column < width) {
        row = 0;
        while (row < (height / 2) - 1) {
            if (pixels[row][column] == 1) {
                row_sum = row_sum + row;
                black_pixels++;
            }
            row++;
        }
        column++;
    }
    return (row_sum / black_pixels + 0.5) / ((height / 2) - 1);
}

// Modified to check the vertical balance for the top half of the bouncing box
// Sourced from Andrew Taylor, COMP1511
double get_upper_vertical_balance(int height, int width, int pixels[height][width]) {

    int row = height / 2;       
    int column = 0;
    double rsum = 0;
    int black_pixels = 0;
    
    while (column < width) {
        row = 0;
        while (row < height) {
            if (pixels[row][column] == 1) {
                rsum = rsum + row;
                black_pixels++;
            }
            row++;
        }
        column++;
    }
    return (rsum / black_pixels + 0.5) / (height - (height / 2));
}
