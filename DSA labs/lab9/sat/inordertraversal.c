#include "inordertraversal.h"

int* readData(FILE* fp,int N){
	int* arr=(int*)malloc(N*sizeof(int));
	int i;
	for(i=0;i<N;i++){
		fscanf(fp,"%d",&arr[i]);
	}
	return arr;
}

bst* construct(int* arr,int N){
	bst* bst1=(bst*)malloc(sizeof(bst));
	int i=1;
	bst1->key=arr[0];
	bst1->left=NULL;
	bst1->right=NULL;
	for(i=1;i<N;i++){
		add(arr[i],bst1);
	}
	return bst1;
}

void add1(bst* k,bst* BST_Ptr){
	if(BST_Ptr->key>=k->key){
		if(BST_Ptr->left!=NULL)
			add1(k,BST_Ptr->left);
		else{
			BST_Ptr->left=k;
		}
	}
	else{
		if(BST_Ptr->right!=NULL)
			add1(k,BST_Ptr->right);
		else
			BST_Ptr->right=k;
	}

}

void add(int k,bst* BST_Ptr){
	bst* new=(bst*)malloc(sizeof(bst));
	new->left=NULL;
	new->right=NULL;
	new->key=k;
	add1(new,BST_Ptr);
}


Stack* pop(Stack* S){
	Stack* temp=S->head;
	Stack* temp2;
	S->head=S->head->next;
	return S;
}
Stack* push(bst* t,Stack* S){
	Stack* temp;
	temp=S->head;
	Stack* new=(Stack*)malloc(sizeof(Stack));
	new->tree=t;
	new->next=temp;
	S->head=new;
	return S;
}
bst* top(Stack1* S){
	return S->head->tree;
}
int isEmpty(Stack1* S){
	if(S->head==NULL)
		return 1;
	else
		return 0;
}
void inOrderTravRec(bst* BST_Ptr){
	if(BST_Ptr==NULL)
		return;
	else
	{
		inOrderTravRec(BST_Ptr->left);
		printf("%d ",BST_Ptr->key );
		inOrderTravRec(BST_Ptr->right);
	}
}
void postOrderTrav2(bst* BST_Ptr){
	bst* temp=BST_Ptr,*temp2 ;
	Stack1* S=(Stack1*)malloc(sizeof(Stack1));
	S=push(temp,S);
	while(!isEmpty(S)){
		temp=top(S);S=pop(S);
		while(temp!=NULL){
			if(temp->right!=NULL)
				S=push(temp->right,S);
			printf("%d ",temp->key );
			temp=temp->left;
		}
	}
}



void postOrderTrav(bst* BST_Ptr){
	bst* temp=BST_Ptr,*temp2;
	Stack1* S=(Stack1*)malloc(sizeof(Stack1));
	S=push(temp,S);
	int t=1;
	while(!isEmpty(S)){
		temp=top(S);S=pop(S);
		if(t!=1){
			temp2=temp;
			temp=temp->right;
		}
		while(temp->left!=NULL){
			if(temp->right!=NULL)
				S=push(temp,S);
			temp=temp->left;
		}
		printf("%d ",temp->key );
		if(t!=1){
			printf("%d ",temp2->key);
		}
		t=0;
		
	}
}


void inOrderTravIter(bst* BST_Ptr){
	bst* temp=BST_Ptr,*temp2;
	Stack1* S=(Stack1*)malloc(sizeof(Stack1));
	S=push(temp,S);
	int t=1;
	while(!isEmpty(S)){
		temp=top(S);S=pop(S);
		if(t!=1){
			printf("%d ",temp->key );
			temp=temp->right;
		}
		t=0;
		if(temp==NULL){
			continue;
		}
		while(temp->left!=NULL){
			S=push(temp,S);
			temp=temp->left;
		}
		S=push(temp,S);
	}
}

int findkthSmallest(bst* BST_Ptr,int k){
	int p=1,t=1;
	bst* temp=BST_Ptr,*temp2;
	Stack1* S=(Stack1*)malloc(sizeof(Stack1));
	S=push(temp,S);
	while(!isEmpty(S)){
		temp=top(S);S=pop(S);
		if(t!=1){
			//printf("%d ",temp->key );
			if(p==k){
				return temp->key;
			}
			else{
				p++;
			}
			temp=temp->right;
		}
		t=0;
		if(temp==NULL){
			continue;
		}
		while(temp->left!=NULL){
			
			S=push(temp,S);
			temp=temp->left;
		}
		
		S=push(temp,S);
	}
	return 0;
}

void findBetweenKeys(bst* BST_Ptr,int k1,int k2){
	int p=0,t=1;
	bst* temp=BST_Ptr,*temp2;
	Stack1* S=(Stack1*)malloc(sizeof(Stack1));
	S=push(temp,S);
	while(!isEmpty(S)){
		temp=top(S);S=pop(S);
		if(t!=1){
			if(temp->key>=k1&& temp->key<=k2){
				printf("%d\t",temp->key );
			}
			else if(temp->key>k2)
				return;	
			temp=temp->right;
		}
		t=0;
		if(temp==NULL){
			continue;
		}
		while(temp->left!=NULL){
			S=push(temp,S);
			temp=temp->left;
		}
		//printf("%d ",temp->key );
		S=push(temp,S);
		
		
	}
}
