#ifndef _DBG_H_
#define _DBG_H_

void prt_args(char *fmt, ...);
#define PRT_VAR(FORMAT, VAR) prt_args("== %-16s : "FORMAT, #VAR, VAR)
#define DBG_PRT(...)\
do {\
	prt_args("[%s %s:%d] ", __FILE__, __FUNCTION__, __LINE__);\
	prt_args(__VA_ARGS__);\
} while(0)

void prt_asterisk(void);
#define PRT_AST() prt_asterisk()

#endif
