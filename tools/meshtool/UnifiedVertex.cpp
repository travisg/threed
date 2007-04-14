#include <stdio.h>
#include "UnifiedVertex.h"

void UnifiedVertex::Write(FILE *outfp) const
{
	fwrite(&m_Pos.x, sizeof(float), 1, outfp);
	fwrite(&m_Pos.y, sizeof(float), 1, outfp);
	fwrite(&m_Pos.z, sizeof(float), 1, outfp);
	fwrite(&m_Normal.x, sizeof(float), 1, outfp);
	fwrite(&m_Normal.y, sizeof(float), 1, outfp);
	fwrite(&m_Normal.z, sizeof(float), 1, outfp);
	fwrite(&m_UV.u, sizeof(float), 1, outfp);
	fwrite(&m_UV.v, sizeof(float), 1, outfp);
}
