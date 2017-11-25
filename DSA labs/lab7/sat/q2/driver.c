#include<stdio.h>
#include "radix.h"

int main(){
	FILE *fp=stdin;
	int i,j=0,n,w,d,k;
	char **s,**A;
	char** f;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1:
				break;
			case 1:
				fscanf(fp,"%d",&n);
				fscanf(fp,"%d",&w);
				A=readStrings(fp,n,w);
				s=(char**)malloc(n*sizeof(char*));
				for(i=0;i<n;i++){
					s[i]=(char*)malloc(w*sizeof(char));
					for(k=0;k<w;k++){
						s[i][k]=A[i][k];
					}
				}
				break;
			case 2:
				fscanf(fp,"%d",&d);
				keyIndex(s,0,n-1,d,w);
				// for(i=0;i<n;i++){
				// 	printf("%c\n",s[i][d]);
				// }
				break;
			case 3:
				lsdRadixSort(s,0,n-1,w);
				for(i=0;i<n;i++){
					printf("%s\n",s[i]);
				}
				break;
		}
	}
	fclose(fp);
	return 0;
}