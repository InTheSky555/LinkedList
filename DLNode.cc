#include <iostream>
#include "DLNode.h"
DLNode::DLNode()
{
	pre = NULL;
	next = NULL;
}
DLNode::DLNode(element_type arg_data):LNode(arg_data)
{
	pre = NULL;
	next = NULL;
}
DLNode::~DLNode()
{

}
