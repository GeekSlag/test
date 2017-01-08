#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include "dbg.h"

unsigned int rwcsv(char *path);

int main(int argc, char *argv[])
{
	//assert(argc == 2);

	//prt_asterisk();
	//rwcsv(argv[1]);
	//prt_asterisk();

	DBG_LOG("Hello test...\n");
	//prt_args("%s %d\n", argv[0], argc);

	return 0;
}
