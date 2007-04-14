#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "Geometry.h"

extern int ac3d_load(FILE *infp);
extern int obj_load(FILE *infp, Geometry **new_geometry);

extern int dump_geometry_tree(Geometry *geometry, std::string outfile_root);

int convertfile(const char *infile, const char *outfile)
{
	FILE *infp;
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
			std::cout << "loading meshes from AC3d file '" << infile << "'" << std::endl;
			ac3d_load(infp);
		} else if (!strcmp(c, ".obj")) {
			std::cout << "loading meshes from object file '" << infile << "'" << std::endl;
			obj_load(infp, &new_geometry);
		} else {
			std::cerr << "unrecognized input mesh" << std::endl;
			fclose(infp);
			return -1;
		}
	} else {
		std::cerr << "unrecognized input mesh" << std::endl;
		fclose(infp);
		return -1;
	}

	fclose(infp);

	// do some processing

	// dump the output
	dump_geometry_tree(new_geometry, outfile);

	return 0;
}
