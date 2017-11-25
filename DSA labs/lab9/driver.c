#include "bst.h"

int main(){
	FILE* fp=stdin;
	int i,j=0,k,l,m,N,z,x=0,y=0;
	int* arr,*arr2;
	char *s=(char*)malloc(6*sizeof(char));
	bst* bst1=NULL;
	bst* bst2=NULL;
	while(!feof(fp)){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1:
				break;
			case 0:
				fscanf(fp,"%d",&N);
				arr=readData(fp,N);
				//printf("dvfv\n");
				break;

			case 1:
				fscanf(fp,"%d",&k);

				fscanf(fp,"%s",s);
				if(s[3]=='2'){
					//printf("asfsaf\n");
					add(k,bst2);
				}
				if(s[3]=='1'){
					add(k,bst1);
				}
				break;
			case 2:
				bst1=construct(arr,N);
				break;
			case 3:
				bst2=randomConstruct(arr,N);
				break;
			case 4:
				fscanf(fp,"%d",&k);
				fscanf(fp,"%s",s);
				if(s[3]=='1')
					l=find(k,bst1);
				if(s[3]=='2')
					l=find(k,bst2);
				printf("%d\n",l );
				break;
			case 5:
				fscanf(fp,"%d",&k);
				fscanf(fp," %s",s);
				if(s[3]=='2')
					l=delete(k,bst2);
				if(s[3]=='1')
					l=delete(k,bst1);
				printf("%d\n",l );
				break;
			case 6:
				fscanf(fp,"%s ",s);
				if(s[3]=='2')
					l=findHeight(bst2);
				if(s[3]=='1')
					l=findHeight(bst1);
				printf("%d\n",l-1 );
				break; 
			case 7:
				experiment(bst1,bst2);
				break;
			default :
				break;

		}
	}
	fclose(fp);
	return 0;
}