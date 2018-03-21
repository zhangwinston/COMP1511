// Written by andrewt@unsw.edu.au April 2017
// as COMP1511 week 7 lab solution

#include <stdio.h>
#include "captcha.h"

void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]) {

    int row = 0;
    int column = 0;

    // Copies the coordinates of the bounding box from pixel array to copy array

    while (row < copy_height) {
        column = 0;
        while (column < copy_width) {
            copy[row][column] = pixels[start_row + row][start_column + column];
            column++;
        }
        row++;
    }
}
