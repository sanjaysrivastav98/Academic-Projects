#include "bloom.h"

int main(){
	FILE *fp;
	fp=stdin;
	int j=0,i;
	//int* arr;
	bloom b;
	int X,V,N,K,L,z;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch (j){
			case -1:
				break;
			case 0:
				fscanf(fp,"%d",&X);
				//printf("0 %d\n",X );
				if(X==2)
				{	
					fscanf(fp,"%d",&N);
				}
				else
				{	
					N=32;
				}
				//arr=(int*)malloc(N*sizeof(int));
				b=CreateBloomFilter(X,N);
				break;
			case 1:
				fscanf(fp,"%d",&V);
				//printf("1 %d\n",V );
				b=Insert(b,V);
				break;
			case 2:
				fscanf(fp,"%d",&V);
				//printf("2 %d\n",V );
				z=Find(b,V);
				printf("%d\n",z );
				break;
			case 3:
				b=Clear(b);
				//printf("3\n");
				break;
			case 4:
				b=Experiment(fp,b);
				break;
		}
	}
	fclose(fp);
	return 0;
}