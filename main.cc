#include <iostream>
#include "LNode.h"
#include "SLNode.h"
#include "DLNode.h"
#include "LinkedList.h"
#include "SLinkedList.h"
#include "DLinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "BLNode.h"
#include "BLinkedList.h"
int main()
{
	int i = 1;
	SLList sll;
	DLList dll;
//	dll.insert(1,10);
//	dll.print_list();

//	sll.insert(1,11);
//	sll.print_list();
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

	std::cout << "is dll empty?" << dll.is_empty() << std::endl;
	for(i = 1; i < 10 ; i ++)
	{
		dll.insert(i,i);
	}
	std::cout << "is dll empty?" << dll.is_empty() << std::endl;
	dll.print_list();
	std::cout << dll.find_previous(5)->data << std::endl;
	std::cout << dll.find_next(5)->data << std::endl;
	std::cout << dll.find_kth(5)->data << std::endl;
	std::cout << dll.find_kth(1)->data << std::endl;
	std::cout << dll.find_kth(0)->data << std::endl;
	std::cout << "is 8 the last?" << dll.is_last(8) << std::endl;
	std::cout << "is 9 the last?" << dll.is_last(9) << std::endl;
	dll.delete_key(6);
	std::cout << "dll.length:" << dll.length << std::endl;
	dll.print_list();
	dll.delete_key(1);
	std::cout << "dll.length:" << dll.length << std::endl;
	for( i = 0; i < 10; i++)
	{
		std::cout << dll.delete_kth(1) << " has been deleted "; 
		std::cout << "dll.length:" << dll.length << "  ";
		dll.print_list();
	}

	Queue myqueue;
	for( i = 0; i < 10; i++)
	{
		std::cout << "insert " << i << " to the queue" << std::endl;
		myqueue.EnQueue(i);
		myqueue.print_list();
	}
	for( i = 0; i < 10; i++)
	{
		std::cout << "delete" << myqueue.DeQueue() << " from the queue" << std::endl;
		myqueue.print_list();
	}
	Stack mystack;
	for( i = 0; i < 10; i++)
	{
		std::cout << "push" << i << " to the stack" << std::endl;
		mystack.push(i);
		mystack.print_list();
	}
	for( i = 0; i < 10; i++)
	{
		std::cout << "pop" << mystack.pop() << " from the stack" << std::endl;
		mystack.print_list();
	}

	BLList mybllist;
	for( int i = 0; i < 40; i += 2)
	{
		mybllist.insert(i);
	}
	for( int i = 1; i < 20; i += 2)
	{
		mybllist.insert(i);
	}

	mybllist.print_list();

	return 0;

}



