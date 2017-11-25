#include<stdio.h>
#include "part.h"


int part(double *ls,int lo,int hi,int p){
	double i;
	double j;
	i=ls[p];
	ls[p]=ls[lo];
	ls[lo]=i;
	double piv1 ;
	piv1=i;
	int lf,n;
	lf=lo+1;
	int rt=hi;
	while(lf<=rt){
		for(;lf<=hi&&ls[lf]<=piv1;lf++);
		for(;rt>=lo+1&&ls[rt]>piv1;rt--);
		if(lf<rt){
			j=ls[lf];
			ls[lf]=ls[rt];
			ls[rt]=j;
			lf++;
			rt--;	
		}
	}
	if(lf==rt){
		n=lf;	
	}
	else{
		n=lf-1;	
	}
	j=ls[lo];
	ls[lo]=ls[n];
	ls[n]=j;
	return n;
}
