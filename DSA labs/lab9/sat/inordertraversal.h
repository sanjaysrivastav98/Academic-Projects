#include <stdio.h>
#include <stdlib.h>

typedef struct bst
{
	struct bst* left;
	struct bst* right;
	int key;

}bst;

typedef struct Stack{
	bst* tree;
	struct Stack* next;
}Stack;

typedef struct Stack1
{
	Stack* head;
}Stack1;

Stack1* pop(Stack1* S);

Stack1* push(bst* t,Stack1* S);

bst* top(Stack1* S);

int isEmpty(Stack1* S);

int* readData(FILE* fp,int N);

bst* construct(int* arr,int N);

void add(int k,bst* BST_Ptr);

void inOrderTravRec(bst* BST_Ptr);

void inOrderTravIter(bst* BST_Ptr);

int findkthSmallest(bst* BST_Ptr,int k);

void findBetweenKeys(bst* BST_Ptr,int k1,int k2);


void postOrderTrav(bst* BST_Ptr);