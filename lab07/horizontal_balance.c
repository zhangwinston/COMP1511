// written by andrewt@unsw.edu.au April 2018
// sourced from COMP1511 sample solution to week 7 lab exercise

#include <stdio.h>
#include "captcha.h"


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
