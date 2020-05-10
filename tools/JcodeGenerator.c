#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

static char code_buf[255];
static char *code_main = 
"public class Test {"
"	public int t = 0;"
"	public static void main(String[] args){"
"		Test test = new Test();"
"		test.int_0 = 5;"
"	}";

static char *method_format = 
"public static int test_%d(){"
"	return %d + %d;"
"}";
static char *publicint_format = 
"public int int_%d;";

int main(int args, char* argv[]) {
	FILE *fp = fopen("/tmp/Test.java", "w");
	assert(fp);
	int32_t cnt = 5;
	//scanf("%d", &cnt);	
	printf("Generating Java code, methods counts = %d\n", cnt);
	fputs(code_main, fp);
	for (int32_t i = 0; i < cnt; ++i){
		sprintf(code_buf, method_format, i, i, i);
		fputs(code_buf, fp);
		sprintf(code_buf, publicint_format, i);
		fputs(code_buf, fp);
	}
	fputs("}", fp);
	fclose(fp);
	int ret = system("javac /tmp/Test.java");
	assert(ret);
}
