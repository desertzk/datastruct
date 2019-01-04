#pragma once

#include"datastructpublic.h"
//FIFO
typedef struct _circlearrayqueue
{
	object *data;
	int head;
	int tail;
	size_t size;
	size_t capacity;
}circlearrayqueue;



extern circlearrayqueue *circlearrayqueue_init(size_t init_size);


extern int circlearrayqueue_push(circlearrayqueue *pqueue, object obj);

extern int circlearrayqueue_pop(circlearrayqueue *pqueue);

extern bool circlearrayqueue_empty(circlearrayqueue *pqueue);


extern object circlearrayqueue_front(circlearrayqueue *pqueue);

//extern size_t circlearrayqueue_size();

int circlearrayqueue_destory(circlearrayqueue *pqueue);