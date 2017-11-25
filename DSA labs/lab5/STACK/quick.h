#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
	int size;
	struct node *first;
}stack;
typedef struct node{
	int lo;
	int hi;
	struct node *next;
}node;
typedef struct student{
	char name[20];
	unsigned int marks;
}student;

student* readData(FILE *f,int M);

void partialQuickSort(student *s, int lo,int hi,int L);

void quicksort(student *s,int lo,int hi);

void print(student *s,int M);

void qs2(student *s,int lo,int hi);

void qs3(student *s,int lo,int hi);

void qs4(student *s,int lo,int hi,stack *head);

int isempty(stack *head);

stack* push(stack  *head,int lo,int hi);

stack* pop(stack *head);

node* top(stack *head);
