#ifndef _SLINKEDLIST_H
#define _SLINKEDLIST_H
#include "LinkedList.h"
#include "SLNode.h"
class SLList:public LList
{
public:
	SLList();
	~SLList();
public:
	SLNode *head;
public:
	virtual bool print_list();
	virtual bool make_null();
	virtual SLNode* find(element_type data);
	virtual SLNode* find_previous(element_type data);
	virtual SLNode* find_next(element_type data);
	virtual SLNode* find_kth(int position);
	virtual	bool insert(int position, element_type data);
	virtual bool delete_key(element_type data);
	virtual element_type delete_kth(int position);
	virtual bool is_empty();
	virtual bool is_last(element_type data);

};
#endif
