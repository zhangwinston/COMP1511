// Program to flood fill the outside of an image
// Taken from http://lodev.org/cgtutor/floodfill.html  - 8-Way Recursive
// Written by Lode Vandevenne

#include <stdio.h>
#include "captcha.h"

void flood(int row, int column, int height, int width, int pixels[height][width]) {
    
    if (row >= 0 && row < height && column >= 0 && column < width && pixels[row][column] == 0 && pixels[row][column] != 1) {
        pixels[row][column] = 1;

        flood(row + 1, column    , height, width, pixels);
        flood(row - 1, column    , height, width, pixels);
        flood(row    , column + 1, height, width, pixels);
        flood(row    , column - 1, height, width, pixels);
        flood(row + 1, column + 1, height, width, pixels);
        flood(row + 1, column - 1, height, width, pixels);
        flood(row - 1, column + 1, height, width, pixels);
        flood(row - 1, column - 1, height, width, pixels);
    }
}


// Code to replace 0's with 1's horizontally
// Keeps any '0's which are shielded by the curvature of numbers (2, 3, 5)
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>
#include "captcha.h"

void horizontal_fill(int height, int width, int pixels[height][width]) {

    int row = 0;
    int column = 0;

    while (row < height) {
        column = 0;
        while (column < width && pixels[row][column] != 1) {
            if (pixels[row][column] == 0) {
                pixels[row][column] = 1;
            }
            column++;
        }
        row++;
    }
}
