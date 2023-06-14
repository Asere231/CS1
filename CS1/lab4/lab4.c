#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linked list.
int length(node* head)
{
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Converts the linked list to a string.
// If the linked list is head -> |a|->|b|->|c|,
// then the toCString function will return "abc".
char* toCString(node* head)
{
    int len = length(head);
    char* str = (char*)malloc((len + 1) * sizeof(char));
    node* current = head;
    int i = 0;
    while (current != NULL) {
        str[i] = current->letter;
        current = current->next;
        i++;
    }
    str[len] = '\0';  // Add null terminator
    return str;
}

// Inserts a character at the end of the linked list.
// If the linked list is head -> |a|->|b|->|c|,
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|.
void insertChar(node** pHead, char c)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = NULL;

    if (*pHead == NULL) {
        *pHead = newNode;
    } else {
        node* current = *pHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Deletes all nodes in the linked list.
void deleteList(node** pHead)
{
    node* current = *pHead;
    node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *pHead = NULL;  // Set head to NULL to indicate an empty list
}


int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;

    FILE* inFile = fopen("input.txt","r");
    
    if (inFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    if (fscanf(inFile, " %d\n", &numInputs) != 1) {
        printf("Failed to read the number of inputs.\n");
        fclose(inFile);
        return 1;
    }

    printf("Number of Inputs: %d\n", numInputs);

    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        printf("String Length: %d\n", strLen);
        
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is: %s\n", str);
        free(str);
        deleteList(&head);

        printf("List deleted.\n");
    }

    fclose(inFile);

    return 0;
}
