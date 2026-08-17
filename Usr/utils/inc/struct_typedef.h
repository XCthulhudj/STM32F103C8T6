#ifndef STRUCT_TYPEDEF_H
#define STRUCT_TYPEDEF_H

#include <stdint.h> //uint32_t, int32_t
#include <stddef.h> //size_t

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
// typedef unsigned int uint32_t;

typedef signed char int8_t;
typedef signed short int16_t;
// typedef signed int int32_t;

typedef volatile unsigned char vuint8_t;
typedef volatile unsigned short vuint16_t;
typedef volatile unsigned int vuint32_t;

typedef volatile signed char vint8_t;
typedef volatile signed short vint16_t;
typedef volatile signed int vint32_t;

typedef float fp32_t;
typedef double fp64_t;

#endif
