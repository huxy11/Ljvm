#include "fs.h"
#include "macro.h"

#define C(x) contact3(CONSTANT_, x , _info)
#define BUFF_SIZE 255

enum { C(Utf8) = 1, C(Integer) = 3, C(Float), C(Long), C(Double), \ 
	C(Class), C(String), C(Fieldref), C(Methodref), C(InterfaceMethodref) \
	C(NameAndType)};

typedef struct {
	uint32_t magic;
	uint16_t minor_version;
	uint16_t major_version;
} CF_header;

typedef struct {
	uint16_t cnt;
	uint32_t buf[BUFF_SIZE];
} CF_info;
