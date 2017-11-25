#include "dnstree.h"

int main(){
	FILE* fp=stdin;
	int i,j=0,k,N;
	char s[500];
	dnsNode* d;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		//printf("%d ",j );
		switch(j){
			case -1:
				break;
			case 1:
				fscanf(fp,"%d",&N);
				//printf("%d\n",N );
				d=readData(fp,N);
				break;
			case 2:
				fscanf(fp,"%s",s);
				//printf("%s\n",s );
				lookup(d,s);
				//printf("asfsd\n");
				printf("\n");
				break;
			default:
				break;
		}
	}
	fclose(fp);
	return 0;
}