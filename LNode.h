#ifndef _LNODE_H
#define _LNODE_H
typedef int element_type;
class LNode
{
public:
	LNode();
	LNode(element_type arg_data);
	~LNode();
public:
	int data;
};


#endif
