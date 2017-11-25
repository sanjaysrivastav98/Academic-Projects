#include <stdio.h>
#include <stdlib.h>

typedef struct directory
{
	char s[500];
	struct directory* child;
	struct directory* next;
}directory;

directory* readData(FILE* fp,int N); 

directory* addreadData(directory* d,FILE* fp,int N); 


void LCA(directory* d,char* s1,char* s2);