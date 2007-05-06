#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include "Geometry.h"
#include "Mesh.h"
#include "UnifiedMesh.h"
#include <shared/mesh.h>

int dump_geometry_tree(Geometry *geometry, std::string outfile_root)
{

	for (MeshListIteratorConst i = geometry->ListIterator(); i != geometry->ListEnd(); i++) {
		Mesh *mesh = *i;
		UnifiedMesh umesh;

		umesh.CreateFromMesh(*mesh);
		umesh.Optimize();

		std::string filename = outfile_root + "_" + mesh->GetName() + ".mesh";
		std::cout << "Outputting mesh to file " << filename << std::endl;
		FILE *outfp = fopen(filename.c_str(), "wb+");
		if (!outfp) {
			std::cerr << "error opening file '" << filename.c_str() << "'" << std::endl;
			return -1;
		}

		// build a header
		mesh_header header;
		header.magic[0] = 'M';
		header.magic[1] = 'E';
		header.magic[2] = 'S';
		header.magic[3] = 'H';
		header.version = 1;
		header.endian = 0;
		header.index_width = 4;
		header.mesh_type = MESH_TYPE_TRIANGLE_LIST;
		header.vert_format = VERT_FORMAT_POS_NORM_UV;
		header.vertcount = (uint32_t)umesh.VertCount();
		header.indexcount = (uint32_t)umesh.IndexCount();
		
		fseek(outfp, sizeof(mesh_header), SEEK_SET);
		header.indexoffset = ftell(outfp);
		umesh.WriteIndexes(outfp, header.index_width);
		header.vertoffset = ftell(outfp);
		header.indexlen = header.vertoffset - header.indexoffset;
		umesh.WriteVerts(outfp, (Vertex_Format)header.vert_format);
		header.vertlen = ftell(outfp) - header.vertoffset;

		fseek(outfp, 0, SEEK_SET);
		fwrite(&header, sizeof(header), 1, outfp);

		fclose(outfp);
	}

	return 0;
}