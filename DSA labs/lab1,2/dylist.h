#include<stdio.h>
#include<stdlib.h>

struct node{
	int element;
	struct node *next;
};

struct linkedlist{
	int count;
	struct node *first;
	
};

void create(struct linkedlist *head,int ele);

void traverse(struct linkedlist *head);

void destroy(struct linkedlist *head);

void insertCycle(struct linkedlist *head,int ele);

void hasCycle( struct linkedlist *head);

void traverseGeneric(struct linkedlist *head);

void destroyGeneric(struct linkedlist *head);
