#ifndef __VERTEX_H
#define __VERTEX_H

#include <vector>

class Vertex {
public:
	Vertex() {}
	~Vertex() {}
	Vertex(float inx, float iny, float inz, float inw) : x(inx), y(iny), z(inz), w(inw) {}
	Vertex(float inu, float inv) : x(inu), y(inv), z(0), w(0) {}

	union {
		struct {
			float x, y, z, w;
		};
		struct {
			float u, v;
		};
	};

	static Vertex EmptyVertex;
};

typedef std::vector<Vertex> VertexList;

#endif
