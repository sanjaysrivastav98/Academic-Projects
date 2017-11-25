#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst
{
	struct bst* left;
	struct bst* right;
	int key;

}bst;

int* readData(FILE *fp,int N);

void add(int k,bst* BST_Ptr);

bst* construct(int* arr,int N);

bst* randomConstruct(int* arr,int N);

int find(int k,bst* BST_Ptr);

int delete(int k,bst* BST_Ptr);

int findHeight(bst* BST_Ptr);

void experiment(bst* bst1,bst* bst2);

int mystrcmp(char* s);

void print(bst* BST_Ptr);
