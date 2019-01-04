#include"tree.h"
#include"arrayqueue.h"

void BFS(treenode *t)
{
	arrayqueue *pqueue=arrayqueue_init(50);


	arrayqueue_push(pqueue, t);

	while (!arrayqueue_empty(pqueue))
	{
		treenode *pnode = arrayqueue_pop(pqueue);
		printf("%d\n",pnode->data);
		if(pnode->left)
			arrayqueue_push(pqueue, pnode->left);
		if(pnode->right)
			arrayqueue_push(pqueue, pnode->right);
	}

}