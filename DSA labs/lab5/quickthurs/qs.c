#include<stdio.h>
#include<stdlib.h>
#include "pivot.h"
#include "part.h"
#include "qs.h"

double max(double a,double b){
	if(a>b)
		return a;
	else
		return b;
}


void print(struct student * ls,int m){
	int i=0;
	for(i=0;i<m;i++){
		printf("%s\t",ls[i].name);
		printf("%lf\t",ls[i].marks1);
		printf("%lf\n",ls[i].marks2);
	}
}

void qs(double *ls,int lo,int hi){
	int p;
	if (lo<hi) {
		 p=pivot(ls,lo,hi);
		 p=part(ls,lo,hi,p);
		 qs(ls,lo,p-1);
		 qs(ls,p+1,hi); 
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


int main(){
	FILE *fp=stdin;
	struct student* ls;
	int m,i,j=0;
	fscanf(fp,"%d",&m);
	if(m==0){
	fscanf(fp,"%d",&m);
	ls=readData(fp,m);
	double s[m];
	for(i=0;i<m;i++){
		s[i]=max(ls[i].marks1,ls[i].marks2);
	}
	qs(s,0,m-1);
	i=0;
	struct student temp;
	for(i=0;i<m;i++){
		for(j=i;i<m;j++){
			if(s[i]==max(ls[j].marks1,ls[j].marks2)){
				temp=ls[i];
				ls[i]=ls[j];
				ls[j]=temp;
				break;
			}
		}
	}
	print(ls,m);
	}
	
	fclose(fp);
	return 0;

}
