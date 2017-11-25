#include<stdio.h>

#include<stdlib.h>

#include "linkedlist.h"

int main(int argc, char *argv[]){
	int flag=0;
	//FILE * fileptr = fopen(argv[1], "r");
	FILE *fileptr = stdin;	
	struct linkedlist * head = (struct linkedlist *) malloc (sizeof(struct linkedlist));
	while(!feof(fileptr)&& flag!=1)
	{
		int temp,ele;
		fscanf(fileptr, "%d ", &temp);
		switch(temp){
			case -1:
				flag=1;
				break;
			case 0:
				fscanf(fileptr,"%d",&ele);
				insertInFront(head,ele);
				break;
			case 1:
				fscanf(fileptr,"%d",&ele);
				insertAtEnd(head,ele);
				break;
			case 2:
				deleteFromFront(head);
				break;
			case 3:
				deleteAtEnd(head);
				break;
			case 4:
				traverse(head);
				break;
		}
		
	}
	
	fclose(fileptr);
return 0;
}	
