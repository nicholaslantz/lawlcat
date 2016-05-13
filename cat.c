

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char *intro = "\e[38;5;";
const char *colors[] = {
    "196m", "202m", "208m", "214m", "220m",
    "226m", "190m", "154m", "118m", "82m",
    "46m",  "47m",  "48m",  "49m",  "50m",
    "51m",  "45m",  "39m",  "33m",  "27m",
    "21m",  "57m",  "93m",  "129m", "165m",
    "201m", "200m", "199m", "198m", "197m",
};

const int COLORS_SIZE = sizeof(colors) / sizeof(char*);

void colorize(int phase);

int main(int argc, char **argv) {
    int start_phase = 0;
    int curr_phase = start_phase;
    int i = 0;
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
            while ((c = getc(f)) != EOF) {
                colorize(curr_phase);
                putchar(c);
                fflush(stdout);
                i++;
                if (i % 5 == 0) {
                    curr_phase = (curr_phase + 1) % COLORS_SIZE;
                    i = 0;
                }
                if (c == '\n') {
                    start_phase = (start_phase + 1) % COLORS_SIZE;
                    curr_phase = start_phase;
                }
            }
        }
    } else {
        /* copy stdin */
        char c;
        while ((c = getc(stdin)) != EOF) {
            putchar(c);
            fflush(stdout);
        }
    }

    colorize(0);

    return EXIT_SUCCESS;
}
/**
 * Colorize - Outputs color escape character
 * @param phase - A number between 0 and 29 inclusive
 */

void colorize(int phase) {
    static char b[512];
    sprintf(b, "%s%s", intro, colors[phase]);
    printf(b);
}
