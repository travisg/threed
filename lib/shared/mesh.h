#ifndef __SHARED_MESH_H
#define __SHARED_MESH_H

#include <shared/defines.h>

enum Mesh_Type { 
	MESH_TYPE_NULL,
	MESH_TYPE_POINTS,
	MESH_TYPE_TRIANGLE_LIST,
	MESH_TYPE_TRIANGLE_MESH,
	MESH_TYPE_TRIANGLE_FAN,

	MAX_MESH_TYPE
};

enum Vertex_Format {
	VERT_FORMAT_NULL,
	VERT_FORMAT_POS,
	VERT_FORMAT_POS_NORM,
	VERT_FORMAT_POS_NORM_UV,

	MAX_VERT_FORMAT
};

// on disk mesh header
struct mesh_header {
	unsigned char magic[4]; // MESH
	uint8_t version; // 1 is current
	uint8_t endian; // 0 (little endian) or 1 (big endian)
	uint8_t index_width; // 2 or 4
	uint8_t mesh_type;
	uint32_t vert_format;
	uint32_t indexcount;
	uint32_t indexoffset;
	uint32_t indexlen;
	uint32_t vertcount;
	uint32_t vertoffset;
	uint32_t vertlen;
};

#define MESH_HEADER_MAGIC "MESH"
#define MESH_HEADER_CURRENT_VERSION 1

#endif
