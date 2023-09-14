#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
}Node;

void printList(Node* head)
{
    Node* tmp = head;
    while (tmp != NULL)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

Node* allocateNode(int value)
{
    Node* node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void insert(Node** pHead, int value)
{
    Node* newNode = allocateNode(value);

    if (*pHead == NULL)
    {
        *pHead = newNode;
    }
    else
    {
        Node *temp = *pHead;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

}

void swap(int* a, int* b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Node** pHead, int len)
{
    if (*pHead == NULL)
        return;



    for (int i = 0; i < len - 1; i++)
    {
        // Reset after first time traversing
        Node* slow = *pHead;
        Node* fast = slow->next;
        int swapcount=0;

        for (int j = 0; j < len - 1; j++)
        {
            if (slow->value > fast->value)
            {
                swap( &(slow->value), &(fast->value) );
                swapcount+=1;
            }

            slow = slow->next;
            fast = fast->next;
            
        }
        printf("%d",swapcount);
    }

}

void* freeList(Node** pHead)
{
    Node* tmp = *pHead;
    while (tmp != NULL)
    {
        *pHead = tmp->next;
        free(tmp);
        tmp = *pHead;
    }
    return *pHead;
}

int main()
{
    Node* head = NULL;
    
    int arr_len = 9;
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};

    for (int i = 0; i < arr_len; i++)
    {
        insert(&head, arr[i]);
    }

    // O(n^2)
    bubbleSort(&head, arr_len);
    printf("\n");

    // printList(head);
    freeList(&head);

    return 0;
}

