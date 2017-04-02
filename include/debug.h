#ifndef _DEBUG_H_
#define _DEBUG_H_

#define D_INFO (1)
#define D_WARNING (2)
#define D_ERROR (3)
 
#define PRT_INFO(fmt, ...) printf("\e[1;32m|INFO|\e[0m "fmt, ##__VA_ARGS__)
#define PRT_WARNING(fmt, ...) printf("\e[1;33m|WARNING|\e[0m "fmt, ##__VA_ARGS__)
#define PRT_ERROR(fmt, ...) printf("\e[1;31m|ERROR|\e[0m "fmt, ##__VA_ARGS__)
#define LOGGER(mod_id, dbg_flg, fmt, ...) \
do { \
    if (D_INFO == dbg_flg) \
        PRT_INFO(fmt, ##__VA_ARGS__); \
    if (D_WARNING == dbg_flg) \
        PRT_WARNING(fmt, ##__VA_ARGS__); \
    if (D_ERROR == dbg_flg) \
        PRT_ERROR(fmt, ##__VA_ARGS__); \
} while(0) 

#endif
