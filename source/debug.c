#include <stdio.h>
#include <stdarg.h>
//#include <string.h>
#include "debug.h"

void prt_asterisk(void)
{
	unsigned char cnt = 80;

	while (cnt-- > 0)
		printf("*");

	printf("\n");
}

void prt_args(char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vprintf(fmt, ap);

	va_end(ap);
}
