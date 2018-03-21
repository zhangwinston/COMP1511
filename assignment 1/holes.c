// Code to count the number of holes in a number
// By Anthony Xu - z5165674@unsw.edu.au
// For COMP1511 assignment - 2017

#include <stdio.h>
#include "captcha.h"

// Checks for the bottom of a hole
int get_holes(int height, int width, int pixels[height][width]) {
    
    int row = 0;
    int column = 0;
    int holes = 0;
    int new_column;
    int row_below;
    int i = 0;
    int counter = 0;

    while (row < height) {
        column = 0;
        i = 0;
        counter = 0;
        while (column < width) {
            if (column <= width - 5 && row < height - 10 && row > 0 && (column + 4 < width - 3) && pixels[row][column] == 1 && pixels[row][column + 1] == 1 
                && pixels[row][column + 2] == 1 && pixels[row][column + 3] == 1 && pixels[row][column + 4] == 0) {              // Checks for ****. or 11110
                row_below = row - 1; 
                new_column = 0;
                while (i < width && new_column + i < width) {        // Checks that the row below it is filled with 1's - therefore it must be the bottom of a hole
                    if (pixels[row_below][new_column + i] == 1) {
                        counter++;
                    }
                    i++;
                }
                if (counter == width) {
                    holes++;
                }
            }
            column++;
        }
        row++;
    }
    return holes;
}   

//Checks the vertical balance of the holes
//Used after the floodfill when the only 0's left are 0's inside holes
//Smaller value means that the hole is closer to the bottom of the bounding box
//Sourced from COMP1511 week 7 lab exercise
//andrewt@unsw.edu.au April 2017
double get_hole_balance(int height, int width, int pixels[height][width]) {    

    int row = 0;       
    int column = 0;
    double row_sum = 0.0;
    double white_pixels = 0.1;
    
    while (column < width) {
        row = 0;
        while (row < height) {
            if (pixels[row][column] == 0) {
                row_sum = row_sum + row;
                white_pixels++;
            }
            row++;
        }
        column++;
    }
    return (row_sum / white_pixels + 0.5) / height;
}    

//Checks for the bottom curve in a digit - in 5's and 3's
//Used after the horizontal fill and floodfill of the right half of the bounding box
int bottom_curve(int height, int width, int pixels[height][width]) {

    int row = 0;
    int column = 0;
    int curve = 0;

    while (row < (height / 2) - 3 && curve < 1) {
        column = 0;
        while (column < width) {
            if (row > 1 && column < width - 7 && pixels[row][column] == 0 && pixels[row][column + 1] == 0 && pixels[row][column + 2] == 0 && pixels[row][column + 3] == 0 && pixels[row][column + 4] == 0 && 
            pixels[row][column + 0] == 0) {                 //Similar to get_holes - checks for a long line of '.'s in the bottom half of the image
                curve++;
                break;
            }
            column++;
        }
        row++;
    }
    return curve;
}

//Checks for the top curve in a digit - in 2's and 3's
//Used after the horizontal fill and floodfill of the right half of the bounding box
int top_curve(int height, int width, int pixels[height][width]) {

    int row = height - 1;
    int column = 0;
    int curve = 0;

    while (row > (height / 2) + 3 && curve < 1) {
        column = 0;
        while (column < width) {
            if (row > 1 && column < width - 7 && pixels[row][column] == 0 && pixels[row][column + 1] == 0 && pixels[row][column + 2] == 0 && pixels[row][column + 3] == 0 && pixels[row][column + 4] == 0 && 
            pixels[row][column + 0] == 0) {                 //Similar to get_holes - checks for a long line of '.'s in the top half of the image
                curve++;
                break;
            }
            column++;
        }
        row = row - 1;
    }
    return curve;
}
