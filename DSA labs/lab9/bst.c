#include "bst.h"

int* readData(FILE *fp,int N){
	int i;
	int* arr=(int*)malloc(N*sizeof(int));
	for (i = 0; i < N; i++)
	{
		fscanf(fp,"%d",&arr[i]);
		//printf("%d\n",arr[i] );
	}
	return arr;
}



void add1(bst* k,bst* BST_Ptr){
	if(BST_Ptr->key>=k->key){
		if(BST_Ptr->left!=NULL)
			add1(k,BST_Ptr->left);
		else
			BST_Ptr->left=k;
	}
	else{
		if(BST_Ptr->right!=NULL)
			add1(k,BST_Ptr->right);
		else
			BST_Ptr->right=k;
	}

}

void print(bst* BST_Ptr){
	if(BST_Ptr==NULL)
		printf("NULL\n");
	else
	{
		printf("KEY is %d\n",BST_Ptr->key );
		printf("LEFT of %d->",BST_Ptr->key);
		print(BST_Ptr->left);
		printf("RIGHT of %d->",BST_Ptr->key);
		print(BST_Ptr->right);
	}
}

void add(int k,bst* BST_Ptr){
	if(BST_Ptr==NULL){
		return;
	}
	bst* new=(bst*)malloc(sizeof(bst));
	new->left=NULL;
	new->right=NULL;
	new->key=k;
	add1(new,BST_Ptr);
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

bst* randomConstruct(int* arr,int N){
	bst* bst2=(bst*)malloc(sizeof(bst));
	int* temp=(int*)malloc(N* sizeof(int));
	int i=0;
	for ( i = 0; i < N; ++i)
	{
		temp[i]=arr[i];
	}
	int j=N-1,k;
	k=rand()%N;
	bst2->key=temp[k];
	bst2->left=NULL;
	bst2->right=NULL;
	temp[k]=temp[N-1];
	for(i=0;i<N-1;i++){
		k=rand()%j;
		j--;		
		add(temp[k],bst2);
		temp[k]=temp[j];
	
	}
	return bst2;
}

int find(int k,bst* BST_Ptr){
	if(BST_Ptr==NULL)
		return 0;
	else if(BST_Ptr->key==k)
		return 1;
	else{
		if(k>BST_Ptr->key)
			return find(k,BST_Ptr->right);
		else
			return find(k,BST_Ptr->left);
	}
}

int delete(int k,bst* BST_Ptr){
	int i;
	bst* temp3;
	i=find(k,BST_Ptr);
	if(i==0)
		return 0;
	bst* temp=BST_Ptr;
	bst* temp4 =BST_Ptr;
	while(temp->key!=k){
		if(temp->key>k){
			temp4=temp;
			temp=temp->left;
		}
		else
		{
			temp4=temp;
			temp=temp->right;
		}
	}
	if(temp->left==NULL&&temp->right==NULL){
		if(temp==BST_Ptr){
			free(temp);
			BST_Ptr=NULL;
			return k;
		}
		if(temp4->key>temp->key)
			temp4->left=NULL;
		else
			temp4->right=NULL;
		free(temp);
		return k;
	}
	else if(temp->right==NULL){
		if(temp==BST_Ptr){
			temp4=temp->left;
			temp->key=temp4->key;
			temp->right=temp4->right;
			temp->left=temp4->left;
			
			free(temp4);
			return k;
		}
		if(temp4->key>temp->key)
			temp4->left=temp->left;
		else
			temp4->right=temp->left;
		free(temp);
		return k;
	}
	else if(temp->left==NULL){
		if(temp==BST_Ptr){
			temp4=temp->right;
			temp->key=temp4->key;
			temp->left=temp4->left;
			temp->right=temp4->right;
			free(temp4);
			return k;
		}
		if(temp4->key>temp->key)
			temp4->left=temp->right;
		else
			temp4->right=temp->right;
		free(temp);
		return k;
	}

	bst* temp2=temp->right;
	temp3=temp2;
	while(temp2->left!=NULL){
		temp3=temp2;
		temp2=temp2->left;
	}
	
	temp->key=temp2->key;
	temp->right=temp2->right;
	temp3->left=NULL;
	free(temp2);
	return k;
	
}

int findHeight(bst* BST_Ptr){
	int i=0,j=0;
	bst* temp=BST_Ptr;
	if(BST_Ptr==NULL)
		return 0;
	if(temp->left==NULL&&temp->right==NULL){
		return 1;
	}
	if(temp->left!=NULL){
		i=findHeight(temp->left);
	}
	if(temp->right!=NULL)
		j=findHeight(temp->right);
	if(i<j){
		return 1+j;
	}
	return 1+i;

}

void experiment(bst* bst1,bst* bst2){
	int i,j;
	//printf("sfddgf\n");
	if(bst1==NULL||bst2==NULL)
		printf("Height of bst1 is 0\nHeight of bst2 is 0\n");
	else{
		i=findHeight(bst1);
		j=findHeight(bst2);
		printf("Height of bst1 is %d\nHeight of bst2 is %d\n",i-1,j-1 );
	}
}

