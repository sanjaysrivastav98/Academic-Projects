#include "lca.h"

int main(){
	FILE *fp=stdin;
	int i,j=0,k,N;
	directory* d;
	char* s1=(char*)malloc(1000*sizeof(char));
	char* s2=(char*)malloc(1000*sizeof(char));
	while(j!=-1){
		fscanf(fp,"%d",&j);
		//printf("%d ",j );
		switch(j){
			case -1:
				break;
			case 1:
				fscanf(fp,"%d",&N);
				//printf("%d\n",N );
				if(d==NULL)
					d=readData(fp,N);
				else
					d=addreadData(d,fp,N);
				break;
			case 2:
				fscanf(fp,"%s",s1);
				//printf("%s ",s1 );
				fscanf(fp,"%s",s2);
				//printf("%s\n",s2 );
				LCA(d,s1,s2);
				break;
		}
	}
	fclose(fp);
	return 0;
}