// A program which encryptes an input with a Caesar Cipher
// 3/04/2017
// By Anthony Xu - z5165674@unsw.edu.au

#include <stdio.h>
#include <stdlib.h>

int lowercases(int ch, int shift) {
    shift = shift % 26;
    ch = (ch - 'a' + shift);
    if (ch < 0) {
        ch = 'z' + (ch + 1);
    } else {
        ch = ch % 26 + 'a';
    }
    return ch;
}

int uppercases(int ch, int shift) {
    shift = shift % 26;
    ch = (ch - 'A' + shift);
    if (ch < 0) {
        ch = 'Z' + (ch + 1);
    } else {
        ch = ch % 26 + 'A';
    }
    return ch;
}

int main(int argc, char *argv[]) {
    int shift;
    int ch;

    shift = atoi(argv[1]);
    
    ch = getchar();
    while (ch != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = lowercases(ch, shift);
            printf("%c", ch);
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = uppercases(ch, shift);
            printf("%c", ch);
        } else {
            printf("%c", ch);
        }
        ch = getchar();
    }
    return 0;
}





