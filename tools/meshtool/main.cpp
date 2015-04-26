#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int convertfile(const char *infile, const char *outfile);

void usage(char **argv)
{
    printf("bad command line. usage:\n");
    printf("%s convert <infile> <outfile name root>\n", argv[0]);
    exit(1);
}

extern "C"
int main(int argc, char **argv)
{
    if (argc < 2) {
        usage(argv);
    }

    if (!strcmp(argv[1], "convert")) {
        if (argc < 4) {
            usage(argv);
        }

        return convertfile(argv[2], argv[3]);
    } else {
        usage(argv);
    }

    return 0;
}
