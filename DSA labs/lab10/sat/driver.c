#include "directoryt.h"

int main(){
	FILE* fp=stdin;
	int i,j=0,N;
	directory* d;
	char* s=(char*)malloc(500*sizeof(char));
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1:
				break;
			case 1:
				fscanf(fp,"%d",&N);
				//printf("dsfdsg\n");
				d=readData(fp,N);
				//printf("asfa\n");
				break;
			case 2:
				fscanf(fp,"%s",s);
				//printf(" %d   %s\n",j,s );
				lookup(d,s);
				break;
			default:
				break;
		}
	}
	return 0;
}