#include <stdio.h>
#include <stdlib.h>

typedef struct directory
{
	char s[400];
	struct directory* child;
	struct directory* next;
}directory;

directory* readData(FILE* fp,int N); 

void lookup(directory* d,char* s);