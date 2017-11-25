#include<stdio.h>
#include "rehash.h"

int main(){
	FILE *fp=stdin;
	int i=0,j=0,rf,s,n,m;
	float mn,mx;
	symbol *symboList,*queryList;
	hashTable *h;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1:
				break;
			case 0:	
				fscanf(fp,"%d",&n);
				symboList=readSymbols(fp,n);
				break;
			case 1:
				fscanf(fp,"%d",&m);
				queryList=readQueries(fp,m);
				break;
			case 2:
				
				fscanf(fp,"%d",&s);
				fscanf(fp,"%f",&mn);
				fscanf(fp,"%f",&mx);
				fscanf(fp,"%d",&rf);
				h=createHashTable(symboList,n,s,mn,mx,rf);
				break;
			case 3:
				lookupQueries(h,queryList,m);
				break;
	
		}
	
	}

	fclose(fp);
	return 0;
}
