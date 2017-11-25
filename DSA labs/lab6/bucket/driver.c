#include<stdio.h>
#include<stdlib.h>
#include "bucket.h"

int main(){
	FILE *fp=stdin;
	int i,j=0,m,xlo,xhi,ylo,yhi,**arr;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1:
				break;
			case 0:
				fscanf(fp,"%d",&m);
				fscanf(fp,"%d",&xlo);
				fscanf(fp,"%d",&xhi);
				fscanf(fp,"%d",&ylo);
				fscanf(fp,"%d",&yhi);
				arr=(int**)malloc(m*sizeof(int*));
				for(i=0;i<m;i++){
					arr[i]=(int*)malloc(2*sizeof(int));
				}
				readData(fp,arr,m,2,xlo,xhi,ylo,yhi);
				break;
			case 1:
				SortSparseLists(arr,m,2,xlo,xhi,ylo,yhi);
				return 0;
			case 2:
				SortDenseLists(arr,m,2,xlo,xhi,ylo,yhi);
				return 0;
		}
	
	}
	fclose(fp);
	return 0;
}
