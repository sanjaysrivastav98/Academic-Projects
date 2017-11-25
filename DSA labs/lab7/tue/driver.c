#include "dict.h"

int main(){
	FILE *fp=stdin;
	int i=0,j=0,t,a,b,n,k;
	char  *s=(char *)malloc(100*sizeof(char));
	char tq[10]="a";
	hashTable* h;
	while(j!=-1){
		fscanf(fp,"%d",&j);

		switch (j){
			case 1:
				fscanf(fp,"%d",&t);
				fscanf(fp,"%d",&a);
				fscanf(fp,"%d",&b);
				h=createHashTable(t,a,b);
				printHashTable(h);
			//printf("%d---->>\n",7>>10);
				//printf("aaa\n");
				break;
			case 2:
					fscanf(fp,"%d",&n);
					printf("%d\n",n);
				for(i=0;i<n;i++){
					printHashTable(h);
					fscanf(fp,"%s",s);
					//printf("%s\n",s);
					//printf("%d\n",strcmp(s,tq));
					printHashTable(h);
					//printf("dsvafsbfd\n");
					k=insert1(h,s);
					//printHashTable(h);
					//printf("%d\n",k);
				}
				//printf("aaab\n");

				break;
			case 3:
				printHashTable(h);
				break;
			case 4:
				fscanf(fp,"%s",s);
				k=find(h,s);
				printf("%s\t%d\n",s,k);
				break;
			case -1:
				break;
		}

	}
	fclose(fp);
	return 0;
}
