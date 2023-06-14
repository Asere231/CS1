/* 
 * Created by: Andrew Valentin
 * Link to WordPress: https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */

/* 
 * PLEASE READ BEFORE YOU CONTINUE!!!
 *
 * This file is meant to be used for practice and to test 
 * your knowledge of stacks.
 *
 * I have included a basic struct for both the node and stack
 * which will be used for the examples and functions in this file as
 * well as an auxiliary function that can be used to print your 
 * stack for testing purposes.
 *
 * A lot of information has been omitted (return types, function code, etc.)
 * and that has been done on purpose in order for you to practice as well as 
 * mess around with the code in order to better understand stacks.
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
 * REMEMBER: KISS
 * 
 * - Keep
 * - It
 * - Simple
 * - Stupid
 * 
 * These functions are a lot easier to write than you may think!
 *
 * As with every problem, make sure you divide and conquer!
 *
 * Don't overthink it and try to break down every problem into smaller, easier to
 * understand problems that all work together and build up to make the big picture
 * a lot clearer to see!
 *
 * If you have any questions, feel free to refer them to the professor or a TA during
 * office hours or an SI leader during their SI sessions.
 */

#include <stdio.h>

typedef struct Node
{
	int value;
	struct Node *next;
} Node;

typedef struct StackLinkedList
{
	Node *head;
	int size; // Number of elements currently in the stack
	int capacity; // Max number of elements the stack can hold
} StackLL;

typedef struct StackArrayList
{
	int *arr;
	int size;
	int capacity;
} StackArr;

void printStackLL(StackLL *s)
{	
	int i;
	Node *temp = s->head;
	
	printf("Capacity: %d\n\n", s->capacity);
	
	for (i = 0; i < s->capacity - s->size; i++)
		printf("*empty*\n");
	
	while (temp != NULL)
	{
		printf("%d%s", temp->value, (temp->next == NULL) ? "\n\n" : "\n");
		temp = temp->next;
	}
}

void printStackArr(StackArr *s)
{
	int i;
	
	printf("Capacity: %d\n\n", s->capacity);
	
	for (i = 0; i < s->capacity - s->size; i++)
		printf("*empty*\n");
	
	i = s->size;
	
	while (i != 0)
		printf("%d\n", s->arr[i - 1]);
	
	printf("\n");
}

// Adds an element to the top of the stack
??? push(???)
{
	// your code goes here
}

// Removes an element from the top of the stack and returns the element
??? pop(???)
{
	// your code goes here
}

// Returns the element at the top of the stack
??? top(???) // Can also be referred to as "peek()"
{
	// your code goes here
}

// Returns 1 if the stack is empty; otherwise, return 0
??? isEmpty(???)
{
	// your code goes here
}

// Returns 1 if the stack is full; otherwise, return 0
??? isFull(???)
{
	// your code goes here
}

int main()
{
	/* 
	 * Questions to consider:
	 *
	 * - What is the runtime of adding to a stack if it's implemented as a linked list?
	 * - What would the runtime be if it was implemented as an array?
	 * - What would the runtime be for deleting from a stack if it was implemented as a linked list?
	 * - What if it was implemented as an array?
	 * - Are you allowed to add/delete an element from a stack from the center? What about from the bottom?
	 * - What is the space complexity of a stack implemented as a linked list? What about an array implementation?
	 */

	// your code goes here
	
	return 0;
}