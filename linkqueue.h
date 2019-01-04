#pragma once
#include"datastructpublic.h"


typedef struct _node {
	object data;
	struct _node *next;
}node;


typedef struct _linkqueue
{
	node *head;
	node *tail;
}linkqueue;



extern linkqueue *linkqueue_init();

extern int linkqueue_push(linkqueue *pqueue, object obj);

extern object linkqueue_pop(linkqueue *pqueue);

extern int linkqueue_destory(linkqueue *pqueue);

