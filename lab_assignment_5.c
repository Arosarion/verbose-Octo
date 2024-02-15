#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int node_len = 0;
	node* tmp = head;
	
	while (tmp != NULL)
	{
		tmp = tmp->next;
		node_len++;
	}
	return node_len;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int node_len = length(head); 
	char* cString = malloc(sizeof(char*) * node_len);

	node* tmp = head;

	if (tmp == NULL)
	{
		tmp = head;
	}
	for (int i = 0; i < node_len; i++)
	{
		cString[i] = tmp->letter;
		tmp = tmp->next;
	}
	return cString;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newNode = malloc(sizeof(node));
	newNode->letter = c; 
	newNode->next = NULL;
	if (*pHead == NULL)
	{
		*pHead = newNode;
	}
	else
	{
		node* curr = *pHead;
		while (curr->next != NULL)
		{
			curr = curr -> next;
		}
		curr->next = newNode;
	}	
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* tmp, *t;
	tmp = *pHead;
	while (tmp != NULL)
	{
		t = tmp->next;
		free(tmp);
		tmp = t;
	}
	if (tmp == NULL)
	{
		*pHead = NULL;
	}
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}