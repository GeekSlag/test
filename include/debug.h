#ifndef _DBG_H_
#define _DBG_H_

#define D_INFO (1)
#define D_WARNING (2)
#define D_ERROR (3)
 
#define PRT_INFO(fmt, ...) printf("\e[1;32m|INFO|\e[0m "fmt, __VA_ARGS__)
#define PRT_WARNING(fmt, ...) printf("\e[1;33m|WARNING|\e[0m "fmt, __VA_ARGS__)
#define PRT_ERROR(fmt, ...) printf("\e[1;31m|ERROR|\e[0m "fmt, __VA_ARGS__)
#define LOGGER(mod_id, dbg_flg, fmt, ...) \
    do { \
        if (D_INFO == dbg_flg) \
            PRT_INFO(fmt, __VA_ARGS__); \
        if (D_WARNING == dbg_flg) \
            PRT_WARNING(fmt, __VA_ARGS__); \
        if (D_ERROR == dbg_flg) \
            PRT_ERROR(fmt, __VA_ARGS__); \
    } while(0) 

/****************************************************************************/
void prt_args(char *fmt, ...);
#define PRT_VAR(FORMAT, VAR) prt_args("\e[33m|INFO|\e[0m %-16s : "FORMAT, #VAR, VAR)
#define DBG_PRT(...)\
do {\
	prt_args("[%s %s:%d] ", __FILE__, __FUNCTION__, __LINE__);\
	prt_args(__VA_ARGS__);\
} while(0)

void prt_asterisk(void);
#define PRT_AST() prt_asterisk()
/****************************************************************************/

#endif
