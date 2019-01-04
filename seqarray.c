#include"seqarray.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


static int realloc_seqarray(seqarray *parr)
{
	//capacity*2
	parr->capacity <<= 2;
	void *pbegin= calloc(0, parr->capacity * sizeof(object));
	if (pbegin)
		return DATASTRUCTERROR;
	//copy old content
	memcpy(pbegin, parr->data, parr->size * sizeof(object));
	free(parr->data);
	parr->data = pbegin;
	return DATASTRUCTSUCCESS;
}


seqarray *array_init(int init_size)
{
	seqarray *parr = calloc(0, sizeof(seqarray));
	parr->data= calloc(0, init_size*sizeof(object));
	parr->size = 0;
	parr->capacity = init_size;

	return parr;
}

int array_insert(seqarray *parr, object obj, int index)
{
	if (parr == NULL)
		return DATASTRUCTERROR;

	if ( NULL == obj)
	{
		return DATASTRUCTARGSERROR;
	}

	if (parr->size + 1 > parr->capacity)
		realloc_seqarray(parr);

	for (int i = parr->size; i > index; --i)
	{
		parr->data[i] = parr->data[i-1];
	}
	parr->data[index] = obj;

	++parr->size;
	return DATASTRUCTSUCCESS;
}

int array_delete(seqarray *parr, int index)
{
	if (parr == NULL)
		return DATASTRUCTERROR;

	if (index >= parr->size)
		return DATASTRUCTERROR;

	for (int i = index; i < parr->size-1; ++i)
	{
		parr->data[i] = parr->data[i + 1];
	}

	parr->data[parr->size] = NULL;
	--parr->size;
	return DATASTRUCTSUCCESS;
}


//add at tail
int array_push_back(seqarray * arr, object obj)
{
	return array_insert(arr, obj, arr->size-1);
}


size_t array_size(seqarray * arr)
{
	return arr->size;
}


size_t array_capacity(seqarray * arr)
{
	return arr->capacity;
}


object array_get(seqarray * arr, int index)
{
	return arr->data[index];
}




int array_destory(seqarray *parr)
{
	if (parr == NULL)
		return DATASTRUCTERROR;
	if (parr->data)
		free(parr->data);

	free(parr);
	return DATASTRUCTSUCCESS;
}
