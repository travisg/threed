#ifndef __SHARED_DEFINES_H
#define __SHARED_DEFINES_H

#if _WIN32
#include <BaseTsd.h>
typedef UINT8 uint8_t;
typedef UINT16 uint16_t;
typedef UINT32 uint32_t;
typedef UINT64 uint64_t;
typedef INT8 int8_t;
typedef INT16 int16_t;
typedef INT32 int32_t;
typedef INT64 int64_t;

#define USE_DIRECTX 1
#else
#define USE_OPENGL 1
#endif

#endif
