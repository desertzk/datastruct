#pragma once

#include"datastructpublic.h"



typedef struct _node {
	object data;
	struct _node *next;
	struct _node *previous;
}node;

//head node
typedef struct _doublelinklist {
	node *first;
}doublelinklist;


extern doublelinklist *doublelinklist_init();

extern int doublelinklist_insert_byindex(doublelinklist *arr, object obj, int index);

extern int doublelinklist_insert(doublelinklist *list, object obj, object obj2, bool(*funcequal)(obj, obj2));

extern int doublelinklist_delete(doublelinklist * list, object obj, bool(*funcequal)(obj, obj2));

extern int doublelinklist_push_front(doublelinklist *list, object obj);


extern int doublelinklist_push_back(doublelinklist *list, object obj);


extern object doublelinklist_get(doublelinklist *list, int index);

extern size_t doublelinklist_size(doublelinklist * list);

extern void remove_duplicates(doublelinklist * list);

extern int linklist_destory(doublelinklist *list);