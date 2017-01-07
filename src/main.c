#include <stdio.h>
#include "dbg.h"

int main(int argc, char *argv[])
{
	unsigned char c = 0;

	prt_asterisk(32);
	PRT_VAR(c);
	PRT_VAR(0x0101^0x0);
	prt_asterisk(32);

	return 0;
}
