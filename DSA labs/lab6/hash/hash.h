#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct student{
	char name[8];
	long int id;
}student;

typedef struct node{
	student* s;
	struct node* next;
}node;

typedef struct linkedlist{
	int count;
	node* first;
}linkedlist;

typedef struct hashTable{
	int elementCount;
	int tableLength;
	float loadFactor;
	int insertionTime;
	int queryingTime;
	linkedlist *head;
}hashTable;

student* readRecords(FILE *fp,int n);

student* readQueries(FILE *fp,int k);

int findInsertionComplexity()
