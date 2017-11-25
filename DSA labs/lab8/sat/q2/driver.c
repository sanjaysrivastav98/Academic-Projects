#include <stdio.h>
#include "bitarray.h"

int main(){
	FILE *fp=stdin;
	int i,j=0,k,n;
	int *a;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1:
				break;
			case 0:
				fscanf(fp,"%d",&n);
				a=CreateBitVector(n);
				break;
			case 1:
				fscanf(fp,"%d",&i);
				a=Set(a,n,i);
				break;
			case 2:
				fscanf(fp,"%d",&i);
				k=Get(a,n,i);
				printf("%d\n",k );
				break;
		}

	}
	fclose(fp);
	return 0;
}