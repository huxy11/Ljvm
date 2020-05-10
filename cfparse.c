#include "cfparse.h"

int cf_parse(char *filename) {
	CF_header header;
	CF_constpool constpool;
	load_classfile(filename);
	header.magic = get_u4();
	header.minor_version = get_u2();
	header.major_version = get_u2();
	constpool.cnt = get_u2();	
	for (int i = 0; i < constpool.cnt; ++i) {
	}
	return 0;
}

int main(int args, char* argv[]) {
	cf_parse("Test.class");
}
