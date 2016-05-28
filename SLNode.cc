#include <iostream>
#include "SLNode.h"

SLNode::SLNode()
{
	next = NULL;
}
SLNode::SLNode(element_type arg_data):LNode(arg_data)
{
	next = NULL;
}

SLNode::~SLNode()
{
}



