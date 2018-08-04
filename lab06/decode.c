#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
   
    int ch, index, character;
    int i = 0;
    int j = 0;
    int alphabet

    ch = getchar();
    
    while (ch != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            j = ch;
            while (i < 26) {
                if (j == alphabet[i]) {
                character = argv[1][j];
                printf("%c", character);
                }
                i++;
            }
        } else {
            printf("%c", ch);
        }
        ch = getchar();
    }
    return 0;
}
