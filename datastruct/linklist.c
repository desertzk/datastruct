#include "linklist.h"

linklist * linklist_init()
{
	linklist *plist = malloc(sizeof(linklist));
	plist->first = NULL;
	
	return plist;
}

int linklist_insert_byindex(linklist *list , object obj, int index)
{
	if (list == NULL)
		return DATASTRUCTERROR;

	//find
	node *pcurnode = list->first;

	while (pcurnode&&--index)
	{
		pcurnode = pcurnode->next;
	}
	//add
	node *pnewnd = malloc(sizeof(node));
	pnewnd->data = obj;
	pnewnd->next = pcurnode->next;
	pcurnode->next = pnewnd;


	return 0;
}

//add before obj2 
int linklist_insert(linklist *list, object obj, object obj2,bool (*funcequal)(obj, obj2))
{
	if (list == NULL)
		return DATASTRUCTERROR;
	//find
	node *pcurnode = list->first;

	while (pcurnode&&!funcequal(pcurnode->data,obj2))
	{
		pcurnode = pcurnode->next;
	}
	//add
	node *pnewnd = malloc(sizeof(node));
	pnewnd->data = obj;
	pnewnd->next = pcurnode->next;
	pcurnode->next = pnewnd;


	return 0;
}



int linklist_delete(linklist * list, object obj,bool(*funcequal)(obj, obj2))
{
	if (list == NULL)
		return DATASTRUCTERROR;
	node *pcurnode = list->first;
	if (pcurnode&&funcequal(pcurnode->data, obj))//first
	{
		list->first = pcurnode->next;
		free(pcurnode);
		return 0;
	}

	node *ppostnode = pcurnode->next;
	while (!funcequal(ppostnode->data, obj) && ppostnode->next)
	{
		pcurnode = ppostnode;
		ppostnode = ppostnode->next;
	}

	if (funcequal(pcurnode->data, obj))
	{
		pcurnode->next = ppostnode->next;
		free(ppostnode);
		return 0;
	}
	
	return -1;
	
}

//add head
int linklist_push_front(linklist * list, object obj)
{
	if (list == NULL)
		return DATASTRUCTERROR;
	node *pnewnd = malloc(sizeof(node));
	pnewnd->data = obj;
	pnewnd->next = list->first;
	list->first = pnewnd;
	return 0;
}

object linklist_get(linklist * list, int index)
{
	if (list == NULL)
		return NULL;
	//find
	node *pcurnode = list->first;

	while (pcurnode&&--index)
	{
		pcurnode = pcurnode->next;
	}
	return pcurnode->data;
}

size_t linklist_size(linklist * list)
{
	if (list == NULL)
		return DATASTRUCTERROR;
	node *pcurnode = list->first;
	size_t size = 0;
	while (pcurnode)
	{
		++size;
		pcurnode = pcurnode->next;
	}
	return size;
}

void remove_duplicates(linklist * list)
{
	node *pnode = list->first;
	for (; pnode->next; pnode= pnode->next)
	{
		node *prenode = pnode;
		node *pcompnode = pnode->next;
		while (pcompnode!= NULL)
		{
			if (pnode->data == pcompnode->data)
			{
				//delete duplicate node
				prenode->next = pcompnode->next;
				
				free(pcompnode);

				pcompnode = prenode->next;
				continue;
			}
			//go to next
			prenode = pcompnode;
			pcompnode = pcompnode->next;
		}
	}
	

}

int linklist_insert_withorder(linklist * list, object obj)
{
	node *pnode = list->first;
	node *pnewnode = malloc(sizeof(node));
	pnewnode->data = obj;
	if (obj < pnode)
	{
		list->first = pnewnode;
		pnewnode->next = pnode;
		return 0;
	}
	//find
	while (pnode&&obj > pnode->next->data)
	{
		pnode = pnode->next;
	}

	//insert
	
	pnewnode->next = pnode->next;

	pnode->next = pnewnode;
	return 0;
}



int linklist_destory(linklist * list)
{
	if (list == NULL)
		return DATASTRUCTERROR;
	node *pcurnode = list->first;
	while (pcurnode)
	{
		pcurnode = pcurnode->next;
		free(pcurnode);
	}
	free(list);
	return 0;
}


void print_list(linklist * list)
{
	for (node *pnode = list->first; pnode; pnode = pnode->next)
	{
		printf("   %d  \n", pnode->data);
	}
}



int main0103()
{
	linklist * list = linklist_init();
	linklist_push_front(list,18);
	linklist_push_front(list, 14);
	linklist_push_front(list, 10);
	linklist_push_front(list, 9);
	linklist_push_front(list, 4);
	linklist_insert_withorder(list,11);
	print_list(list);
	linklist_insert_withorder(list, 1);
	/*linklist_push_front(list, 97);
	linklist_push_front(list, 12);
	linklist_push_front(list, 12);
	linklist_push_front(list, 16);
	linklist_push_front(list, 12);
	linklist_push_front(list, 22);
	linklist_push_front(list, 32);
	linklist_push_front(list, 72);
	linklist_push_front(list, 19);
	linklist_push_front(list, 25);
	linklist_push_front(list, 36);
	linklist_push_front(list, 12);
	linklist_push_front(list, 14);
	linklist_push_front(list, 41);
	linklist_push_front(list, 99);
	print_list(list);
	remove_duplicates(list);*/
	print_list(list);

	//+ 1
	return 0;
}



