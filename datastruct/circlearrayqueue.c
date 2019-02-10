#include "circlearrayqueue.h"

circlearrayqueue * circlearrayqueue_init(size_t init_size)
{
	circlearrayqueue *pqueue = calloc(1, sizeof(circlearrayqueue));
	pqueue->data = calloc(init_size , sizeof(object));
	//pqueue->size = 0;
	pqueue->capacity = init_size;

	
	return pqueue;
}

int circlearrayqueue_push(circlearrayqueue * pqueue, object obj)
{
	if (pqueue == NULL)
		return DATASTRUCTERROR;

	if (NULL == obj)
	{
		return DATASTRUCTARGSERROR;
	}

	pqueue->tail = (pqueue->tail + 1) % pqueue->capacity;
	if (pqueue->tail == pqueue->head)
	{
		
		if (pqueue->tail == 0)//Prevent variables from changing to negative numbers
			pqueue->tail = pqueue->capacity - 1;
		else
			--pqueue->tail;

		//nead realoc memory

	}

	pqueue->data[pqueue->tail] = obj;


	return 0;
}

int circlearrayqueue_pop(circlearrayqueue * pqueue)
{
	if (pqueue == NULL)
		return DATASTRUCTERROR;
	if ( pqueue->head == pqueue->tail)
	{
		//empty
		return DATASTRUCTERROR;
	}

	pqueue->data[pqueue->head] = NULL;
	pqueue->head= (pqueue->head+1) % pqueue->capacity;

	return 0;
}

bool circlearrayqueue_empty(circlearrayqueue * pqueue)
{
	return false;
}

object circlearrayqueue_front(circlearrayqueue * pqueue)
{
	return NULL;
}

int circlearrayqueue_destory(circlearrayqueue * pqueue)
{
	return 0;
}
