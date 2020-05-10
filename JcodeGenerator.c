#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

static char code_buf[255];
static char *code_main = 
"public class Test {"
"	public int t = 0;"
"	public static void main(String[] args){"
"		Test test = new Test();"
"		test.a = 8;"
"	}";

static char *code_format = 
"public static int test_%d(){"
"	return %d + %d;"
"}";

int main(int args, char* argv[]) {
	FILE *fp = fopen("/home/hu/Test.java", "w");
	assert(fp);
	int32_t cnt;
	scanf("%d", &cnt);	
	printf("Generating Java code, methods counts = %d\n", cnt);
	fputs(code_main, fp);
	for (int32_t i = 0; i < cnt; ++i){
		sprintf(code_buf, code_format, i, i, i);
		fputs(code_buf, fp);
	}
	fputs("}", fp);
	fclose(fp);
}
