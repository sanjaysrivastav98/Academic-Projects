#include "smallset.h"

int main(){
	FILE *fp=stdin;
	int j=0,i;
	unsigned int a=0,b=0,c;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case -1 :
				//printf("-1\n");
				break;
			case 0:
				//printf("0\t");
				readData(fp,&a,&b);

				break;
			case 1:
				c=Union(&a,&b);
				//printf("1\n");
				print(c);
				break;
			case 2:
				c=Intersection(&a,&b);
				print(c);
				//printf("2\n");
				break;
			case 3:
				c=Difference(&a,&b);
				print(c);
				//printf("3\n");
				break;
		}
	}
	fclose(fp);
	return 0;
}