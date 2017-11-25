#include<stdio.h>
#include "pivot.h"



int pivot(double* ls,int lo,int hi){
	int mid=(lo+hi)/2;
	if(ls[lo]>=ls[hi]){
		if(ls[lo]<=ls[mid])
			return lo;
		else{
			if(ls[hi]<=ls[mid])
				return mid;
			else
				return hi;			
		}
	}
	else{
		if(ls[lo]>=ls[mid]){
			return lo;
		}
		else{
			if(ls[hi]<ls[mid])
				return hi;
			else
				return mid;
		}
	}
}


