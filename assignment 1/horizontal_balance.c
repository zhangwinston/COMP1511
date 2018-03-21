// Written by andrewt@unsw.edu.au April 2017
// Sourced from COMP1511 sample solution to week 7 lab exercise

#include <stdio.h>
#include "captcha.h"

// Checks horizontal balance for the whole bounding box
double get_horizontal_balance(int height, int width, int pixels[height][width]) {

    int row = 0;       
    int column = 0;
    double column_sum = 0;
    int black = 0;
    
    while (row < height) {
        column = 0;
        while (column < width) {
            if (pixels[row][column] == 1) {
                column_sum = column_sum + column;
                black++;
            }
            column++;
        }
        row++;
    }
    return (column_sum / black + 0.5) / width;
}

// Modified to check the horizontal balance for the bottom half of the bouncing box
// Sourced from Andrew Taylor, COMP1511
double get_lower_horizontal_balance(int height, int width, int pixels[height][width]) {

    int row = 0;       
    int column = 0;
    double csum = 0;
    int black = 0;
    
    while (row < (height / 2) - 1) {
        column = 0;
        while (column < width) {
            if (pixels[row][column] == 1) {
                csum = csum + column;
                black++;
            }
            column++;
        }
        row++;
    }
    return (csum / black + 0.5) / width;
}

// Modified to check the horizontal balance for the top half of the bounding box
// Sourced from Andrew Taylor, COMP1511
double get_upper_horizontal_balance(int height, int width, int pixels[height][width]) {

    int row = height / 2;       
    int column = 0;
    double csum = 0;
    int black = 0;
    
    while (row < height) {
        column = 0;
        while (column < width) {
            if (pixels[row][column] == 1) {
                csum = csum + column;
                black++;
            }
            column++;
        }
        row++;
    }
    return (csum / black + 0.5) / width;
}

// Modified to check the horizontal balance for the left half of the bounding box
// Sourced from Andrew Taylor, COMP1511
double get_left_horizontal_balance(int height, int width, int pixels[height][width]) {

    int row = 0;       
    int column = 0;
    double csum = 0;
    int black = 0;
    
    while (row < height) {
        column = 0;
        while (column < (width / 2) - 1) {
            if (pixels[row][column] == 1) {
                csum = csum + column;
                black++;
            }
            column++;
        }
        row++;
    }
    return (csum / black + 0.5) / (width / 2);
}

// Modified to check the horizontal balance for the right half of the bounding box
// Sourced from Andrew Taylor, COMP1511
double get_right_horizontal_balance(int height, int width, int pixels[height][width]) {

    int row = 0;       
    int column = width / 2;
    double csum = 0;
    int black = 0;
    
    while (row < height) {
        column = 0;
        while (column < width) {
            if (pixels[row][column] == 1) {
                csum = csum + column;
                black++;
            }
            column++;
        }
        row++;
    }
    return (csum / black + 0.5) / (width - (width / 2));
}
