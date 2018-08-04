#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
   
    int ch, c;
    int index;
    
    ch = getchar();
    
    while (ch != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            index = ch - 'A';
            c = argv[1][index] - ('a' - 'A');
            printf("%c", c);
        } else if (ch >= 'a' && ch <= 'z') {
            index = ch - 'a';
            c = argv[1][index];
            printf("%c", c);
        } else {
            printf("%c", ch);
        }
        ch = getchar();
    }
    return 0;
}   
