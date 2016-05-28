#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include "SLinkedList.h"

class Stack : public SLList
{
public:
	Stack();
	~Stack();
public:
	bool push(element_type data);
	element_type pop();
};

#endif 
