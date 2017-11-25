#include<stdio.h>
#include<stdlib.h>

struct student{
	char name[20];
	double marks1;
	double marks2;
}student;

void qs(struct student* ls,int lo,int hi);

struct student* readData(FILE *fp,int m);

void partialQuickSort(struct student *ls,int lo,int hi,int t);

void print(struct student * ls,int m);

int part(struct student *ls,int lo,int hi,int p);

void quickIn(struct student *ls,int lo,int hi,int t);

int pivot(struct student* ls,int lo,int hi);

