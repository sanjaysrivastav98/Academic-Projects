#include "linkedlist.h"
#include<stdlib.h>
void insertInFront(struct linkedlist * head,int ele){
	
	struct node *link=(struct node*)malloc(sizeof(struct node));
	link->element=ele;
	link->next=head->first;
	head->first=link;
	head->count ++;
	traverse(head);
}

void insertAtEnd(struct linkedlist * head,int ele){
	if (head->count==0){
		struct node *link=(struct node*)malloc(sizeof(struct node));
		link->element=ele;
		link->next = NULL;
		head->first=link;
		head->count++;
		traverse(head);

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

	traverse(head);
	}
}


void deleteFromFront(struct linkedlist * head){
	if(head->count==0){
		printf("-2\n");
	}
	else if(head->count ==1){
		printf("\n%d\n",head->first->element);
		head->first=NULL;
		head->count--;
	}
	else{
	struct node * temp = head->first;
	
	head->first=temp->next;
	printf("\n%d\n",temp->element);	

	head->count --;
	}
}

void deleteAtEnd(struct linkedlist * head){
	if(head->count==0){
		printf("-2\n");
		
	}
	else if(head->count ==1){
		printf("\n%d\n",head->first->element);
		head->first=NULL;
		head->count--;
	}
	else{
	struct node * temp = head->first;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}

	printf("\n%d\n",temp->next->element);	
	temp->next=NULL;

	head->count --;
	}
}

void traverse(struct linkedlist * head){	
	struct node * temp = head->first;
	printf("\n");
	while(temp != NULL){
		printf("%d	",temp->element);
		temp=temp->next;
		
	}
	printf("\n");

}

		
int search(struct linkedlist * head, int ele){
	struct node * head1=head->first;
	int count =1;	
	while(head1!=NULL)
        {
        if(head1->element == ele)
            return count;
        head1=head1->next;
	count++;
	}
}

void ht(struct linkedlist* head){
	struct node* hare=head->first;
	struct node* tort=head->first;
	int count=0,flag=0,flag1=0;
	while(hare!=NULL || hare->next!=NULL){
		hare=hare->next->next;
		tort=tort->next;
		if(flag1==1){
			break;
		}
		if (flag==1){
			count++;		
		}
		if (hare=tort){
			flag=1;	
			if(count>0){
				flag1=1;
			}
		}
	}
	printf("%d\n",count);
}
