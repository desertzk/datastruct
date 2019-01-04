#include "arraystack.h"

arraystack * arraystack_init(size_t init_size)
{
	arraystack *pstack= calloc(0, sizeof(arraystack));
	seqarray *parr=array_init(init_size);
	pstack->seqarr = parr;
	return pstack;
}
//add tail
int arraystack_push(arraystack *pstack,object obj)
{
	
	return array_push_back(pstack->seqarr, obj);
}
//remove head
int arraystack_pop(arraystack *pstack)
{
	return array_delete(pstack->seqarr, pstack->seqarr->size - 1);
}

object arraystack_top(arraystack *pstack)
{
	return array_get(pstack->seqarr, pstack->seqarr->size - 1);
}


int arraystack_destory(arraystack *pstack)
{
	if (pstack == NULL)
		return DATASTRUCTERROR;
	array_destory(pstack->seqarr);

	free(pstack);
	pstack = NULL;
	return DATASTRUCTSUCCESS;
}


