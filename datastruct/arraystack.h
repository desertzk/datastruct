#pragma once
#include"seqarray.h"

typedef struct _arraystack
{
	seqarray *seqarr;
}arraystack;



extern arraystack *arraystack_init(size_t init_size);


extern int arraystack_push(arraystack *pstack,object obj);

extern int arraystack_pop(arraystack *pstack);

extern object arraystack_top(arraystack *pstack);

//extern size_t arraystack_size();

int arraystack_destory(arraystack *pstack);