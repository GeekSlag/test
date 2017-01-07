#ifndef _DBG_H_
#define _DBG_H_

#define PRT_VAR(VAR) printf("== %-16s : %#x\n", #VAR, VAR)

void prt_asterisk(unsigned int num);

#endif
