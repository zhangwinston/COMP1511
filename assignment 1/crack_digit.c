// Program to recognise digits
// By Anthony Xu - z5165674@unsw.edu.au
// for COMP1511 assignment 1 - 2017
// https://cgi.cse.unsw.edu.au/~cs1511/17s1/assignments/captcha/index.html

#include <stdio.h>
#include "captcha.h"

// Code written by Andrew Taylor for COMP1511 week 7 lab and for assignment 1
// andrewt@unsw.edu.au April 2017
void analyze_image(int height, int width, int pixels[height][width]);
int find_digit(double horizontal_balance, double vertical_balance, double density, int holes, double lower_vertical, double upper_horizontal,double lower_horizontal,
            double upper_vertical, double hole_density, double hole_balance, double left_balance, double right_balance, int top_curves, int bottom_curves);

int main(int argc, char *argv[]) {
    int height, width;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }
    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }
    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {
        analyze_image(height, width, pixels);
    }
    return 0;
}
// Code written by Andrew Taylor for COMP1511 week 7 lab and for assignment 1             

void analyze_image(int height, int width, int pixels[height][width]) {
    int start_row, start_column, box_width, box_height;

    get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);

    int box_pixels[box_height][box_width];
    copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);

    // Obtaining different characteristics of the digit and outputting values
    double horizontal_balance = get_horizontal_balance(box_height, box_width, box_pixels);                            
    double vertical_balance = get_vertical_balance(box_height, box_width, box_pixels);
    double density = get_density(box_height, box_width, box_pixels);
    double lower_vertical = get_lower_vertical_balance(box_height, box_width, box_pixels);
    double upper_horizontal = get_upper_horizontal_balance(box_height, box_width, box_pixels);
    double lower_horizontal = get_lower_horizontal_balance(box_height, box_width, box_pixels);
    double upper_vertical = get_upper_vertical_balance(box_height, box_width, box_pixels);
    double left_balance = get_left_horizontal_balance(box_height, box_width, box_pixels);
    double right_balance = get_right_horizontal_balance(box_height, box_width, box_pixels);
    
    // Co-ordinaates of starting rows and columns for flood fill
    int row_top = box_height - 1;
    int column_last = box_width - 1;
    int row_bottom = 0;
    int column_first = 0;
    int row_middle = box_height/2;
    int row_middle_upper = box_height/2 + 10;
    int row_middle_lower = box_height/2 - 10;
    int row10 = 10;

    flood(row_top, column_last, box_height, box_width, box_pixels); // Starts from top righthand corner of image
    flood(row_top, column_first, box_height, box_width, box_pixels); // Starts from top lefthand corner of image 

    flood(row_bottom, column_first, box_height, box_width, box_pixels); // Starts from bottom lefthand corner of image
    flood(row_bottom, column_last, box_height, box_width, box_pixels); // Starts from bottom righthand corner of image

    flood(row_middle, column_last, box_height, box_width, box_pixels); // Starts from middle righthand side of image
    flood(row_middle, column_first, box_height, box_width, box_pixels); // Starts from middle lefthand side of image

    flood(row_middle_upper, column_last, box_height, box_width, box_pixels); // Starts from middle upper righthand side of image
    flood(row_middle_upper, column_first, box_height, box_width, box_pixels); // Starts from middle upper lefthand side of image

    flood(row_middle_lower, column_first, box_height, box_width, box_pixels); // Starts from middle lower lefthand side of image
    flood(row_middle_lower, column_last, box_height, box_width, box_pixels); // Starts from middle lower righthand side of image
    flood(row10, column_last, box_height, box_width, box_pixels);
    
    int holes = get_holes(box_height, box_width, box_pixels);
    double hole_density = get_density(box_height, box_width, box_pixels);
    double hole_balance = get_hole_balance(box_height, box_width, box_pixels);

    // "Refreshing" the image so that it is 'clean' for checking the curves
    get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);
    copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);

    flood(row_top, column_last, box_height, box_width, box_pixels); // Starts from top righthand corner of image
    flood(row_bottom, column_last, box_height, box_width, box_pixels); // Starts from bottom righthand corner of image
    flood(row_middle, column_last, box_height, box_width, box_pixels); // Starts from middle righthand side of image
    flood(row_middle_upper, column_last, box_height, box_width, box_pixels); // Starts from middle upper righthand side of image
    flood(row_middle_lower, column_last, box_height, box_width, box_pixels); // Starts from middle lower righthand side of image

    horizontal_fill(box_height, box_width, box_pixels);
    int bottom_curves = bottom_curve(box_height, box_width, box_pixels);
    int top_curves = top_curve(box_height, box_width, box_pixels);

    int digit = find_digit(horizontal_balance, vertical_balance, density, holes, upper_horizontal, upper_vertical, lower_horizontal,
             lower_vertical, hole_density, hole_balance, left_balance, right_balance, top_curves, bottom_curves);

    printf("%c\n", digit);
}

int find_digit(double horizontal_balance, double vertical_balance, double density, int holes, double upper_horizontal, double upper_vertical, double lower_vertical, double lower_horizontal, 
                double hole_density, double hole_balance, double left_balance, double right_balance, int top_curves, int bottom_curves) {
    if (holes == 2) {
        return '8';
    }
    if (holes == 1) {   
        if (hole_density < 0.750) {
            return '0';
        } 
        if (hole_balance < 0.390 && upper_horizontal > 0.320 && upper_horizontal < 0.590 && horizontal_balance < 0.520 && horizontal_balance > 0.400 && vertical_balance >= 0.400 
        && vertical_balance < 0.550) {
            return '6';
        }
        if (hole_balance > 0.620 && hole_balance < 0.710 && lower_horizontal > 0.430 && lower_horizontal < 0.650 && horizontal_balance > 0.465 && horizontal_balance < 0.600 
        && vertical_balance > 0.450 &&         
        vertical_balance < 0.575) {
            return '9';
        }
        if (hole_density > 0.551 && hole_density < 0.880 && hole_balance > 0.460 && hole_balance < 0.540 && horizontal_balance > 0.430 && horizontal_balance < 0.540 
        && vertical_balance >= 0.460 && vertical_balance < 0.550) {
            return '0';
        }
        if (hole_density > 0.830 && hole_density < 0.980 && hole_balance <= 0.625 && hole_balance > 0.270 && vertical_balance > 0.410 && vertical_balance < 0.560 
        && horizontal_balance > 0.430 && horizontal_balance < 0.640) {
            return '4';
        }
    }
    if (holes == 0) {
        if (vertical_balance > 0.620) { 
            return '7';
        }
        if (top_curves == 1 && bottom_curves == 1 && horizontal_balance > 0.513 && vertical_balance > 0.420 && vertical_balance < 0.570) {
            return '3';
        }
        if (bottom_curves == 1 && upper_vertical > 0.870 && upper_vertical < 1.150 && horizontal_balance > 0.430 && horizontal_balance < 0.600 && 
        vertical_balance > 0.430 && vertical_balance < 0.550) {
            return '5';
        }
        if (top_curves == 1 && vertical_balance > 0.400 && vertical_balance < 0.560 && horizontal_balance > 0.450 && horizontal_balance < 0.630) {
            return '2';
        }
        if (top_curves == 1 && right_balance > 0.840 && right_balance < 1.420 && left_balance > 0.440 && left_balance < 0.690 && horizontal_balance < 0.700 && horizontal_balance > 0.420 
        && vertical_balance >= 0.430 && vertical_balance < 0.560) {
            return '1';
        }
        if (vertical_balance > 0.540 && vertical_balance < 0.620 && upper_vertical > 1.030 && upper_vertical < 1.400 && horizontal_balance > 0.410 && 
        horizontal_balance < 0.700) { 
            return '7';
        }
        if (right_balance > 0.840 && right_balance < 1.420 && left_balance > 0.440 && left_balance < 0.690 && horizontal_balance < 0.700 && horizontal_balance > 0.420 
        && vertical_balance >= 0.430 && vertical_balance < 0.560) {
            return '1';
        }

    }
} 
