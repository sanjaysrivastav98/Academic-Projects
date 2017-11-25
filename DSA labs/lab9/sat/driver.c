#include "inordertraversal.h"

int main(){
	FILE* fp=stdin;
	int i,j=0,N,k,p,k1,k2;
	bst* bst1;
	int* arr;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1:
				break;
			case 0:
				fscanf(fp,"%d",&N);
				//printf("%d\n",N );
				arr=readData(fp,N);
				break;
			case 1:
				fscanf(fp,"%d",&k);
				
				add(k,bst1);
				
				break;
			case 2:
				bst1=construct(arr,N);
				break;
			case 3:
			
				inOrderTravRec(bst1);
				printf("\n");
				break;
			case 4:
				postOrderTrav(bst1);
				printf("\n");
				break;
			case 5:
				fscanf(fp,"%d",&k);
				p=findkthSmallest(bst1,k);
				printf("%d\n",p );
				break;
			case 6:
				fscanf(fp,"%d",&k1);
				fscanf(fp,"%d",&k2);
				findBetweenKeys(bst1,k1,k2);
				printf("\n");
				break;
			default:
				break;
		}
	}
	fclose(fp);
	return 0;
}