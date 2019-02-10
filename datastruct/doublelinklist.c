#include"doublelinklist.h"

doublelinklist * doublelinklist_init()
{
	doublelinklist *plist = malloc(sizeof(doublelinklist));
	plist->first = NULL;

	return plist;
}

int doublelinklist_insert(doublelinklist * list, object obj, object obj2)
{
	node *pcur = list->first;
	while (pcur->data != obj&&pcur)
		pcur = pcur->next;

	node *pnewnd = malloc(sizeof(node));
	pnewnd->data = obj2;
	pnewnd->next = pcur->next;
	pnewnd->previous = pcur;
	pcur->next = pnewnd;

	return 0;
}

int doublelinklist_delete(doublelinklist * list, object obj)
{
	node *pcur = list->first;
	while (pcur->data != obj&&pcur)
		pcur = pcur->next;

	if (pcur)
	{
		pcur->previous->next = pcur->next;
		pcur->next->previous = pcur->previous;
		free(pcur);
	}
		

	return 0;
}

int doublelinklist_push_back(doublelinklist * list, object obj)
{
	if (list == NULL)
		return DATASTRUCTERROR;
	node *pnewnd = malloc(sizeof(node));
	pnewnd->data = obj;
	pnewnd->next = list->first;
	list->first = pnewnd;
	return 0;
}
