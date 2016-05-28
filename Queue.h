#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include "SLinkedList.h"

class Queue:public SLList
{
public:
	Queue();
	~Queue();
public:
	bool EnQueue(element_type data);
	element_type DeQueue();

};

#endif



