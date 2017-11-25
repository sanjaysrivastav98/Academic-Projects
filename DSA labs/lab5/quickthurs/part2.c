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
	int rt=lo+1;
	while(rt<=hi){
		while(lf<=hi&&ls[lf]<=piv1){
			if(lf==rt){
				lf++;
				rt++;
			}
			else{
				lf++;			
			}
		}
		while(rt<=hi&&ls[rt]>piv1){
			rt++;
		}
		if(rt<=hi&&ls[rt]<=piv1){
			j=ls[lf];
			ls[lf]=ls[rt];
			ls[rt]=j;
			lf++;
			rt++;
			
		}
		else
			rt++;
	}
	n= lf-1;
	j=ls[lo];
	ls[lo]=ls[n];
	ls[n]=j;
	return n;
	
	
}
