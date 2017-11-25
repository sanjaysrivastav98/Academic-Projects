#include<stdio.h>
#include "quick.h"
#include<time.h>
int main(int argc,char **argv){
	FILE *fp=stdin;
	//FILE *fp = fopen("1.txt","r");
	struct student* s;
	int j,m,t;

	stack *head=(stack*)malloc(sizeof(stack));

	clock_t start,stop;
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
				fscanf(fp,"%d",&t);
				switch(t){
					case 1:
						start=clock();
						qs(s,0,m-1);
						stop=clock();
						printf("time taken is %lf\n",(double)(stop-start)/CLOCKS_PER_SEC);
						break;
					case 2:
						start=clock();
						int p;
						qs2(s,0,m-1);
						int q;
						stop=clock();
						printf("Stack size occupied is %ld and time taken is %lf\n",(&q-&p),(double)(stop-start)/CLOCKS_PER_SEC);
						break;
					case 3:
						start=clock();
						int r;
						qs4(s,0,m-1,head);
						int s;
						stop=clock();
						printf("Stack size occupied in case 3 is %ld and time taken is %lf\n",(&s-&r),(double)(stop-start)/CLOCKS_PER_SEC);
						break;
					case -1:
						break;
				}					
				print(s,m);
				break;
			case 3:
				fscanf(fp,"%d",&t);
				quickIn(s,0,m-1,t);
				print(s,m);
				break;
			case -1:
				break;

		}

	}
	fclose(fp);
	return 0;
}
