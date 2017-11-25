#include <stdio.h>
#include <stdlib.h>

void readData(FILE *fp,unsigned int *a,unsigned int *b);

unsigned int Union(unsigned int *a,unsigned int *b);

unsigned int Intersection(unsigned int *a,unsigned int *b);

unsigned int Difference(unsigned int *a,unsigned int *b);

void print(unsigned int c);