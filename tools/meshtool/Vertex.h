#ifndef __VERTEX_H
#define __VERTEX_H

#include <vector>

class Vertex {
public:
	Vertex();
	~Vertex();

	union {
		struct {
			float x, y, z, w;
		};
		struct {
			float u, v;
		};
	};
};

typedef std::vector<Vertex> VertexList;

#endif
