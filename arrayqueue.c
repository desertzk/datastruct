#include "arrayqueue.h"

arrayqueue * arrayqueue_init(size_t init_size)
{
	arrayqueue *pqueue = calloc(0, sizeof(arrayqueue));
	seqarray *parr = array_init(init_size);
	pqueue->seqarr = parr;
	return pqueue;
}

//inserts element at the end O(1)
int arrayqueue_push(arrayqueue *pqueue, object obj)
{

	return array_push_back(pqueue->seqarr, obj);
}

//	removes the first element O(n)
int arrayqueue_pop(arrayqueue *pqueue)
{
	if (!arrayqueue_empty(pqueue))
	{//empty
		return NULL;
	}
	return array_delete(pqueue->seqarr, 0);
}



bool arrayqueue_empty(arrayqueue * pqueue)
{
	return array_size(pqueue->seqarr)==0?true:false;
}

//	access the first element
object arrayqueue_front(arrayqueue *pqueue)
{
	if (!arrayqueue_empty(pqueue))
	{//empty
		return NULL;
	}

	return array_get(pqueue->seqarr, 0);
}


int arrayqueue_destory(arrayqueue *pqueue)
{
	if (pqueue == NULL)
		return DATASTRUCTERROR;
	array_destory(pqueue->seqarr);

	free(pqueue);
	pqueue = NULL;
	return DATASTRUCTSUCCESS;
}


