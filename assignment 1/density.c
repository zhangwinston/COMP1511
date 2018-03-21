// Code to calculate the density of various areas of a bounding box
// Written by Anthony Xu - z5165674@unsw.edu.au
// for COMP1511 assignment 1 - 2017

#include <stdio.h>
#include "captcha.h"

// Checks for a black pixel ('1' or '*') and counts up
// Finds the black pixel to white pixel ratio
double get_density(int height, int width, int pixels[height][width]) {

    int row = 0;
    int column = 0;
    double black_pixels = 0;
    int total_pixels = height * width;

    while (row < height) {
        column = 0;
        while (column < width) {
            if (pixels[row][column] == 1) {
                black_pixels++;
            }
            column++;
        }
        row++;
    }
    return (black_pixels / total_pixels);
}
