#include <iostream>
typedef int element_type;
class LNode
{
public:
	LNode();
	LNode(element_type arg_data);
	~LNode();
public:
	int data;
};
LNode::LNode()
{
	data = 0;
}
LNode::LNode(element_type arg_data)
{
	data = arg_data;
}
LNode::~LNode()
{

}
class SLNode:public LNode
{
public:
	SLNode();
	SLNode(element_type arg_data);
	~SLNode();
public:
	SLNode *next;
};

SLNode::SLNode()
{
	next = NULL;
}
SLNode::SLNode(element_type arg_data):LNode(arg_data)
{
	next = NULL;
}

SLNode::~SLNode()
{
}
class DLNode:public LNode
{
public:
	DLNode();
	DLNode(element_type arg_data);
	~DLNode();
public:
	DLNode *pre;
	DLNode *next;
};
DLNode::DLNode()
{
	pre = NULL;
	next = NULL;
}
DLNode::DLNode(element_type arg_data):LNode(arg_data)
{
	pre = NULL;
	next = NULL;
}
DLNode::~DLNode()
{


}

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

/////////////////////////////////////////////////////////////////////////////////
LList::LList()
{
	length = 0;
}
LList::~LList()
{

}


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
SLList::SLList()
{
	SLNode *header = new SLNode(0);
	head = header;
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
	LNode *ptr = NULL;
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
class DLList:public LList
{
public:
	DLList();
	~DLList();
public:
	DLNode *head;
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

DLList::DLList()
{
	DLNode *header = new DLNode(0);
	head = header;
}
DLList::~DLList()
{

}
bool DLList::print_list()
{
	DLNode *ptr = NULL;
	for(ptr = head->next; ptr != NULL; ptr = ptr->next)
	{
		std::cout  << ptr->data << "->";
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
	for(ptr = head; ptr != NULL; ptr = ptr->next)
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

bool DLList::insert(int position, element_type data)//position must > 0
{
	DLNode *ptr = NULL;
	DLNode *newnode = new DLNode(data);
	
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
	return (head->next == NULL);
}

bool DLList::is_last(element_type data)
{
	DLNode *ptr = find(data);
	return (ptr->next == NULL);

}

int main()
{
	int i = 1;
	SLList sll;
	DLList dll;
	dll.insert(1,10);
	dll.print_list();
	sll.insert(1,11);
	sll.print_list();
	std::cout << "is sll empty?" << sll.is_empty() << std::endl;
	for(i = 1; i < 10 ; i ++)
	{
		sll.insert(i,i);
	}
	std::cout << "is sll empty?" << sll.is_empty() << std::endl;
	sll.print_list();
	std::cout << sll.find_previous(5)->data << std::endl;
	std::cout << sll.find_next(5)->data << std::endl;
	std::cout << sll.find_kth(5)->data << std::endl;
	std::cout << sll.find_kth(1)->data << std::endl;
	std::cout << sll.find_kth(0)->data << std::endl;
	std::cout << "is 8 the last?" << sll.is_last(8) << std::endl;
	std::cout << "is 9 the last?" << sll.is_last(9) << std::endl;
	sll.delete_key(6);
	std::cout << "sll.length:" << sll.length << std::endl;
	sll.print_list();
	sll.delete_key(1);
	std::cout << "sll.length:" << sll.length << std::endl;
	for( i = 0; i < 10; i++)
	{
		std::cout << sll.delete_kth(1) << " has been deleted "; 
		std::cout << "sll.length:" << sll.length << "  ";
		sll.print_list();
	}
	return 0;

}



