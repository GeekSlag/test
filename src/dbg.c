#include <stdio.h>
#include <stdarg.h>
#include <string.h>

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
	//char *str = NULL;
	//char c = '\0';
	//unsigned int i = 0;

	va_start(ap, fmt);
	/*
	while (*fmt) {
		if (0 == strncmp(fmt, "\%c", strlen(fmt))) {
			c = (char)va_arg(ap, int);
			printf(fmt, c);
			fmt++;
			continue;
		}

		if (0 == strncmp(fmt, "\%d", strlen(fmt))) {
			i = va_arg(ap, int);
			printf(fmt, i);
			fmt++;
			continue;
		}

		if (0 == strncmp(fmt, "\%s", strlen(fmt))) {
			str = va_arg(ap, char *);
			printf(fmt, str);
			fmt++;
			continue;
		}
	}
	*/

	vprintf(fmt, ap);

	va_end(ap);
}
