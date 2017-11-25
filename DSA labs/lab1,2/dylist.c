#include<stdio.h>
#include<stdlib.h>

#include "dylist.h"

void traverse(struct linkedlist * head){
	
		struct node * temp = head->first;
		
		while(temp != NULL){
			printf("%d\t",temp->element);
			temp=temp->next;
		}
	printf("-2\n");

	
}
void create(struct linkedlist *head,int ele){
	if (head->count==0){
		struct node *link=(struct node*)malloc(sizeof(struct node));
		link->element=ele;
		link->next = NULL;
		head->first=link;
		head->count++;
		//traverse(head);

	}		
	else{
		struct node *link=(struct node*)malloc(sizeof(struct node));
		link->element=ele;
		struct node *temp = head->first;
		while(temp->next!=NULL){
			temp=temp->next;	
		}
		temp->next=link;
		link->next = NULL;
		head->count ++;

	//traverse(head);
	}
	
}

void destroy(struct linkedlist *head){
	if(head->count==0){
		printf("-3\n");	
	}
	else{
		struct node *temp = head->first;
		int j=0;
		for(j=0;j<head->count;j++){
			if(temp->next!=NULL){
				head->first=temp->next;
				free(temp);
				temp=head->first;			
			}
			else{
				free(temp);
			}
			head->first=NULL;
			head->count=0;					
		}
		traverse(head);
	}
}

void insertCycle(struct linkedlist *head,int ele){
	int j=0;
	struct node *temp= head->first; 
	for(j=1;j<ele;j++){
		temp=temp->next;		
	}
	struct node *temp1=head->first;
	while(temp1->next!=NULL)
	{		
		temp1=temp1->next;
	}
	temp1->next=temp;
}	

void hasCycle(struct linkedlist *head){
	struct node* hare=head->first;
	struct node* tort=head->first;
	int count=0,flag=0,flag1=0;
	while(hare!=NULL && hare->next!=NULL){
		hare=hare->next->next;
		tort=tort->next;
		if(flag1==1){
			break;
		}
		if (flag==1){
			count++;		
		}
		if (hare==tort&&head->count!=1){
			flag=1;	
			if(count>0){
				flag1=1;
			}
		}
	}
	printf("%d\n",flag);
}

void traverseGeneric(struct linkedlist *head){
	struct node *temp = head->first;
		int j=0;
		for(j=0;j<head->count;j++){
			printf("%d\t",temp->element);
			temp=temp->next;			
		}
		printf("-2\n");
		
}

void destroyGeneric(struct linkedlist *head){
	destroy(head);
}

