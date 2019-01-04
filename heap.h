#pragma once

#include"seqarray.h"



typedef struct _heap {
	seqarray arr;
	int(*pcompare)(object obj1, object obj2);
}heap;


extern heap *heap_create(size_t initsize);

extern int heap_insert(heap *pheap, object obj);

#define ElementType int
typedef struct HeapStruct *MaxHeap;

struct HeapStruct {
	ElementType *Elements;
	int Size;
	int Capacity;
};

