
#include "Node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constructor

Node::Node()
{
	data=0;
	next-NULL;
}


void Node::setData(int data)
{
	this->data= data;
}

void Node::setNext(Node *node)
{
	this->next= node;
}

void Node::push(Node **head_ref, int data)
{
	
	//1. allocate new node
	Node *new_node = (Node *)malloc(sizeof(Node));

	//2. assign data
	new_node.setData(data);

	//3.Make next of new node as head
	new_node.setNext(*head_ref);

	//4. Move the head to point to the new node
	*head_ref= new_node;
}





