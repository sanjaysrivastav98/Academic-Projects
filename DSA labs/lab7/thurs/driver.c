#include "quick.h"

int main(){
	FILE *fp=stdin;
	int j=0,m,t;
	student *s;
	cmp *c =(cmp*)malloc(sizeof(cmp));
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1:
				break;
			case 0:
				fscanf(fp,"%d",&m);
				s=readData(m,fp);
				break;
			case 1:
				fscanf(fp,"%d",&t);
				quickInSort(s,0,m-1,t,c);
				print(s,m);
				break;
			case 2:
				fscanf(fp,"%d",&t);
				quickDualPivotSort(s,0,m-1,t,c);print(s,m);
				break;
			case 3:
				compare(c);
				break;
		}

	}
	fclose(fp);
	return 0;
}