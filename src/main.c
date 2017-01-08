#include <stdio.h>
//#include <stdarg.h>
#include <assert.h>
#include "dbg.h"

unsigned int rwcsv(char *path);

int main(int argc, char *argv[])
{
	unsigned int ret = 0;

	assert(argc == 2);
	ret = rwcsv(argv[1]);
	PRT_VAR("%#x\n", ret);

	return ret;
}
