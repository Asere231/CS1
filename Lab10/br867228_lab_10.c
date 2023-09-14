#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TrieNode
{
    struct TrieNode *children[26]; // One child for each alphabet
    int count; // To keep track of word occurrences
};

struct Trie 
{
    struct TrieNode *root;
};

struct TrieNode *createTrieNode() 
{
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (node) 
    {
        node->count = 0;
        for (int i = 0; i < 26; i++) 
        {
            node->children[i] = NULL;
        }
    }
    return node;
}

struct Trie *createTrie() 
{
    struct Trie *trie = (struct Trie *)malloc(sizeof(struct Trie));
    if (trie) 
    {
        trie->root = createTrieNode();
    }
    return trie;
}

void insert(struct Trie *pTrie, char *word) 
{
    struct TrieNode *current = pTrie->root;
    for (int i = 0; word[i] != '\0'; i++) 
    {
        int index = word[i] - 'a';
        if (!current->children[index]) 
        {
            current->children[index] = createTrieNode();
        }
        current = current->children[index];
    }
    current->count++;
}

int numberOfOccurrences(struct Trie *pTrie, char *word) 
{
    struct TrieNode *current = pTrie->root;
    for (int i = 0; word[i] != '\0'; i++) 
    {
        int index = word[i] - 'a';
        if (!current->children[index]) 
        {
            return 0; // Word not found
        }
        current = current->children[index];
    }
    return current->count;
}

void deallocateTrieNode(struct TrieNode *pTrie) 
{
    if (pTrie) 
    {
        for (int i = 0; i < 26; i++) 
        {
            deallocateTrieNode(pTrie->children[i]);
        }
        free(pTrie);
    }
}

struct Trie *deallocateTrie(struct Trie *pTrie) 
{
    if (pTrie) 
    {
        deallocateTrieNode(pTrie->root);
        free(pTrie);
    }
    return NULL;
}


// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords)
{
	FILE *fp = fopen(filename, "r");
	if(!fp) 
	{
		printf("Could not open file %s", filename);
		return 0;
	}

	int numWords = 0;
	char word[64];

	// Read each word from file and store in array
	while(fscanf(fp, "%s", word) != EOF) 
	{
		pInWords[numWords] = (char*)malloc(strlen(word) + 1);
		strcpy(pInWords[numWords], word);
		numWords++; 
	}

	fclose(fp);

	return numWords;

}

int main(void)
{
	char *inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
	}
	
	struct Trie *pTrie = createTrie();
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurrences(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}
