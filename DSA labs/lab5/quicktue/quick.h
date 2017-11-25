#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	char name[20];
	unsigned int  marks;
}student;

typedef struct stack{
	int size;
	struct node *first;
}stack;
typedef struct node{
	int lo;
	int hi;
	struct node *next;
}node;

void qs(struct student* ls,int lo,int hi);

void qs2(struct student* ls,int lo,int hi);

void qs3(struct student* ls,int lo,int hi);

struct student* readData(FILE *fp,int m);

void partialQuickSort(struct student *ls,int lo,int hi,int t);

void print(struct student * ls,int m);

int part(struct student *ls,int lo,int hi,int p);

void quickIn(struct student *ls,int lo,int hi,int t);

int pivot(struct student* ls,int lo,int hi);

void qs4(student *s,int lo,int hi,stack *head);

int isempty(stack *head);

stack* push(stack  *head,int lo,int hi);

stack* pop(stack *head);

node* top(stack *head);
