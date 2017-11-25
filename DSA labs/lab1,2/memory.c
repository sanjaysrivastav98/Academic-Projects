#include<stdio.h>
#include "memory.h"
#include<time.h>


int *myAlloc(long int size){	
	
	
	heapAllocs[t].p=malloc(size);
	heapAllocs[t].size=size;
	curHeapSize+=d.size;
	if(maxHeapSize<=curHeapSize)
	{
		maxHeapSize=curHeapSize;
	}
	return heapAllocs[t++].p;
	
}


void myFree(void *ptr){
	int i=0,flag=0;	
	while(heapAllocs[i]!=NULL){
		if(ptr==heapAllocs[i].p){
			curHeapSize-=heapAllocs[i].size;
			if(maxHeapSize==curHeapSize){
				maxHeapSize-=heapAllocs[i].size;
			}
			free(heapAllocs[i].p);
			flag=1;
		}
		t--;
		i++;
			
	}
	while(i<=t){
		heapAllocs[i]=heapAllocs[i+1];
		i++;	
	}
} 

