#include "linkstack.h"

linkstack * linkstack_init()
{
	linkstack *pstack = malloc(sizeof(linkstack));
	pstack->top = NULL;
	return pstack;
}

linkstack * linkstack_push(linkstack * pstack, object obj)
{
	node *pnode = malloc(sizeof(node));
	pnode->data = obj;
	pnode->next = pstack->top;
	pstack->top = pnode;

	return pstack;
}

object  linkstack_pop(linkstack * pstack)
{
	node *pnode = pstack->top;
	pstack->top = pnode->next;
	object data = pnode->data;
	free(pnode);
	return data;
}

int linkstack_destory(linkstack * pstack)
{
	return 0;
}
