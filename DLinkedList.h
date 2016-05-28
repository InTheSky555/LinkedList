#ifndef _DLINKEDLIST_H
#define _DLINKEDLIST_H

#include <iostream>
#include "DLNode.h"
#include "LinkedList.h"
class DLList:public LList
{
public:
	DLList();
	~DLList();
public:
	DLNode *head;
	DLNode *tail;
public:
	virtual bool print_list();
	virtual bool make_null();
	virtual DLNode* find(element_type data);
	virtual DLNode* find_previous(element_type data);
	virtual DLNode* find_next(element_type data);
	virtual DLNode* find_kth(int position);
	virtual	bool insert(int position, element_type data);
	virtual bool delete_key(element_type data);
	virtual element_type delete_kth(int position);
	virtual bool is_empty();
	virtual bool is_last(element_type data);
};


#endif






