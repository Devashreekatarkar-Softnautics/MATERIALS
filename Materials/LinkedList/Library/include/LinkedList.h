#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define SUCCESS 1


typedef struct Node{
    int data;
    struct Node* link;
}Node;

void PrintNodes(void *);
Node* initlist(void **, uint32_t);
Node* insertNodeAtTop(void *, int);
Node* listInsertNodeAt(void *, int, int);
int RetriveNodeFromTop(void *);
int RetriveNodeFromP(void*, int);
Node* RemoveTopNode(void*);
Node* RemoveNNode(void*, int);
Node* DelList(void*);
int CheckList(void*);
int SizeOfList(void*);
Node* RemoveNValue(void*, int);
int RetPVal(void*, int);
void SortList(void*);

