#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct symbol{
	char name[20];
	char type[20];
}symbol;

typedef struct hashVal{
	symbol *s;
	struct hashVal* next;
}hashVal;

typedef struct hashValList{
	hashVal* headSym;
	int noofSym;
}hashValList;

typedef struct hashTable{
	int entries;
	int size;
	float loadFactor;
	int freeSlots;
	int insertionTime;
	int queryingTime;
	hashValList* head;
}hashTable;

symbol* readSymbols(FILE *fp,int N);

symbol* readQueries(FILE *fp,int N);

hashTable* createEmptyHashTable(int size);

hashTable* createHashTable(symbol *s,int m,int size,float minLoad,float maxLoad,int resizeFactor);

void lookupQueries(hashTable* H,symbol* s,int m);

hashTable* insert(hashTable* H, symbol *s);

int hashingFunction(symbol *s);
