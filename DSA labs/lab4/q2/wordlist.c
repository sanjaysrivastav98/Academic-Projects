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

int compare(struct CharList *t1,struct CharList* t2){
	while(t1!=NULL&&t2!=NULL){
		if(t1->c>t2->c){
			return 0;
		}
		else if(t1->c<t2->c){
			return 1;
		}
		else{
			t1=t1->nextChar;
			t2=t2->nextChar;
		}
	}
	if(t1==NULL){
		return 1;
	}
	else{
		return 0;
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

void sortCharList(struct Linkedlist * head,int k){
	int i=1;
	struct WordList * temp = head->first;
	for(i=1;i<k;i++){
		temp=temp->nextWord;		

	}
	struct CharList *temp1= temp->headChar;
	struct CharList *temp2= temp->headChar;	
	char min;
	int minInd;
	i=0;
	int j=0,l=0;
	while(temp1!=NULL){
		min=temp1->c;
		minInd=j;
		i=j;
		temp2=temp1->nextChar;
		while(temp2!=NULL){
			i++;
			if(min>temp2->c){
				min=temp2->c;
				minInd=i;
			}
			temp2=temp2->nextChar;
		}
		temp2=temp1;
		for(l=j;l<minInd;l++){
			temp2=temp2->nextChar;
		}
		j++;
		temp2->c=temp1->c;
		temp1->c=min;
		temp1=temp1->nextChar;		
	}
	printCharList(head,k);
}
void sortAllCharLists(struct Linkedlist* head){
	struct WordList * temp = head->first;
	int i=1;
	while(temp!=NULL){
		sortCharList(head,i);
		temp=temp->nextWord;
		i++;	
	}
	//printWordList(head);
}
	
void sortWordList(struct Linkedlist* head){
	struct WordList * temp1 = head->first;
	struct WordList *temp2=head->first;
	struct CharList* min=temp1->headChar;
	struct CharList *temp=temp1->headChar;
	int minInd;
	int j=0,l=0,i=0;;
	while(temp1!=NULL){
		temp2=temp1->nextWord;
		minInd=j;
		i=j;
		min=temp1->headChar;
		while(temp2!=NULL){
			i++;
			temp=temp2->headChar;
			if(compare(min,temp)==0){
				min=temp;
				minInd=i;
			}
			temp2=temp2->nextWord;
		}
		temp2=temp1;
		for(l=j;l<minInd;l++){
			temp2=temp2->nextWord;
		}
		j++;
		temp2->headChar=temp1->headChar;
		temp1->headChar=min;
		temp1=temp1->nextWord;
	}
	printWordList(head);
}



