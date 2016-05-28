#include "DLinkedList.h"
DLList::DLList()
{
	DLNode *header = new DLNode(0);
	DLNode *tailer = new DLNode(0);
	head = header;
	tail = tailer;
	head->next = tail;
	tail->pre = head;
}
DLList::~DLList()
{

}
bool DLList::print_list()
{
	DLNode *ptr = NULL;
	for(ptr = head->next; ptr->next != NULL; ptr = ptr->next)
	{
		std::cout  << ptr->data << "<->";
	}
	std::cout << std::endl;
	return true;
}

bool DLList::make_null()
{
	DLNode *ptr = NULL;
	while(length != 0)	
	{
		ptr = head;
		head = head->next;
		delete(ptr);	
		length--;
	}
	return true;
}

DLNode* DLList::find( element_type data)
{
	DLNode *ptr= NULL;
	for(ptr = head; ptr->next != NULL; ptr = ptr->next)
	{		
		if(ptr->data == data)
		{
			return ptr;		
		}
	}
	return ptr;
}

DLNode* DLList::find_previous( element_type data)
{
	DLNode *ptr = NULL;
	for(ptr = head; ptr->next != NULL; ptr = ptr->next)
	{
		
		if(ptr->next->data == data)
		{
			return ptr;		
		}
	}
	return ptr;
}

DLNode* DLList::find_next( element_type data)
{
	DLNode *ptr= NULL;
	for(ptr = head; ptr->next != NULL; ptr = ptr->next)
	{
		
		if(ptr->data == data)
		{
			return ptr->next;		
		}
	}
	return ptr;
}

DLNode* DLList::find_kth( int position)
{
	DLNode *ptr = NULL;
	int pos =0;

	ptr = head;
	if((0 <= position)&&( position <= length))
	{
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
	return NULL;
}

bool DLList::insert(int position, element_type data)//position must > 0
{
	DLNode *ptr = NULL;
	DLNode *newnode = new DLNode(data);
	
	if(( 0 < position )&&( position <= (length+1)))
	{
		ptr = find_kth(position-1);
		newnode->next = ptr->next;
		newnode->pre = ptr;

		ptr->next->pre = newnode;
		ptr->next = newnode;


		length ++;
		return true;	
	}
	else
	{
		return false;
	}
}

bool DLList::delete_key( element_type data)
{
	DLNode *tmp = NULL; 
	DLNode *pre = NULL;
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

element_type DLList::delete_kth( int position)//pos must > 0
{
	element_type data_tmp = 0;
	DLNode *ptr = NULL;
	DLNode *tmp = NULL;
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

bool DLList::is_empty()
{
	return (head->next == tail);
}

bool DLList::is_last(element_type data)
{
	DLNode *ptr = find(data);
	return (ptr->next == tail);

}


