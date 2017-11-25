#include<stdio.h>

#include "quick.h"

int pivot(struct student* ls,int lo,int hi){
	return hi;
}

void insertSort(struct student *ls,int m){
	int i=0,j=0,temp;
	struct student a;
	for(i=0;i<m;i++){
		temp=i;
		for(j=i+1;j<m;j++){
			if(ls[temp].marks>ls[j].marks){
				temp=j;
			}
		}
		a=ls[temp];
		ls[temp]=ls[i];
		ls[i]=a;
		
	}
}

void print(struct student * ls,int m){
	int i=0;
	for(i=0;i<m;i++){
		printf("%s\t",ls[i].name);
		printf("%u\n",ls[i].marks);
	}
}


int part(struct student *ls,int lo,int hi,int p){
	struct student i;
	struct student j;
	i=ls[p];
	ls[p]=ls[lo];
	ls[lo]=i;
	double piv1 ;
	piv1=i.marks;
	int lf,n;
	lf=lo+1;
	int rt=hi;

	while(lf<rt){
		for(;lf<=hi&&ls[lf].marks<=piv1;lf++);
		for(;rt>=lo+1&&ls[rt].marks>piv1;rt--);
		if(lf<rt){
			j=ls[lf];
			ls[lf]=ls[rt];
			ls[rt]=j;
			lf++;
			rt--;	
		}
	}
	if(lf==rt){
		//printf("fxdfzzsd\n");
		n=lf;	
	}
	else{
		//printf("gfsfs\n");
		n=lf-1;	
	}
	j=ls[lo];
	ls[lo]=ls[n];
	ls[n]=j;
	return n;
}

void qs(struct student *ls,int lo,int hi){
	int p;
	if (lo<hi) {
		 p=pivot(ls,lo,hi);
		 p=part(ls,lo,hi,p);
		 qs(ls,lo,p-1);
		 qs(ls,p+1,hi); 
	} 	
}

void qs2(struct student *ls,int lo,int hi){
	int p;
	if (lo<hi) {
		 p=pivot(ls,lo,hi);
		 p=part(ls,lo,hi,p);
		 if(p-lo<hi-p){
		 	qs(ls,lo,p-1);
		 	qs(ls,p+1,hi);
		}
		else{
		 	qs(ls,p+1,hi);
		 	qs(ls,lo,p-1);			
		} 
	} 
	
}

void qs3(struct student *ls,int lo,int hi){
	int p,i;
	while(lo<hi){
		p=pivot(ls,lo,hi);
		p=part(ls,lo,hi,p);
		qs(ls,lo,p-1);
		lo=p+1;
	}

}

void qs4(student *s,int lo,int hi,stack *head){
	int p,flag=0;
	node *temp=(node*)malloc(sizeof(node));
	while(isempty(head)==1||flag==0){	
		if(isempty(head)==1){
			temp=top(head);
			lo=temp->lo;
			hi=temp->hi;
			head=pop(head);flag=1;
		}
		while(lo<hi){
			p=pivot(s,lo,hi);
			p=part(s,lo,hi,p);
			if(hi-p>=p-lo){
				head=push(head,lo,p-1);
				lo=p+1;
			}
			else{
				head=push(head,p+1,hi);
				hi=p-1;
			}	
		}
		
	};
	return;
}

void quickIn(struct student *ls,int lo,int hi,int t){
	int p;
	if(lo<hi){
		if(hi-lo+1<=t){
			insertSort(ls+lo,hi-lo+1);
		}
		else{
			p=pivot(ls,lo,hi);
			p=part(ls,lo,hi,p);
			quickIn(ls,lo,p-1,t);
			quickIn(ls,p+1,hi,t);
		}	
	}
		

}

struct student* readData(FILE *fp,int m){
	struct student* s =(struct student*)malloc(m*sizeof(struct student));
	int i=0;
	for(i=0;i<m;i++){
		fscanf(fp,"%s",s[i].name);
		fscanf(fp,"%u",&(s[i].marks));
	}
	return s;
}

void partialQuickSort(struct student *ls,int lo,int hi,int t){
	int p;
	if(lo<hi){
		if(hi-lo+1<=t){return;}
		p=pivot(ls,lo,hi);
		p=part(ls,lo,hi,p);
		partialQuickSort(ls,lo,p-1,t);
		partialQuickSort(ls,p+1,hi,t);
	}
}

node* top(stack *head){
	return head->first;
}
stack* pop(stack *head){
	head->size--;
	head->first=head->first->next;
	return head;
}
stack* push(stack  *head,int lo,int hi){
	node *new=(node*)malloc(sizeof(node));
	if(head->size==0){
		head->first=new;
		new->lo=lo;
		new->hi=hi;
		head->size++;
		new->next=NULL;
	}
	else{
		new->next=head->first;
		head->first=new;
		new->lo=lo;
		new->hi=hi;
		head->size++;
	}
	return head;
}
int isempty(stack *head){
	if(head->size==0){
		return 0;
	}
	else{
		return 1;
	}
}
