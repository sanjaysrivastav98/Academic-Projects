#include<stdio.h>

#include "wordlist.h"
void insertChar(struct WordList * head,char c){
	struct CharList * temp = (struct CharList *)malloc(sizeof(struct CharList));
	temp->c=c;
	struct CharList * t = head->headChar;
	if(t==NULL){
		head->headChar=temp;	
	}
	else{
	while(t->nextChar!=NULL){
		t=t->nextChar;
	}
	t->nextChar=temp;
	
	}
	
}

void insertWord(struct Linkedlist* head,struct WordList *c){
	struct WordList * t = head->first;
	if(t==NULL){
		head->first=c;	
	}
	else{
	while(t->nextWord!=NULL){
		t=t->nextWord;
	}
	t->nextWord=c;
	
	}
	
}

void readWords(FILE *fp,struct Linkedlist *head,int n){
	
	int i=0;
	
	for(i=0;i<n;i++){
		char c[20];
		fscanf(fp,"%s",c);
		//printf("%s",c);
		struct WordList* w=(struct WordList*)malloc(sizeof(struct WordList));	
		int j=0;
		for(j=0;c[j]!=NULL;j++){
			insertChar(w,c[j]);
		}
		insertWord(head,w);
				//printf("%d\n",i);
		//printf("%c\n",head->first->headChar->c);				
	}
	
}

void printCharList(struct Linkedlist *head,int n){
	struct WordList * temp = head->first;
	int i=1;
	while(temp->nextWord!=NULL && i<n){
		//printf("%d\n",i);
		temp=temp->nextWord;
		//printf("hello\n");
		i++;
	}
	//printf("a\n");
	struct CharList *temp1= temp->headChar;
	//printf("a");
	while(temp1!=NULL){
		printf("%c\t",temp1->c);
		temp1=temp1->nextChar;
		//printf("%c\t",temp1->c);
	}
	printf("\n");
	
}

void printWordList(struct Linkedlist * head){
	struct WordList * temp = head->first;
	while(temp!=NULL){
		struct CharList *temp1= temp->headChar;
		while(temp1!=NULL){
			printf("%c\t",temp1->c);
			temp1=temp1->nextChar;
		}
		printf("\n");
		temp=temp->nextWord;
	}
}

void sortCharList(struct LinkedList * head,int k){
	int i=1;
	struct WordList * temp = head->first;
	for(i=1;i<k-1;i++){
		temp=temp->next;		

	}
	struct CharList *temp1= temp->headChar;
	struct CharList *temp2= temp->headChar;
	while(temp2!=NULL){
		temp2=temp2->nextChar;
		if(temp1->c>temp2->c){
			temp1->nextChar=temp2->nextChar;
			temp2->nextChar=temp1;		
		}
	}
		struct CharList *temp3= temp->headChar;
	for(i=1;i<k-1;i++){
		temp3=temp3->next;		

	}
	
}
void sortAllCharLists(struct Linkedlist* head){
	struct WordList * temp = head->first;
	int i=1;
	while(temp!=NULL){
		sortCharList(head,i);
		i++;	
	}
	printWordList(head);
}
	
void sortWordList(struct Linkedlist* head){
	
	printWordList(head);
}



