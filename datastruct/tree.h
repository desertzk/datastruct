#pragma once
#include"datastructpublic.h"


typedef struct _treenode
{
	struct _treenode *left;
	struct _treenode *right; 
	object data;
}treenode;