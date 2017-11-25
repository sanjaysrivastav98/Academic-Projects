#include "avltree.h"

int main(){
	FILE* fp=stdin;
	int i,j=0,k,N;
	avl* tree;
	int* arr;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1: 
				break;
			case 0:
				fscanf(fp,"%d",&N);
				arr=readData(fp,N);
				break;
			case 1:
				//printf("%d\n",N);
				fscanf(fp,"%d",&k);
				//printf("%d\n",k );
				tree=add(tree,k);
				//print(tree);
				break;
			case 2:
				//printf("asf\n");
				tree=construct(arr,N);

				//printf("asfafdf\n");
				break;
			case 3:
				fscanf(fp,"%d",&k);
				i=find(k,tree);
				printf("%d\n",i );
				break;
			case 4:
				//print(tree);
				measure();
				break;

		}
	}
	fclose(fp);
	return 0;
}