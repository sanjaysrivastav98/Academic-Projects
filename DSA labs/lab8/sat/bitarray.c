#include "bitarray.h"

int* CreateBitVector(int N){
	
	int *s=(int*)malloc(N*sizeof(int));
	int i;
	for(i=0;i<N;i++){
		s[i]=0;
	}
	return s;
}


int* Set(int *s,int N,int j){
	s[j-1]=1;
	return s;
}

int Get(int *s,int N,int j){
	return s[j-1];
}