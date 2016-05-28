#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include "LNode.h" 
class LList
{
public:
	LList();
	~LList();
public:
	int length;
public:
	virtual bool print_list() = 0;
	virtual bool make_null() = 0;
	virtual LNode* find(element_type data) = 0;
	virtual LNode* find_previous(element_type data) = 0;
	virtual LNode* find_next(element_type data) = 0;
	virtual LNode* find_kth(int position) = 0;
	virtual	bool insert(int position, element_type data) = 0;
	virtual bool delete_key(element_type data) = 0;
	virtual element_type delete_kth(int position) = 0;
	virtual bool is_empty() = 0;
	virtual bool is_last(element_type data) = 0;
};



#endif
