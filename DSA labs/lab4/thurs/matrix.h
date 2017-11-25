#include<stdio.h>
#include<stdlib.h>

struct node{
	int ele;
	struct node* next;
}node;

struct ll{
	int count;
	struct node* head;
}ll;

struct myPtr{
	void *p;
	int m;
}myPtr;

int curHeapSize;
int maxHeapSize;

myPtr* myMalloc(unsigned int size);
void myFree(myPtr* ptr);

struct ll* readMatrix(FILE *fp);

int rcMul(FILE *fp,struct ll* m,int size);





