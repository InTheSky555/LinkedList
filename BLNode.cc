#include "BLNode.h"
BLNode::BLNode()
{
	left = NULL;
	right = NULL;

}
BLNode::BLNode(element_type data):LNode(data)
{
	left = NULL;
	right = NULL;
}
BLNode::~BLNode()
{



}
