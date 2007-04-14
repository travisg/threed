#ifndef __SURFACE_H
#define __SURFACE_H

#include <vector>

struct SurfaceIndex {
	int posIndex;
	int normIndex;
	int uvIndex;
};

typedef std::vector<SurfaceIndex> SurfaceIndexList;
typedef std::vector<SurfaceIndex>::iterator SurfaceIndexListIterator;
typedef std::vector<SurfaceIndex>::const_iterator SurfaceIndexListIteratorConst;

class Surface {
public:
	void AddIndex(int posIndex, int normIndex, int uvIndex);

	SurfaceIndexList m_Indexes;
};
	
typedef std::vector<Surface *> SurfaceList;
typedef std::vector<Surface *>::iterator SurfaceListIterator;
typedef std::vector<Surface *>::const_iterator SurfaceListIteratorConst;

#endif
