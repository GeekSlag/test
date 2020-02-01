#include <stdio.h>
#include <assert.h>
//#include "dbg.h"

unsigned int rwcsv(char *path)
{
	FILE *fp = NULL;
	char line[1024] = "";
	char *str_tmp = NULL;

	assert(NULL != path);

	fp = fopen(path, "rw");
	assert(NULL != fp);

	while ((str_tmp = fgets(line, 1024, fp))) {
		//PRT_VAR("%s\n", line);
		//PRT_VAR("%s\n", str_tmp);
		fp++;
	}

	fclose(fp);

	return 0;
}
