#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>

typedef struct {
	void 	*buf;
	uint32_t last;
	uint32_t capacity;
}stack;


#endif
