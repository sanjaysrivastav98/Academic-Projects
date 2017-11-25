#include<stdio.h>
#include "radix.h"

int main(){
	FILE *fp=stdin;
	int i,j=0,n,w,d;
	char **s;
	char** f;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1:
				break;
			case 1:
				fscanf(fp,"%d",&n);
				fscanf(fp,"%d",&w);
				s=readStrings(fp,n,w);
				break;
			case 2:
				fscanf(fp,"%d",&d);
				f=keyIndex(s,0,n-1,d,w);
				for(i=0;i<n;i++){
					printf("%c\n",f[i][d]);
				}
				break;
			case 3:
				f=lsdRadixSort(s,0,n-1,w);
				for(i=0;i<n;i++){
					printf("%s\n",f[i]);
				}
				break;
		}
	}
	fclose(fp);
	return 0;
}