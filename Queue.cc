#include "Queue.h"

Queue::Queue(): SLList()
{


}

Queue::~Queue()
{


}

bool Queue::EnQueue( element_type data)
{
	this->insert(1,data);
	return true;
}
element_type Queue::DeQueue()
{
	element_type data;
	data = this->delete_kth(this->length);		
	return data;
}



