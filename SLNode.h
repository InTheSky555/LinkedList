#ifndef _SLNODE_H
#define _SLNODE_H
#include "LNode.h"

class SLNode:public LNode
{
public:
	SLNode();
	SLNode(element_type arg_data);
	~SLNode();
public:
	SLNode *next;
};




#endif
