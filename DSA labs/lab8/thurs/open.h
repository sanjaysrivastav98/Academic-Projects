#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct hashTable{
	int t;
	unsigned int size;
	int entries;
	double loadFactor;
	int findCount;
	int findProbes;
	double findRatio;
	int k;
	char **data;
}hashTable;

typedef struct datapro{
	char* dat;
	int z; 
}

char** readData(FILE* fp,int N);

int hash1(char *s,int t);

int hash2(char *s,int t);

hashTable* createHashTable(char**s,int N,int K,int t);


datapro* find(hashTable* h,int i,char** s);

int insert1(hashTable* h,char *s);

void printHashTable(hashTable* h);

