#include"quick.h"

student* readData(FILE *f,int M){
	student *s=(student*)malloc(M*sizeof(student));
	int i,j,k,l;
	for(i=0;i<M;i++){
		fscanf(f,"%s",s[i].name);
		fscanf(f,"%d",&s[i].marks);
	}
	return s;
}
int pivot(student *s,int lo,int hi){
	return hi;
}
void swap(student *s,int s1,int s2){
	student temp;
	temp=s[s1];
	s[s1]=s[s2];
	s[s2]=temp;
	return;
}
int part(student *s,int lo,int hi,int p){
	int i,j,k,l;
	unsigned int psum=s[p].marks;
	swap(s,lo,p);
	int lt=lo+1,rt=hi;
	while(lt<=rt){
		for(;lt<=hi && s[lt].marks<=psum;lt++);
		for(;rt>=lo+1 && s[rt].marks>psum;rt--);
		if(lt<rt){
			swap(s,rt,lt);
			rt--;
			lt++;
		}
	}
	if(lt==rt)
		k=lt;
	else
		k=lt-1;
	swap(s,lo,k);
	return k;
}
void partialQuickSort(student *s, int lo,int hi,int L){
	int p;
	if(lo<hi){
		if(hi-lo+1<L){
			return;
		}
		p=pivot(s,lo,hi);
		p=part(s,lo,hi,p);
		partialQuickSort(s,lo,p-1,L);
		partialQuickSort(s,p+1,hi,L);
	}
	return;
}
void quicksort(student *s,int lo ,int hi){
	int p;
	if(lo<hi){
		p=pivot(s,lo,hi);
		p=part(s,lo,hi,p);
		quicksort(s,lo,p-1);
		quicksort(s,p+1,hi);
	}
	return;
}


void qs2(student *s,int lo,int hi){
	int p;
	if(lo<hi){
		if(hi-lo+1<=1){
			return;
		}
		p=pivot(s,lo,hi);
		p=part(s,lo,hi,p);
		if(hi-p>=p-lo){
			qs2(s,lo,p-1);
			qs2(s,p+1,hi);
		}
		else{
			qs2(s,p+1,hi);
			qs2(s,lo,p-1);
		}	
	}
	return;
}

void qs3 (student *s,int lo, int hi){
	int p;
	while(lo<hi){
		if(hi-lo+1<=1){
			return;
		}
		p=pivot(s,lo,hi);
		p=part(s,lo,hi,p);
		if(hi-p>=p-lo){
			qs3(s,lo,p-1);
			lo=p+1;
		}
		else{
			qs3(s,p+1,hi);
			hi=p-1;
		}	
	}
	return;
}
void qs4(student *s,int lo,int hi,stack *head){
	int p;
	node *temp=(node*)malloc(sizeof(node));
	do{	
		if(isempty(head)==1){
			temp=top(head);
			lo=temp->lo;
			hi=temp->hi;
			head=pop(head);
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
		
	}while(isempty(head)==1);
	return;
}
void print(student *s,int M){
	int i=0;
	if(M==0){
		printf("-1\n");
	}
	for(i=0;i<M;i++){
		printf("%s\t%d\n",s[i].name,s[i].marks);
	}
	return;
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









