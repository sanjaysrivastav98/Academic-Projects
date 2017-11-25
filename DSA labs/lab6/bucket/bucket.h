#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int b;
	struct node* next;
}node;

typedef struct linkedlist{
	node *first;
	int size;
}linkedlist;


void readData(FILE *fp,int (*arr)[2],int n,int m,int xlo,int xhi,int ylo,int yhi);

void print(int (*arr)[2],int m,int n);

linkedlist insert(int k,linkedlist head);

void SortSparseLists(int (*arr)[2],int n,int m,int xlo,int xhi,int ylo,int yhi);

void SortDenseLists(int (*arr)[2],int n,int m,int xlo,int xhi,int ylo,int yhi);


