#include<stdio.h>
#include<stdlib.h> 
struct data{
	int* p;
	int size;
}data

struct data heapAllocs[100];
int curHeapSize;
int maxHeapSize;
int t;

int *myAlloc(long int size);
void myFree(void *ptr);
