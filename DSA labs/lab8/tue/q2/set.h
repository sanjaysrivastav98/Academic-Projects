#include <stdio.h>
#include <stdlib.h>

void readData(FILE *fp,unsigned int* a,unsigned int * b,int M);

unsigned int *Union(unsigned int* a,unsigned int * b,int M);

unsigned int* Intersection(unsigned int* a,unsigned int * b,int M);

unsigned int *Difference(unsigned int* a,unsigned int * b,int M);

void print(unsigned int *c,int M);