#include<stdio.h>
#include "wordlist.h"

int main(int argc,char **argv){
	FILE *fp =stdin;
	//FILE *fp =fopen("1.txt","r");
	int i=0;
	struct Linkedlist * head= (struct Linkedlist*)malloc(sizeof(struct Linkedlist));
	int r=0,j;
	while(r!=-1){
		fscanf(fp,"%d",&r);
		switch(r){
			case 1:
				fscanf(fp,"%d ",&j);
				//printf("aaaaa\n");				
				readWords(fp,head,j);
				//printf("aaaaa\n");				
				break;
			case 2:

				fscanf(fp,"%d ",&j);
								//printf("aaaaa\n");				
				printCharList(head,j);
				//printf("aaaaa\n");
				break;
			case 3:
				printWordList(head);
				break;
			case 4:
				fscanf(fp,"%d",&j);
				sortCharList(head,j);
				break;
			case 5:
				sortAllCharLists(head);
				break;
			case 6:
				sortWordList(head);break;
			case -1:
				break;
		}
	}
	fclose(fp);
	return 0;
}
