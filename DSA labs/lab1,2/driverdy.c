#include<stdio.h>
#include<stdlib.h>

#include "dylist.h"

int main(int argc,char **argv){
	//	FILE *fp= fopen(argv[1],"r");
	FILE *fp = stdin;
	int flag=0;
	struct linkedlist * head = (struct linkedlist *) malloc (sizeof(struct linkedlist));
	while(!feof(fp)&& flag!=1)
	{	
		int temp,ele;
		fscanf(fp, "%d", &temp);
		switch(temp){
			case -1:
				flag=1;
				break;
			case 0:
				fscanf(fp,"%d ",&ele);
				while(ele!=-1){
					create(head,ele);
					fscanf(fp,"%d ",&ele);				
				}
				traverse(head);
				break;
			case 1:
				traverse(head);
				break;
			case 2:
				destroy(head);
				break;
			case 3:
				fscanf(fp,"%d ",&ele);
				insertCycle(head,ele);
				//traverseGeneric(head);
				break;
			case 4:
				hasCycle(head);
				break;
			case 5:
				traverseGeneric(head);
				break;
			case 6:
				destroyGeneric(head);
				break;	
			
		}
		
	}
	fclose(fp); 
}
