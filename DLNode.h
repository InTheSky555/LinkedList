#ifndef _DLNODE_H
#define _DLNODE_H

#include <iostream>
#include "LNode.h"
class DLNode:public LNode
{
public:
	DLNode();
	DLNode(element_type arg_data);
	~DLNode();
public:
	DLNode *pre;
	DLNode *next;
};

#endif
