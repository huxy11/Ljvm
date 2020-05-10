#include "cfparse.h"

int cf_parse(char *filename) {
	CF_header header;
	CF_info info;
	int fp = fopen(filename, 'r');
	assert(fp);
	fseek(filename, 0, 0);
	fread(&header, sizeof(header));
	printf("%#x, %#x, %#x\n", header.magic, header.minor_version, header.major_version);
	fs_close;
	return 0;
}

int main(int args, char* argv[]) {
	cf_parse(""
}
