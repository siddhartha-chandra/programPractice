
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};


void getNthNode(struct node **head_ref, int N)
{
  
  if (N<=0)
    {
      printf("N cannot be less than 1\n");
    }
  
  struct node *temp = *head_ref;
  int count=N;
  while(temp!=NULL && count!=1)
    {
      temp = temp->next;
      count=count-1;
    }

  if(temp==NULL)
    printf ("%dth node does not exist",N);
  else
    printf ("%d node value is %d\n\n",N, temp->data);

}


void printList(struct node *n)
{

	printf("Current List is:\n");

	while(n!=NULL)
	{
		printf("%d -->", n->data);
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

void insertAfter(struct node **head_ref, int nodeNum, int new_data)
{

	if(nodeNum<1)
	{
		printf("Cannot insert before head\n");
		return;
	}

	//struct node *prevNode= (struct node*)malloc(sizeof(struct node));
	//prevNode= *head_ref;

	struct node *prevNode= *head_ref;

	int i;
	for (i = 1; i < nodeNum; ++i)
	{
		prevNode=prevNode->next;
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

void reverseList(struct node **head_ref)
{
	struct node * next = NULL;
	struct node * curr = *head_ref;
	struct node * prev = NULL;

	while (curr!=NULL)
	{
		next = curr->next;
		curr->next= prev;
		prev = curr;
		curr = next;
	}

	*head_ref= prev;
}

void reverseListRecursive(struct node **head_ref, struct node *p)
{	
	
	if (p->next==NULL)
	{
		*head_ref=p;
		return;
	}
	reverseListRecursive(head_ref, p->next);

	struct node * curr = p->next;
	curr->next= p;
	p->next= NULL;

}

void deleteNthNode(struct node **head_ref, int N)
{
	if (N<1)
	{
		cout <<"Node number should be atleast 1";
		return;
	}

	struct node * temp = *head_ref;
	while (N!=1)
	{
	
		if (temp==NULL)
		{
			printf("Number of nodes in list are lesser than the number specified \n");
			return;
		}
		N=N-1;
		temp=temp->next;
	}

	
	if (temp->next==NULL)
	{
		
		temp=NULL;

		if(N>1)
		{
			free(temp);
		}
		return;
	}

	struct node * prev = temp;
	temp=temp->next;
	prev->data=temp->data;
	prev->next = temp->next;
	free(temp);

}

void deleteList(struct node **head_ref)
{
	if (*head_ref==NULL)
	{
		printf("List already empty!\n");
		return;
	}

	struct node *nextNode=*head_ref;
	nextNode=nextNode->next;
	while(nextNode!=NULL)
	{
		free(*head_ref);
		*head_ref=nextNode;
		nextNode=nextNode->next;

	}

	*head_ref=NULL;
}

int main()
{

//menu for linked list operations

int choice;

//declare head node
struct node *head=NULL;

while(1)
{
	printf("\n\nMenu\n\n");
	printf("1. push an element\n");
	printf("2. Append an element at the tail\n");
	printf("3. Insert an element after value\n");
	printf("4. Get Nth node\n");
	printf("5. Print the list\n");
	printf("6. Reverse the list\n");
	printf("7. Recursively Reverse the list\n");
	printf("8. Delete the list\n");
	printf("9. Delete the Nth node\n\n");

	//To implement
	printf("10. Palindrome check\n\n");
	printf("11. Sort List\n\n");
	printf("12. Insert in sorted list\n\n");
	//getting intersection points of 2 lists
	//Print reverse of list
	//remove duplicates from a sorted list
	//remove duplicates from an unsorted list
	//pairwise swap of elements
	//move last element to front
	//intersection of 2 sorted linked lists

	printf("Enter your choice *0 to exit* : ");
	cin>>choice;
	
	int num;
	int nodeNum;

	if(choice==1)
	{
		cout<<"Enter number to push: ";
		cin >> num;
		cout <<endl;
		push(&head, num);
	}
	else if(choice==2)
	{
		cout<<"Enter number to append at tail: ";
		cin >> num;
		cout <<endl;
		append(&head, num);
	}
	else if(choice==3)
	{
		cout<<"Enter node number after which you would like to insert: ";
		cin >> nodeNum;
		cout <<endl;

		cout<<"Enter value to be inserted: ";
		cin >> num;
		cout <<endl;
		insertAfter(&head, nodeNum, num);	
	}
	else if(choice==4)
	{
		cout<<"Enter node number which you would like to get value of: ";
		cin>>nodeNum;
		cout<<endl;
		getNthNode(&head, nodeNum);	
	}
	else if(choice==5)
	{
		printList(head);
	}
	else if(choice==6)
	{
		reverseList(&head);
	}
	else if(choice==7)
	{
		reverseListRecursive(&head,head);
	}
	else if(choice==8)
	{
		deleteList(&head);
	}
	else if(choice==9)
	{
		cout<<"Enter node number which you would like to delete: ";
		cin>>nodeNum;
		cout<<endl;
		deleteNthNode(&head,nodeNum);
	}
	else if(choice==0)
	{
		printf("Exiting!\n");
		exit(0);
	}
	
	else
		exit(1);
	
}


return 0;
	
}
