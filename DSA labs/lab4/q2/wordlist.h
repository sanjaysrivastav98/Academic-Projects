#include<stdio.h>
#include<stdlib.h>

struct CharList{
	char c;
	struct CharList *nextChar;
};

struct WordList{
	struct CharList *headChar;
	struct WordList *nextWord; 
};


struct Linkedlist {
	struct WordList *first;
};

void readWords(FILE *fp,struct Linkedlist *head,int n);

void printCharList(struct Linkedlist *head,int n);

void printWordList(struct Linkedlist *head);

void sortCharList(struct Linkedlist * head,int k);

void sortAllCharLists(struct Linkedlist* head);

void sortWordList(struct Linkedlist* head);

int compare(struct CharList *t1,struct CharList* t2);
