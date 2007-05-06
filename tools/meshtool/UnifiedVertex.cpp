#include <stdio.h>
#include <assert.h>
#include "UnifiedVertex.h"

void UnifiedVertex::Write(FILE *outfp, Vertex_Format f) const
{
	bool pos = false;
	bool normal = false;
	bool uv = false;

	switch (f) {
		case VERT_FORMAT_NULL:
			break;
		case VERT_FORMAT_POS:
			pos = true;
			break;
		case VERT_FORMAT_POS_NORM:
			pos = true;
			normal = true;
			break;
		case VERT_FORMAT_POS_NORM_UV:
			pos = true;
			normal = true;
			uv = true;
			break;
		default:
			assert(0);
	};
	if (pos) {
		fwrite(&m_Pos.x, sizeof(float), 1, outfp);
		fwrite(&m_Pos.y, sizeof(float), 1, outfp);
		fwrite(&m_Pos.z, sizeof(float), 1, outfp);
	}
	if (normal) {
		fwrite(&m_Normal.x, sizeof(float), 1, outfp);
		fwrite(&m_Normal.y, sizeof(float), 1, outfp);
		fwrite(&m_Normal.z, sizeof(float), 1, outfp);
	}
	if (uv) {
		fwrite(&m_UV.u, sizeof(float), 1, outfp);
		fwrite(&m_UV.v, sizeof(float), 1, outfp);
	}
}
