#include <stdio.h>
#include <stdlib.h>


typedef struct avl
{
	struct avl* left;
	struct avl* right;
	int key;
	int ind;
}avl;

typedef struct xyz
{
	avl* x;
	avl* y;
	avl* z;
	int i;
	int j;
}xyz;

int n;
double t;

int* readData(FILE* fp,int N);

avl* add(avl* tree,int k);

avl* construct(int* arr,int N);

int find(int k,avl* BST_Ptr);

void measure();

void print(avl* BST_Ptr);