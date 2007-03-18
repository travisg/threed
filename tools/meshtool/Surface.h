#ifndef __SURFACE_H
#define __SURFACE_H

#include <vector>

class Surface {
public:
	Surface();
	~Surface();

	void AddIndex(int posIndex, int normIndex, int uvIndex);

	struct SurfaceIndex {
		int posIndex;
		int normIndex;
		int uvIndex;
	};

private:
	std::vector<SurfaceIndex> m_Indexes;
};

typedef std::vector<Surface *> SurfaceList;

#endif
