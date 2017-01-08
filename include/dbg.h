#ifndef _DBG_H_
#define _DBG_H_

#define PRT_VAR(FORMAT, VAR) printf("== %-16s : "FORMAT"\n", #VAR, VAR)

void prt_args(char *fmt, ...);
#define DBG_LOG(...)\
do {\
	prt_args("[%s %s %s:%d]\n", __DATE__, __FILE__, __FUNCTION__, __LINE__);\
	prt_args(__VA_ARGS__);\
} while(0)

void prt_asterisk(void);

#endif
