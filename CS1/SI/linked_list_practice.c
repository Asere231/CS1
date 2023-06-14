/* 
 * Created by: Andrew Valentin
 * Link to WordPress: https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */

/* 
 * PLEASE READ BEFORE YOU CONTINUE!!!
 *
 * This file is meant to be used for practice and to test 
 * your knowledge of linked lists.
 *
 * I have included a basic struct for both the node and linked list
 * which will be used for the examples and functions in this file as
 * well as an auxiliary function that can be used to print your 
 * linked lists for testing purposes.
 *
 * A lot of information has been omitted (return types, function code, etc.)
 * and that has been done on purpose in order for you to practice as well as 
 * mess around with the code in order to better understand linked lists.
 *
 * Furthermore, it is meant to prevent you from just copying any code I write
 * which would ultimately lead to you not understanding what you are doing.
 *
 * I am providing the function prototypes to give you a good start, but the rest is
 * up to you.
 *
 * Make sure to read every function name and comment carefully as they are written
 * in a way that makes their purpose clear to understand and to help guide you
 * as you write the code for each function.
 *
 * One last note: use this as an opportunity to practice dynamic memory allocation as well!
 * 
 * I know that there are some parameters that require pointers, but feel free to see
 * how the code works when you are not using pointers or when you are solely using pointers.
 *
 * If you have any questions, feel free to refer them to the professor or a TA during
 * office hours or an SI leader during their SI sessions.
 */

#include <stdio.h>

#define EMPTY 0

// Node struct
typedef struct Node 
{
  int value;
  struct Node *next;
} Node;

// Linked List struct that holds head and tail
typedef struct LL 
{
  Node *head;
  Node *tail;
} LL;

// Prints a linked list
void printLL(Node *head) 
{
  Node *temp = head;

  while (temp != NULL) 
  {
    printf("%d -> ", temp->value);
    temp = temp->next;
  }
  
  printf("NULL\n");
}

// Creates an empty linked list and returns the address
LL* createLL()
{
	LL* l = (LL*)malloc(sizeof(LL));

	return l;
}

// Initializes values inside an empty linked list to NULL
void initLL(LL *ll) 
{
	ll->head = NULL;
	ll->tail = NULL;
}

// Creates an empty node and returns the address
Node* createNode() 
{
	Node* n = (Node*)malloc(sizeof(Node));

	return n;
}

// Creates a node that holds a value and returns the address
Node* createNodeWithValue(int val) 
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->value = val;

	return newNode; 
}

// Return 1 if a node with a specific value exists within the linked list
// Otherwise, return 0
int containsNode(LL* pHead, int data)
{
	if (pHead == NULL)
		return 0;
	
	LL* curr = pHead;

	while (curr != NULL)
	{
		if (curr->value == data)
			return 1;

		curr = curr->next;
	}

	return 0;
}

/*
 * NOTE:
 * 	The following functions are meant to explore the different
 * 	ways one could insert or remove nodes from a linked list.
 *
 * 	There are functions that do the same thing; however, they
 * 	are slightly different due to way they have to be implemented.
 *
 * 	Make sure to read the comments carefully since they all explain
 * 	the purpose of each function.
 *
 * 	You could approach each function with a different solution;
 * 	however, in order to stay consistent, the function descriptions
 * 	are written to guide you toward a specific solution.
 * 
 * 	Feel free to play around with the functions in order to implement
 * 	different solutions, but do keep in mind that the function
 * 	descriptions are written to reflect the consistency that I usually
 * 	aim to achieve whenever I write code (and which is something you
 * 	should keep in mind whenever you write code in order to write cleaner,
 * 	easier to understand code).
 */
 
// Inserts an empty node to the head of a linked list and returns the new head
Node* insertEmptyNodeToHead(Node *head) 
{	
	Node* eNode = createNode();

	if (head == NULL)
	{
		eNode->next = NULL;
		head = vNode;

		return head;
	}

	eNode->next = head;
	head = eNode;

	return head;
}

// Inserts a node with a value to the head of a linked list and returns the new head
Node* insertNodeWithValueToHead(Node *head, int val) 
{	
	Node* vNode = createNodeWithValue(val);

	if (head == NULL)
	{
		vNode->next = NULL;
		head = vNode;

		return head;
	}

	vNode->next = head;
	head = vNode;

	return head;
}

// Inserts an empty node to the head of a linked list
void insertNodeToListHead(LL *list) 
{
	Node* eNode = createNode();

	if (list == NULL)
	{
		eNode->next = NULL;
		list->head = eNode;
		list->tail = eNode;
		return;
	}

	eNode->next = list->head;
	list->head = eNode;
}

// Inserts a node with a value to the head of a linked list
void insertNodeWithValueToListHead(LL *list, int val) 
{	
	Node* vNode = createNodeWithValue(val);

	if (list == NULL)
	{
		vNode->next = NULL;
		list->head = vNode;
		list->tail = vNode;
		return;
	}

	vNode->next = list->head;
	list->head = vNode;
}



// Inserts an empty node to the tail of a linked list and returns the head
Node* insertEmptyNodeToTail(Node *head) 
{
	Node* eNode = createNode();
	eNode->next = NULL;

	if (list == NULL)
	{
		list->head = eNode;
		list->tail = eNode;
		return;
	}

	Node* curr = head;

	while (curr->next != NULL)
		curr = curr->next;

	curr->next = eNode;
	list->tail = eNode;

	return head; 
}

// Inserts a node with a value to the tail of a linked list and returns the head
Node* insertNodeWithValueToTail(Node *head, int val) 
{

	Node* vNode = createNodeWithValue(val);
	vNode->next = NULL;

	if (list == NULL)
	{
		list->head = vNode;
		list->tail = vNode;
		return;
	}

	Node* temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = vNode;
	list->tail = vNode;

	return head;
}

// Inserts an empty node to the tail of a linked list
void insertNodeToListTail(LL *list) 
{

	Node* eNode = createNode();
	eNode->next = NULL;

	if (list == NULL)
	{
		list->head = eNode;
		list->tail = eNode;
		return;
	}

	Node* temp = list->head;

	while (temp->next != NULL)
		temp = temp->next;
	
	temp->next = eNode;
	list->tail = eNode;
}

// Inserts a node with a value to the tail of a linked list
void insertNodeWithValueToListTail(LL *list, int val) 
{
	Node* vNode = createNodeWithValue(val);
	vNode->next = NULL;

	if (list->head == NULL)
	{
		list->head = vNode;
		list->tail = vNode;
	}
	else
	{
		list->tail->next = vNode;
		list->tail = vNode;
	}
}

/*
 * NOTE:
 * 	The following functions are meant to give you practice inserting a node
 *  into the middle of a linked list or removing a node from the middle of
 *  a linked list at some arbitrary index.
 *  
 *  The index can start at 0 or 1 (that is up to you to decide).
 *
 *  Just make sure to stay consistent so you don't cause any errors
 *  or confusion later on!
 */

// Inserts an empty node to a specific index in the linked list and returns the head
Node* insertEmptyNodeToLLHead(Node *head, int index) 
{
	int count = 0;

	Node* eNode = createNode();
	eNode->next = NULL;

	if (head == NULL)
	{
		if (index == 0)
			head = eNode;

		return head;
	}

	if (index == 0)
	{
		eNode->next = head;
		head = eNode;

		return head;
	}

	Node* temp = head;

	while ((count < index) && (temp->next != NULL))
	{
		temp = temp->next;
		count++;	
	}

	eNode->next = temp->next;
	temp->next = eNode;

	return head;
}

// Inserts a node with a value to a specific index in the linked list and returns the head
Node* insertNodeWithValueToLLHead(Node *head, int val, int index) 
{
	int count = 0;

	Node* vNode = createNodeWithValue(val);
	vNode->next = NULL;

	if (head == NULL)
	{
		if (index == 0)
			vNode = head;

		return head;
	}

	if (index == 0)
	{
		vNode->next = head;
		head = vNode;

		return head;
	}

	Node* temp = head;

	while ((count < index) && (temp->next != NULL))
	{
		temp = temp->next;
		count++;
	}

	vNode->next = temp->next;
	temp->next = vNode;

	return head;
}

// Inserts an empty node to a specific index in the linked list
void insertEmptyNodeToLL(LL *list, int index) 
{
	int count = 0;
	Node* eNode = createNode();
	eNode->next = NULL;

	if (list->head == NULL)
	{
		if (index == 0)
			list->head = eNode;
	
		return;
	}

	if (index == 0)
	{
		eNode->next = list->head;
		list->head = eNode;

		return;
	}

	Node* temp = list->head;

	while (count < index && temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}

	eNode->next = temp->next;
	temp->next = eNode;

}

// Inserts a node with a value to a specific index in the linked list
void insertNodeWithValueToLL(LL *list, int val, int index) 
{
	int count = 0;
	Node* vNode = createNodeWithValue(val);
	vNode->next = NULL;

	if (list->head == NULL)
	{
		if (index == 0)
			list->head = vNode;

		return;
	}

	if (index == 0)
	{
		vNode->next = list->head;
		list->head = vNode;

		return;
	}

	Node* temp = list->head;

	while (count < index && temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}

	vNode->next = temp->next;
	temp->next = vNode;

}

// Takes in the head of a linked list, removes a node from the head, and returns the new head
Node* removeNodeFromHead(Node* head)
{
	if (head == NULL)
		return NULL;

	Node* temp = head;
	head = head->next;

	free(temp);

	return head;
}

// Takes in a linked list and removes a node from the head
void removeNodeFromListHead(LL* list)
{
	if (list == NULL)
		return;
	
	if (list->head != NULL)
	{
		Node* temp = list->head;
		list->head = list->head->next;

		free(temp);
	}

}

// Takes in the head of a linked list, removes a node from the tail, and returns the head
??? removeNodeFromTail(???)
{
	// your code goes here
}

// Takes in a linked list and removes a node from the tail
??? removeNodeFromListTail(???)
{
	// your code goes here
}

// Takes in the head of a linked list and a value, removes the first instance of a node
// with that value, and returns the head of the linked list
??? removeNodeWithValueFromLLHead(???)
{
	// your code goes here
}

// Takes in a linked list and a value and removes the first instance of a node
// with that value
??? removeNodeWithValueFromLL(???)
{
	// your code goes here
}

// Takes in the head of a linked list and an index, removes the node
// at that index, and returns the head of the linked list
??? removeNodeInIndexFromLLHead(???)
{
	// your code goes here
}

// Takes in a linked list and an index and removes the node at that index
??? removeNodeInIndexFromLL(???)
{
	// your code goes here
}



int main() 
{
	/* 
	 * Questions to consider:
	 *
	 * - What is the Big-O runtime if you add a node to the head? What if you added it to the tail?
	 * - What changes do you need to make if you were to use a circular linked list?
	 * - Can you add a node to the middle of a linked list if you only had access to the tail?
	 * - What are the benefits and drawbacks to using a doubly linked list?
	 * - What are the benefits and drawbacks to storing a tail pointer?
	 * - What are the differences between arrays and linked lists?
	 * - Why would a linked list be better to use than an array?
	 * - Why would an array be better to use than a linked list?
	 * - What are the differences/similarities between the Big-O runtimes for arrays and linked lists for:
	 *   > Insertion
	 *   > Deletion
	 *   > Search by index
	 *   > Search by value in a sorted list
	 *   > Search by value in an unsorted list
	 * - What considerations do you need to make when writing functions for linked lists and what is the
	 *   error that you need to always look out for and try to avoid as you write these functions?
	 */

	// your code goes here
  
	return 0;
}
