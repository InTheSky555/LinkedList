all:LNode SLNode DLNode LList SLList DLList Queue Stack BLNode BLList main.cc
	g++ -g -Wall LNode.o SLNode.o DLNode.o LList.o SLList.o DLList.o Queue.o Stack.o BLNode.o BLList.o main.cc -o main
LNode:
	g++ -g -c LNode.cc -o LNode.o
SLNode:
	g++ -g -c SLNode.cc -o SLNode.o
DLNode:
	g++ -g -c DLNode.cc -o DLNode.o
LList:
	g++ -g -c LinkedList.cc -o LList.o
SLList:
	g++ -g -c SLinkedList.cc -o SLList.o
DLList:
	g++ -g -c DLinkedList.cc -o DLList.o
Queue:
	g++ -g -c Queue.cc -o Queue.o
Stack:
	g++ -g -c Stack.cc -o Stack.o
BLNode:
	g++ -g -c BLNode.cc -o BLNode.o
BLList:
	g++ -g -c BLinkedList.cc -o BLList.o
clean:
	rm main *~ *.o
run:
	./main
