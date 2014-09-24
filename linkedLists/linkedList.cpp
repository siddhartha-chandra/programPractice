
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	node *next;
};


void printList(struct node *n)
{
	while(n!=NULL)
	{
		printf("%d\n", n->data);
		n=n->next;
	}

}

void push(struct node **head_ref, int new_data)
{
	
	//create new node and allocate data
	struct node *new_node= (struct node*)malloc(sizeof(struct node));

	//assign data
	new_node->data=new_data;

	//assign next of new_node to head
	new_node->next= *head_ref;

	//assign new_node as the head
	(*head_ref) = new_node;


}

void append(struct node **head_ref, int new_data)
{


	struct node *last= (struct node*)malloc(sizeof(struct node));
	last= *head_ref;

	//create new node and allocate data
	struct node *new_node= (struct node*)malloc(sizeof(struct node));

	//assign data
	new_node->data=new_data;

	if(*head_ref==NULL)
	{
		*head_ref=new_node;
		return;

	}

	while(last->next!=NULL)
		last=last->next;

	last->next=new_node;
	return;

}

void insertAfter(struct node *prevNode, int new_data)
{

	if (prevNode==NULL)
	{
		printf("Previous node cannot be null\n");
		return;
	}

	//create new node and allocate data
	struct node *new_node= (struct node*)malloc(sizeof(struct node));

	//assign data
	new_node->data=new_data;

	//assign next of new_node as next of prevNode
	new_node->next= prevNode->next;

	//assign next of prev_node to new_node
	prevNode->next= new_node;

}


int main()
{

//declare head node
struct node *head=NULL;

append(&head, 10);

push(&head, 20);
insertAfter(head->next, 50);

printf("Created List is:\n");
printList(head);
getchar();

return 0;
	
}