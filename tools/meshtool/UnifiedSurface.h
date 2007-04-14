#ifndef __UNIFIED_SURFACE_H
#define __UNIFIED_SURFACE_H

#include <vector>

struct UnifiedSurface {
	std::vector<int> m_Indexes;
};

typedef std::vector<UnifiedSurface *> UnifiedSurfaceList;
typedef std::vector<UnifiedSurface *>::iterator UnifiedSurfaceListIterator;
typedef std::vector<UnifiedSurface *>::const_iterator UnifiedSurfaceListIteratorConst;

#endif
