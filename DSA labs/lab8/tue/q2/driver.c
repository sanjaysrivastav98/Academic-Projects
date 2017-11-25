#include "set.h"

int main(){
	FILE *fp=stdin;
	int j=0,M;
	unsigned int *a,*b,*c;
	while(j!=-1)
	{
		fscanf(fp,"%d",&j);
		switch(j){
			case -1:
				//printf("-1\n");
				break;
			case 0 :
				fscanf(fp,"%d",&M);
				//printf("0 %d ",M );
				a=(unsigned int*)malloc(M*sizeof(unsigned int));
				b=(unsigned int*)malloc(M*sizeof(unsigned int));
				readData(fp,a,b,M);
				break;
			case 1 :
				//printf("1\n");
				c=Union(a,b,M);
				print(c,M);
				break;
			case 2 :
				c=Intersection(a,b,M);
				print(c,M);
				break;
			case 3 :
				c=Difference(a,b,M);
				print(c,M);
				break;
		}
	}
	fclose(fp);
	return 0;
}