#include <stdio.h>
//#include <assert.h>
#include "debug.h"

int main(int argc, char *argv[])
{
	unsigned int ret = 0;

    LOGGER(0, D_INFO, "ret(%#x)\n", ret);
    LOGGER(0, D_WARNING, "warning\n", ret);
    LOGGER(0, D_ERROR, "error!\n", ret);

	return ret;
}
