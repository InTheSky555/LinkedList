#include "Stack.h"

Stack::Stack():SLList()
{



}

Stack::~Stack()
{


}


bool Stack::push(element_type data)
{
	this->insert(1,data);
	return true;
}

element_type Stack::pop()
{
	element_type data;
	data = this->delete_kth(1);
	return data;
}




