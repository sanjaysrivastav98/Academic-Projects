#include<stdio.h>

struct node{
	int element;
	struct node *next;
};

struct linkedlist{
	int count;
	struct node *first;
	
};

//void insertInFront(struct linkedlist *head,int ele);	

void insertAtEnd(struct linkedlist *head,int ele);

//void deleteFromFront(struct linkedlist *head);

//void deleteAtEnd(struct linkedlist * head);

//void traverse(struct linkedlist *head);

//int search(struct linkedlist* head, int ele);


void ht(struct linkedlist* head);
