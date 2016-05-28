#ifndef _BLNODE_H
#define _BLNODE_H

#include <iostream>
#include "LNode.h"
class BLNode:public LNode
{
public:
	BLNode();
	BLNode(element_type data);
	~BLNode();
public:
	BLNode *left;
	BLNode *right;
};

#endif

