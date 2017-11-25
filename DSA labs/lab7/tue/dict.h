#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int  MAX_CNT ;

typedef struct hashTable{
	int s;
	int n;
	char **data;
	int a;
	int b;
}hashTable;

int hash(char *s,int c,int t);

hashTable* createHashTable(int t,int a,int b);

int insert1(hashTable* h,char *s);

void printHashTable(hashTable* h);

int find(hashTable* h,char *s);


