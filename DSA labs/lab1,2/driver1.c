#include<stdio.h>
#include<stdlib.h>

struct node{
	int element;
	struct node *next;
};

struct linkedlist{
	int count;
	struct node *first;
	
};

void insertAtEnd(struct linkedlist * head,int ele){
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


void ht(struct linkedlist* head){
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
		if (hare==tort){
			flag=1;	
			if(count>0){
				flag1=1;
			}
		}
	}
	printf("%d\n",count);
}


int main(int argc, char *argv[]){
	//FILE *fp=fopen(argv[1],"r");
	FILE *fp = stdin;
	struct linkedlist * head = (struct linkedlist *) malloc (sizeof(struct linkedlist));
	int c=0;
	while(!feof(fp)){
		int a,b;
		fscanf(fp,"%d",&a);
		if(a==-1){;break;}
		if(a>c){
			fscanf(fp,"%d",&b);
			insertAtEnd(head,b);
		}
		else{
			
			struct node *temp=head->first;
			struct node *temp1=head->first;
						fscanf(fp,"%d",&b);
			int i=1;
			while(i<c){
				temp1=temp1->next;
				if(i<a){
					temp=temp->next;
				}
				i++;
			}
			temp1->next=temp;				
		}
		c=a;
		
	}
	ht(head);
	return 0;

}
