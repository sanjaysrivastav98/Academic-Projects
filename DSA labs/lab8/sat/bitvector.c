#include "bitvector.h"

unsigned int CreateBitVector1(int N){
	
	unsigned int s=0;
	return s;
}


unsigned int Set1(unsigned int s,int N,int j){
	unsigned int B=1;
	B=B<<j;
	s=s|B;
	return s;
}

int Get1(unsigned int s,int N,int j){
	unsigned int B=1;
	B=B<<j;
	B=s&B;
	return B>>j;
}