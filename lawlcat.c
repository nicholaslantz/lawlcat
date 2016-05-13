

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

void colorize(int phase, FILE *out);
void pretty_output(FILE *in, FILE *out);

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
                perror("lawlcat");
                continue;
            }
            pretty_output(f, stdout);
        }
    } else
        pretty_output(stdin, stdout);

    return EXIT_SUCCESS;
}
/**
 * colorize - Outputs color escape character
 * @param phase - A number between 0 and 29 inclusive
 */

void colorize(int phase, FILE *out) {
    static char b[512];
    sprintf(b, "%s%s", intro, colors[phase]);
    fputs(b, out);
}

/**
 * pretty_output - Pipes text in a fabulous way
 * @param in - input file stream
 * @param out - output file stream
 *
 * Does not check if in and out are valid streams, don't
 * mess with it
 */

void pretty_output(FILE *in, FILE *out) {
    int start_phase = 0;
    int curr_phase = 0;
    int i = 0;

    char c;
    while ((c = getc(in)) != EOF) {
        colorize(curr_phase, out);
        putc(c, out);
        fflush(out);

        i++;
        if (i % 5 == 0) {
            i = 0;
            curr_phase = (curr_phase + 1) % COLORS_SIZE;
        }

        if (c == '\n') {
            start_phase = (start_phase + 1) % COLORS_SIZE;
            curr_phase = start_phase;
        }
    }
}
