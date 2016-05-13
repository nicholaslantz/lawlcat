/*
 * Jack Rosenthal supplied the idea for this program. Hoever,
 * this is my own implementation of it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char **argv) {
    char c;
    char vowels[] = "aeiou";

    while ((c = getc(stdin)) != EOF) {
        putchar(c);
        fflush(stdout);
        char b[2];
        sprintf(b, "%c", c);
        if (strstr(vowels, b))
            usleep(1500);
        else if (isspace(c))
            usleep(500);
        else
            usleep(3500);
    }

    return EXIT_SUCCESS;
}
