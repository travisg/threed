#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <utils/HostFile.h>

HostFile::HostFile()
:	m_fp(0)
{
}

HostFile::~HostFile()
{
	if (m_fp)
		fclose(m_fp);
}

int HostFile::Open(const char *name)
{
	assert(!m_fp);
	m_fp = fopen(name, "rb");
	if (!m_fp)
		return -1;

	return 0;
}

int HostFile::Read(void *buf, size_t len)
{
	assert(m_fp);

	size_t ret = fread(buf, len, 1, m_fp);
	if (ret == 0)
		return -1;
	return (int)ret;
}

int HostFile::Write(const void *buf, size_t len)
{
	// XXX not implemented
	assert(0);
	return -1;
}

off_t HostFile::Seek(off_t offset)
{
	assert(m_fp);
	if (fseek(m_fp, offset, SEEK_SET) != 0)
		return -1;
	return offset;
}

int HostFile::ReadLine(char *line, size_t linelen)
{
	assert(m_fp);
	if (fgets(line, (int)linelen, m_fp) == 0)
		return -1;

	return (int)strlen(line);
}

