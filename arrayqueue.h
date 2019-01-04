#pragma once
#include"seqarray.h"
//FIFO
typedef struct _arrayqueue
{
	seqarray *seqarr;
}arrayqueue;



extern arrayqueue *arrayqueue_init(size_t init_size);


extern int arrayqueue_push(arrayqueue *pqueue, object obj);

extern int arrayqueue_pop(arrayqueue *pqueue);

extern bool arrayqueue_empty(arrayqueue *pqueue);


extern object arrayqueue_front(arrayqueue *pqueue);

//extern size_t arrayqueue_size();

int arrayqueue_destory(arrayqueue *pqueue);