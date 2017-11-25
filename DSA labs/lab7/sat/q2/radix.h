#include<stdio.h>
#include<stdlib.h>

typedef struct rad{
	char a;
	int freq;
}rad;

typedef struct intPair
{
	int i;
	int j;
}intPair;

char **readStrings(FILE *fp,int n,int w);

intPair keyIndex(char** A,int l,int h,int d,int w);

void lsdRadixSort(char **A,int l,int h,int w);


