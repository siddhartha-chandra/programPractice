// Author - Siddhartha Chandra


#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__ 

/* Node.h

header that contains operations associated with a linked List node.

*/

class Node
{
	
	private:

			int data;
			Node *next;

	public:
			
			void push(Node**, int);
			void setData(int); 
			void setNext(Node*); 
			// append(Node**, int);
			// insertAfter(Node**, int);
			// printList(Node*);
};

#endif