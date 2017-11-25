#include<stdio.h>
#include "quicksort.h"
#include<time.h>
int main(int argc,char **argv){
	FILE *fp=stdin;
	//FILE *fp = fopen("1.txt","r");
	struct student* s;
	clock_t start,stop;
	int j,m,t;
	while(j!=-1){
		fscanf(fp,"%d",&j);
		switch(j){
			case 0:
				fscanf(fp,"%d",&m);
				s=readData(fp,m);
				break;
			case 1:
				fscanf(fp,"%d",&t);
				partialQuickSort(s,0,m-1,t);
				print(s,m);
				break;
			case 2:
				start=clock();
				qs(s,0,m-1);
				stop=clock();
				print(s,m);
				double d=stop-start;
				printf("Time taken by quick sort is %lf\n",d/CLOCKS_PER_SEC);
				break;
			case 3:
				fscanf(fp,"%d",&t);
				start=clock();
				quickIn(s,0,m-1,t);
				stop=clock();
				print(s,m);
				d=stop-start;
				printf("Time taken by quickIN sort is %lf\n",d/CLOCKS_PER_SEC);
				break;
			case -1:
				break;

		}

	}
	fclose(fp);
	return 0;
}
