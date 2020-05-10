#ifndef __CFPARSE_H__
#define __CFPARSE_H__
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "macro.h"

#define POOL_SIZE 255
#define C(x) concat3(CONSTANT_, x , _info)

enum { C(Utf8) = 1, C(Integer) = 3, C(Float), C(Long), C(Double), \
	C(Class), C(String), C(Fieldref), C(Methodref), C(InterfaceMethodref), \
	C(NameAndType)};
static FILE* cfp;

typedef struct {
	uint32_t magic;
	uint16_t minor_version;
	uint16_t major_version;
} CF_header;

typedef struct {
	uint16_t cnt;
} CF_constpool;

static inline void load_classfile(char* filename) {
	cfp = fopen(filename, "r");
	assert(cfp);
	fseek(cfp, 0, 0);
}
static inline uint8_t get_u1(void) {
	uint8_t ret;
	fread(&ret, 1, 1, cfp);
	return ret;
}
static inline uint16_t get_u2(void) {
	uint16_t ret;
	fread(&ret, 2, 1, cfp);
	for (int i = 0; i < 2/2; ++i) {
		char *h, *l;
		uint8_t tmp;
		l = ((char*)(&ret) + i);
		h = (char*)(l + 2 - 1 - 2 * i);
		tmp = *h;
		*h = *l;
		*l = tmp;
	}
	return ret;
}
static inline uint32_t get_u4(void) {
	uint32_t ret;
	fread(&ret, 4, 1, cfp);
	for (int i = 0; i < 4/2; ++i) {
		char *h, *l;
		uint8_t tmp;
		l = ((char*)(&ret) + i);
		h = (char*)(l + 4 - 1 - 2 * i);
		tmp = *h;
		*h = *l;
		*l = tmp;
	}
	return ret;
}

#endif
