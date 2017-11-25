#include"quick.h"

int main(){
//FILE *f =fopen("input.txt","r");
FILE *f=stdin;
int temp,M,L,temp2;
student *s;
stack *head=(stack*)malloc(sizeof(stack));
	while(temp!=-1){
		fscanf(f,"%d",&temp);
		switch(temp){
			case 0:
				fscanf(f,"%d",&M);
				s=readData(f,M);
				break;
			case 1:					
				fscanf(f,"%d",&L);
				partialQuickSort(s,0,M-1,L);
				print(s,M);
				break;
			case 2:					
				fscanf(f,"%d",&temp2);
				switch(temp2){
					case 1:
						quicksort(s,0,M-1);
						break;	
					case 2:
						qs2(s,0,M-1);
						break;
					case 3:
						qs3(s,0,M-1);
						break;
					case 4:
						qs4(s,0,M-1,head);
						break;		 
					default	:				
						break;
				}
				print(s,M);
				break;
			case -1:
				break;
			}
	}
	fclose(f);
	return 0;
}
