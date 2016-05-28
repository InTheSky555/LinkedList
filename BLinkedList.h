#ifndef _BLINKEDLIST_H
#define _BLINKEDLIST_H

#include <iostream>
#include "BLNode.h"
#include "LinkedList.h"
class BLList//:public LList
{
public:
	BLList();
	~BLList();
public:
	BLNode *root;
public:

	virtual bool print_list();
//	virtual bool make_null();
	virtual BLNode* find(element_type data);
	virtual	bool insert(element_type data);
	virtual bool insert(BLNode* root, element_type data);
//	virtual bool delete_key(element_type data);
//	virtual element_type delete_kth(int position);
//	virtual bool is_empty();
	virtual void midorder(BLNode* root);
};



#endif



