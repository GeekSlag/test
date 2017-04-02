#ifndef _DEBUG_H_
#define _DEBUG_H_

#define INFO (1)
#define WARNING (2)
#define ERROR (3)
 
#define PRT_LITERAL(literal) printf(#literal);
#define PRT_INFO(fmt, ...) printf("\e[32m|INFO|\e[0m "fmt, ##__VA_ARGS__)
#define PRT_WARNING(fmt, ...) printf("\e[33m|WARNING|\e[0m "fmt, ##__VA_ARGS__)
#define PRT_ERROR(fmt, ...) printf("\e[31m|ERROR|\e[0m "fmt, ##__VA_ARGS__)
#define LOGGER(mod_id, dbg_flg, fmt, ...) \
do { \
    if (INFO == dbg_flg) { \
        printf("\e[1m|"#mod_id"|\e[0m"); \
        PRT_INFO(fmt, ##__VA_ARGS__); \
    } \
    if (WARNING == dbg_flg) { \
        printf("\e[1m|"#mod_id"|\e[0m"); \
        PRT_WARNING(fmt, ##__VA_ARGS__); \
    } \
    if (ERROR == dbg_flg) { \
        printf("\e[1m|"#mod_id"|\e[0m"); \
        PRT_ERROR(fmt, ##__VA_ARGS__); \
    } \
} while(0) 

#endif
