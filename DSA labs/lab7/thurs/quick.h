#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	char name[20];
	unsigned int marks;
}student;

typedef struct pivots{
	int p1;
	int p2;
}pivots;

typedef struct cmp{
	int x1;
	int x2;
	int x3;
	int x4;
	int y1;
	int y2;
	int y3;
	int y4;
}cmp;

student* readData(int m,FILE *fp);

void quickInSort(student *s,int lo,int hi,int t,cmp *c );

void quickDualPivotSort(student* s,int lo,int hi,int t,cmp *c );

void compare(cmp *c);

void print(student* s,int m);