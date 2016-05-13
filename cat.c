

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc > 1) {
        /* Open, concatenate files */
        FILE *f;
        unsigned int i;
        for (i = 1; i < argc; i++) {
            f = fopen(argv[i], "r");
            if (f == NULL) {
                perror("cat");
                continue;
            }
            char c;
            while ((c = getc(f)) != EOF)
                putchar(c);
        }
    } else {
        /* copy stdin */
        char c;
        while ((c = getc(stdin)) != EOF) {
            putchar(c);
            fflush(stdout);
        }
    }

    return EXIT_SUCCESS;
}
