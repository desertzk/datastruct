#pragma once
#include"datastructpublic.h"



typedef struct _seqarray
{
	//a place hold 
	object* data;
	size_t size;
	size_t capacity;
}seqarray;





extern seqarray *array_init(int init_size);
 
extern int array_insert(seqarray *arr, object obj,int index);
 
extern int array_delete(seqarray *arr, int index);

extern int array_push_back(seqarray *arr, object obj);

extern object array_get(seqarray *arr, int index);

extern size_t array_size(seqarray * arr);

extern size_t array_capacity(seqarray * arr);

extern int array_destory(seqarray *arr);