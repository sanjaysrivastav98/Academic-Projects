#include<stdio.h>
#include "rehash.h"
#include<math.h>
#include<string.h>
int hashingFunction(symbol *s){
	int i,index,sum=0;
	int len=strlen(s->name);
	for(i=0;i<len;i++){
		sum=sum+(int)s->name[i];
	}
	index=(sum %(int) pow(2,15));
	return index;
}

symbol* readSymbols(FILE *fp,int N){
	symbol *s=(symbol*)malloc(N*sizeof (symbol));
	int i=0;
	while(i<N){
		fscanf(fp,"%s",s[i].name);
		fscanf(fp,"%s",s[i].type);
		i++;
	}
	return s;
}

symbol* readQueries(FILE *fp,int N){
	symbol *s=(symbol*)malloc(N*sizeof (symbol));
	int i=0;
	while(i<N){
		fscanf(fp,"%s",s[i].name);
		fscanf(fp,"%s",s[i].type);
		i++;
	}
	return s;
}

hashTable* createEmptyHashTable(int size){
	hashTable* H=(hashTable*)malloc(sizeof(hashTable));
	H->size=size;
	H->entries=0;
	H->loadFactor=H->entries/H->size;
	H->freeSlots=size;
	hashValList *head=(hashValList*)malloc(size*sizeof(hashValList));
	H->head=head;
	return H;
}

int insertSymbol(hashTable* H,int index,symbol *s){
	hashVal *sym=(hashVal*)malloc(sizeof(hashVal));
	hashVal* temp=(hashVal*)malloc(sizeof(hashVal));
	(sym->s)=s;
	sym->next=NULL;
	if (H->head[index].noofSym==0){
		(H->head[index]).headSym=sym;H->head[index].noofSym++;
	}
	else{
	temp=(H->head[index]).headSym;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=sym;
	H->head[index].noofSym++;
	}
	return H->head[index].noofSym-1;
}

hashTable* insert(hashTable* H, symbol *s){
	int t,index;
	H->entries++;
	H->loadFactor=(double)H->entries/(double)H->size;
	index = hashingFunction (s)%H->size;
	if (H->head[index].noofSym==0){
		H->freeSlots--;}
	H->insertionTime+=insertSymbol(H,index,s);
	H->loadFactor = (double)H->entries /(double) H->size;
	return H;
}

hashTable* createHashTable(symbol* sym,int m,int size,float minLoad,float maxLoad,int resizeFactor){
	hashTable* H;
	hashTable* Hnew;
	int newSize;
	int i,j,k=0;
	H = createEmptyHashTable(size);
	for (i=0;i<m;i++){
		H = insert(H, &sym[i]);k++;}
		if (H->loadFactor >maxLoad){
			newSize = H->size * resizeFactor;
			Hnew = createEmptyHashTable(newSize);
			Hnew->insertionTime=H->insertionTime;
			for(j=0;j<k;j++){
				Hnew=insert(Hnew,&sym[j]);
			}
			H = Hnew ;
		}
	
		else if (H->loadFactor < minLoad){
			newSize = (int)(H->size / resizeFactor);
			Hnew = createEmptyHashTable(newSize);
			Hnew->insertionTime=H->insertionTime;
			for(j=0;j<k;j++){
				Hnew=insert(Hnew,&sym[j]);
			}
			H = Hnew;
		
	}
	printf("%d\t%d\t%f\t%d\t%d\n",H->entries,H->size,H->loadFactor,H->freeSlots, H->insertionTime);
	return H;
}

int search(hashTable *h,symbol *q){
	int index;
	int t=0;
	index=hashingFunction(q)%h->size;
	int i=0;
	hashVal *temp=(hashVal*)malloc(sizeof(hashVal));
	temp=h->head[index].headSym;
	if(h->head[index].noofSym==0){
		return 0;
	}
	while(temp!=NULL){

		if(strcmp(temp->s->name,q->name) ==0 && strcmp(temp->s->type,q->type)==0){
			t++;
			h->queryingTime+=t;
			return 1;
		}
		t++;
		temp=temp->next;
	}
	h->queryingTime+=t;
	return 0;
}

void lookupQueries(hashTable *h,symbol *q,int size){
	int i=0;
	int no=0;
	for(i=0;i<size;i++){
		no+=search(h,&q[i]);
	}
	printf("%d\t%d\n",no,h->queryingTime);
	return;
}

