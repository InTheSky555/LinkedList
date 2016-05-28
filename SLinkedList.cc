#include <iostream>
#include "SLinkedList.h"
#include "SLNode.h"
SLList::SLList()
{
	SLNode *header = new SLNode(0);
	head = header;
	length = 0;
}
SLList::~SLList()
{

}

bool SLList::print_list()
{
	SLNode *ptr = NULL;
	for(ptr = head->next; ptr != NULL; ptr = ptr->next)
	{
		std::cout  << ptr->data << "->";
	}
	std::cout << std::endl;
	return true;
}

bool SLList::make_null()
{
	SLNode *ptr = NULL;
	while(length != 0)	
	{
		ptr = head;
		head = head->next;
		delete(ptr);	
		length--;
	}
	return true;
}

SLNode* SLList::find( element_type data)
{
	SLNode *ptr= NULL;
	for(ptr = head; ptr != NULL; ptr = ptr->next)
	{		
		if(ptr->data == data)
		{
			return ptr;		
		}
	}
	return ptr;
}

SLNode* SLList::find_previous( element_type data)
{
	SLNode *ptr = NULL;
	for(ptr = head; ptr->next != NULL; ptr = ptr->next)
	{
		
		if(ptr->next->data == data)
		{
			return ptr;		
		}
	}
	return ptr;
}

SLNode* SLList::find_next( element_type data)
{
	SLNode *ptr= NULL;
	for(ptr = head; ptr->next != NULL; ptr = ptr->next)
	{
		
		if(ptr->data == data)
		{
			return ptr->next;		
		}
	}
	return ptr;
}

SLNode* SLList::find_kth( int position)
{
	SLNode *ptr = NULL;
	int pos =0;

	ptr = head;
	if(position == 0)
	{
		return ptr;
	}
	else
	{
		for(pos = 0; pos < position; pos++)// position must shorter than the length of the queue 
		{
			ptr = ptr->next;			
		}
		return ptr;	
	}
}

bool SLList::insert(int position, element_type data)//position must > 0
{
	SLNode *ptr = NULL;
	SLNode *newnode = new SLNode(data);
	
	if(( 0 < position )&&( position <= (length+1)))
	{
		ptr = find_kth(position-1);

		newnode->next = ptr->next;
		ptr->next = newnode;
		length ++;
		return true;	
	}
	else
	{
		return false;
	}
}

bool SLList::delete_key( element_type data)
{
	SLNode *tmp = NULL; 
	SLNode *pre = NULL;
	pre = find_previous(data);
	{
		tmp = pre->next;
		pre->next = tmp->next;
		delete(tmp);
		length--;
		return true;		
	}
	return false;
}

element_type SLList::delete_kth( int position)//pos must > 0
{
	element_type data_tmp = 0;
	SLNode *ptr = NULL;
	SLNode *tmp = NULL;
	if((length > 0)&&(0 < position)&&(position <= length))
	{
		ptr = find_kth(position-1);
		tmp = ptr->next;
		data_tmp = tmp->data;
		ptr->next = tmp->next;
		length--;
		delete(tmp);	
		return data_tmp;	
	}
	else
	{
		return -1;
	}
}

bool SLList::is_empty()
{
	return (head->next == NULL);
}


bool SLList::is_last(element_type data)
{
	SLNode *ptr = find(data);
	return (ptr->next == NULL);

}

