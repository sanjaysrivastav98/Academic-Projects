#include <stdio.h>
#include "bitvector.h"

int main(){
	FILE *fp=stdin;
	int i,j=0,k;
	unsigned int a;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1:
				break;
			case 0:
				a=CreateBitVector1(32);
				break;
			case 1:
				fscanf(fp,"%d",&i);
				a=Set1(a,32,i);
				break;
			case 2:
				fscanf(fp,"%d",&i);
				k=Get1(a,32,i);
				printf("%d\n",k );
				break;
		}

	}
	fclose(fp);
	return 0;
}