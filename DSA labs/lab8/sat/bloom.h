#include <stdio.h>
#include <stdlib.h>
#include "bitarray.h"
#include "bitvector.h"



typedef struct choose
{
	int * s1;
	unsigned int s2;

}choose;

typedef struct bloom
{
	choose c;
	int w;
	int l;
	int n;
	int m;
}bloom;

//int glo;

bloom CreateBloomFilter(int X,int N);

bloom Insert(bloom b,int V);

int Find(bloom b,int V);

bloom Clear(bloom b);

bloom Experiment(FILE *fp,bloom b);