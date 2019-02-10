#pragma once
#include"datastructpublic.h"

#define elementtype int

typedef struct _node {
	object data;
	struct _node *next;
}node;

//head node
typedef struct _linklist {
	node *first;
}linklist;

extern linklist *linklist_init();

extern int linklist_insert_byindex(linklist *arr, object obj, int index);

extern int linklist_insert(linklist *list, object obj, object obj2, bool(*funcequal)(obj, obj2));

extern int linklist_delete(linklist * list, object obj, bool(*funcequal)(obj, obj2));

extern int linklist_push_front(linklist *arr, object obj);

extern object linklist_get(linklist *arr, int index);

extern size_t linklist_size(linklist * arr);

extern void remove_duplicates(linklist * arr);

extern int linklist_destory(linklist *arr);