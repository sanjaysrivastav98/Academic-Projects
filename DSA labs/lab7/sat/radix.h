#include<stdio.h>
#include<stdlib.h>

typedef struct rad{
	char a;
	int freq;
}rad;

char **readStrings(FILE *fp,int n,int w);

char** keyIndex(char** A,int l,int h,int d,int w);

char** lsdRadixSort(char **A,int l,int h,int w);


