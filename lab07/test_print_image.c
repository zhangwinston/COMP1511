#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {
    int height, width;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    // first get image dimensions
    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }

    // now declare appropriate array
    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {

        int row_top = box_height - 1;
        int column_last = box_width - 1;
        int row_bottom = 0;
        int column_first = 0;
        int row_middle = box_height/2 - 2;

        flood(row_top, column_last, box_height, box_width, box_pixels); // Starts from top righthand corner of image
        flood(row_top, column_first, box_height, box_width, box_pixels); // Starts from top lefthand corner of image 
        flood(row_bottom, column_first, box_height, box_width, box_pixels); // Starts from bottom lefthand corner of image
        flood(row_bottom, column_last, box_height, box_width, box_pixels); // Starts from bottom righthand corner of image
        flood(row_middle, column_last, box_height, box_width, box_pixels); // Starts from middle righthand side of image
        flood(row_middle, column_first, box_height, box_width, box_pixels); // Starts from middle lefthand side of image

        print_image(height, width, pixels);
    }
    return 0;
}
