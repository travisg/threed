#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Geometry.h"

extern int ac3d_load(FILE *infp);
extern int obj_load(FILE *infp, Geometry **new_geometry);

int convertfile(const char *infile, const char *outfile)
{
	FILE *infp;
	FILE *outfp;
	Geometry *new_geometry;

	infp = fopen(infile, "rb");
	if (!infp) {
		fprintf(stderr, "error opening input file '%s'\n", infile);
		return -1;
	}

	// try to guess the file type based on input name
	const char *c = strrchr(infile, '.');
	if (c) {
		if (!strcmp(c, ".ac")) {
			ac3d_load(infp);
		} else if (!strcmp(c, ".obj")) {
			obj_load(infp, &new_geometry);
		} else {
			fprintf(stderr, "unrecognized input mesh\n");
			fclose(infp);
			return -1;
		}
	} else {
		fprintf(stderr, "unrecognized input mesh\n");
		fclose(infp);
		return -1;
	}

	outfp = fopen(outfile, "wb+");
	if (!outfp) {
		fprintf(stderr, "error opening output file '%s'\n", outfile);
		fclose(infp);
		return -1;
	}

	fclose(infp);
	fclose(outfp);

	return 0;
}
