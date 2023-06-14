/* 
 * Created by: Andrew Valentin
 * Link to WordPress: https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */

/* 
 * PLEASE READ BEFORE YOU CONTINUE!!!
 *
 * This file is meant to be used for practice and to test 
 * your knowledge of queues.
 *
 * I have included a basic struct for both the node and queue
 * which will be used for the examples and functions in this file as
 * well as an auxiliary function that can be used to print your 
 * queue for testing purposes.
 *
 * A lot of information has been omitted (return types, function code, etc.)
 * and that has been done on purpose in order for you to practice as well as 
 * mess around with the code in order to better understand queues.
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

typedef struct QueueLinkedList
{
	Node *tail;
	int size; // Number of elements currently in the queue
	int capacity; // Max number of elements the queue can hold
} QueueLL;

typedef struct QueueArrayList
{
	int *arr;
	int front;
	int size;
	int capacity;
} QueueArr;

void printQueueLL(QueueLL *q)
{	
	int i;
	Node *temp = q->tail->next;
	
	printf("Capacity: %d\n\n", q->capacity);
	
	while (temp != q->tail)
	{
		printf("%d%s", temp->value, " <- ");
		temp = temp->next;
	}
	
	printf("%d%c", temp->value, (q->size == q->capacity) ? '\n' : ' ');
	
	for (i = 0; i < q->capacity - q->size; i++)
		printf("<- *empty*%c", (i == q->capacity - q->size - 1) ? '\n' : ' ';
}

void printQueueArr(QueueArr *q)
{
	int i;
	
	printf("Capacity: %d\n\n", q->capacity);

	for (i = q->front; i < (q->front + q->size); i++)
		printf("%s%d", (i == q->front) ? "" : " <- ", q->arr[i % q->capacity]);
	
	for (i = 0; i < q->capacity - q->size; i++)
		printf(" <- *empty*");
}

// Adds an element to the end of the queue
??? enqueue(???)
{
	// your code goes here
}

// Removes an element from the front of the queue and returns the element
??? dequeue(???)
{
	// your code goes here
}

// Returns the element at the front of the queue
??? front(???) // Can also be referred to as "peek()"
{
	// your code goes here
}

// Returns 1 if the queue is empty; otherwise, return 0
??? isEmpty(???)
{
	// your code goes here
}

// Returns 1 if the queue is full; otherwise, return 0
??? isFull(???)
{
	// your code goes here
}

int main()
{
	/* 
	 * Questions to consider:
	 *
	 * - What is the runtime of adding to a queue if it's implemented as a linked list?
	 * - What would the runtime be if it was implemented as an array?
	 * - What would the runtime be for deleting from a queue if it was implemented as a linked list?
	 * - What if it was implemented as an array?
	 * - Are you allowed to add/delete an element from a queue from the center? What about from the back?
	 * - What is the space complexity of a queue implemented as a linked list? What about an array implementation?
	 * - What are the equations that are used to support O(1) insertion and deletion in an array?
	 *   -> Index where insertion takes place: ???
	 *   -> Index where removal takes place: ???
	 *   -> After removal, set front equal to: ???
	 *   -> After removal, set size equal to: ???
	 */

	// your code goes here
	
	return 0;
}
