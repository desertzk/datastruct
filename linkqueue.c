#include "linkqueue.h"

linkqueue * linkqueue_init()
{
	linkqueue * pqueue = malloc(sizeof(linkqueue));
	pqueue->head = NULL;
	pqueue->tail = NULL;
	return pqueue;
}

int linkqueue_push(linkqueue * pqueue, object obj)
{
	node * pnode = malloc(sizeof(node));
	pnode->data = obj;
	pnode->next = NULL;
	if (pqueue->head==NULL)
	{
		pqueue->head = pnode;
	}
	else {
		pqueue->tail->next = pnode;//先放入
	}
	pqueue->tail = pnode;//然后指向最后一个放入的
	return 0;
}

object linkqueue_pop(linkqueue * pqueue)
{
	object ret=NULL;
	if (pqueue->head == NULL)
		return NULL;
	node *popnode = pqueue->head;
	ret = popnode->data;
	pqueue->head = popnode->next;
	free(popnode);
	return ret;
}

int linkqueue_destory(linkqueue * pqueue)
{
	return 0;
}
