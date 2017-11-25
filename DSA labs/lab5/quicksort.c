#include<stdio.h>

#include "quicksort.h"

int pivot(struct student* ls,int lo,int hi){
	return hi;
}

void insertSort(struct student *ls,int m){
	int i=0,j=0,temp;
	struct student a;
	for(i=0;i<m;i++){
		temp=i;
		for(j=i+1;j<m;j++){
			if(ls[temp].marks1+ls[temp].marks2>ls[j].marks1+ls[j].marks2){
				temp=j;
			}
		}
		a=ls[temp];
		ls[temp]=ls[i];
		ls[i]=a;
		
	}
}

void print(struct student * ls,int m){
	int i=0;
	for(i=0;i<m;i++){
		printf("%s\t",ls[i].name);
		printf("%lf\t",ls[i].marks1);
		printf("%lf\n",ls[i].marks2);
	}
}


int part(struct student *ls,int lo,int hi,int p){
	struct student i;
	struct student j;
	i=ls[p];
	ls[p]=ls[lo];
	ls[lo]=i;
	double piv1 ;
	piv1=i.marks1+i.marks2;
	int lf,n;
	lf=lo+1;
	int rt=hi;
	while(lf<=rt){
		for(;lf<=hi&&ls[lf].marks1+ls[lf].marks2<=piv1;lf++);
		for(;rt>=lo+1&&ls[rt].marks1+ls[rt].marks2>piv1;rt--);
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

void qs(struct student *ls,int lo,int hi){
	int p;
	if (lo<hi) {
		 p=pivot(ls,lo,hi);
		 p=part(ls,lo,hi,p);
		 qs(ls,lo,p-1);
		 qs(ls,p+1,hi); 
	} 
	
}

void quickIn(struct student *ls,int lo,int hi,int t){
	int p;
	if(lo<hi){
		if(hi-lo+1<=t){
			insertSort(ls+lo,hi-lo+1);
		}
		else{
			p=pivot(ls,lo,hi);
			p=part(ls,lo,hi,p);
			quickIn(ls,lo,p-1,t);
			quickIn(ls,p+1,hi,t);
		}	
	}
		

}

struct student* readData(FILE *fp,int m){
	struct student* s =(struct student*)malloc(m*sizeof(struct student));
	int i=0;
	for(i=0;i<m;i++){
		fscanf(fp,"%s",s[i].name);
		fscanf(fp,"%lf",&(s[i].marks1));
		fscanf(fp,"%lf",&(s[i].marks2));		
	}
	return s;
}

void partialQuickSort(struct student *ls,int lo,int hi,int t){
	int p;
	if(lo<hi){
		if(hi-lo+1<=t){return;}
		p=pivot(ls,lo,hi);
		p=part(ls,lo,hi,p);
		partialQuickSort(ls,lo,p-1,t);
		partialQuickSort(ls,p+1,hi,t);
	}
}


