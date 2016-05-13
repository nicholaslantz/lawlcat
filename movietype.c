

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
            usleep(30000);
        else if (isspace(c))
            usleep(10000);
        else
            usleep(70000);
    }

    return EXIT_SUCCESS;
}
