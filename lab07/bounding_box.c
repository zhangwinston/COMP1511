#include <stdio.h>
#include "captcha.h"

void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width) {

    int row = height - 1;
    int column = width - 1;
    int end_column;
    int end_row;
    int bheight;
    int bwidth;

    
    
    while (row >= 0) {
        column = width - 1;
        while (column >= 0) {
            if (pixels[row][column] == 1) {
                *start_row = row;
                break;
            }
            column = column - 1;
        }
        row = row - 1;
    }

    row = height - 1;
    column = width - 1;

    while (column >= 0) {
        row = height - 1;
        while (row >= 0) {
            if (pixels[row][column] == 1) {
                *start_column = column;
                break;
            }
            row = row - 1;
        }
        column = column - 1;
    }

    row = 0;
    column = 0;

    while (row < height) {
        column = 0;
        while (column < width) {
            if (pixels[row][column] == 1) {
                end_row = row;
                break;
            }
            column++;
        }
        row++;
    }
    
    row = 0;
    column = 0;
    
    while (column < width) {
        row = 0;
        while (row < height) {
            if (pixels[row][column] == 1) {
                end_column = column;
                break;
            }
            row++;
        }
        column++;
    }

    bheight = end_row - *start_row;
    bwidth = end_column - *start_column;

    *box_height = bheight + 1;
    *box_width = bwidth + 1;
}
