#pragma once
#include"datastructpublic.h"


typedef struct _node {
	object data;
	struct _node *next;
}node;


typedef struct _linkstack
{
	node *top;
}linkstack;




extern linkstack *linkstack_init();

extern linkstack *linkstack_push(linkstack *pstack, object obj);

extern object linkstack_pop(linkstack *pstack);

extern int linkstack_destory(linkstack *pstack);
