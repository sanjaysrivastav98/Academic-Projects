#include "avltree.h"
#include <time.h>

int* readData(FILE* fp,int N){
	int *arr=(int*)malloc(N*sizeof(int));
	int i;
	for(i=0;i<N;i++){
		fscanf(fp,"%d",&arr[i]);
	}
	return arr;
} 


int findHeight(avl* BST_Ptr){
	int i=0,j=0;
	avl* temp=BST_Ptr;
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

xyz* findxyz(avl* tree){
	xyz* a=(xyz*)malloc(sizeof(xyz));
	a->z=tree;
	avl* y,*x;
	if(tree->ind>=1){
		y=tree->right;
		a->j=0;
		if(y->ind==1){
			x=y->right;
			a->i=1;
		}
		else{
			x=y->left;
			a->i=0;
		}
	}
	else{
		y=tree->left;
		a->j=1;
		if(y->ind==1){
			x=y->right;
			a->i=0;
		}
		else{
			x=y->left;
			a->i=1;
		}
	}
	a->y=y;
	a->x=x;
	return a;
}

avl* rotate(avl* tree){
	xyz* nodes=findxyz(tree);
	tree->ind=findHeight(tree->right)-findHeight(tree->left);
	avl *a,*b,*c,*t0,*t1,*t2,*t3,*res;
	int i=1;
	if(tree->ind>1||tree->ind<-1){
	if(nodes->j==0){
		a=nodes->z;
		t0=a->left;
		if(nodes->i==0){
			b=nodes->x;
			t1=b->left;
			t2=b->right;
			c=nodes->y;
			t3=c->right;
			i++;
		}
		else{
			b=nodes->y;
			t1=b->left;
			c=nodes->x;
			t2=c->left;
			t3=c->right;
		}
	}
	else{
		c=nodes->z;
		t3=c->right;
		if(nodes->i==0){
			a=nodes->y;
			t0=a->left;
			b=nodes->x;
			t1=b->left;
			t2=b->right;
			i++;
		}
		else{
			a=nodes->x;
			t0=a->left;
			t1=a->right;
			b=nodes->y;
			t2=b->right;
		}
	}
	b->left=a;
	b->right=c;
	a->left=t0;
	a->right=t1;
	c->left=t2;
	c->right=t3;

	a->ind=findHeight(a->left)-findHeight(a->right);
	b->ind=findHeight(b->left)-findHeight(b->right);
	c->ind=findHeight(c->left)-findHeight(c->right);
	
	res=(avl*)malloc(sizeof(avl));
	res->key=i;
	res->left=b;
	res->right=NULL;
	res->ind=0;
	
		tree=res->left;
		n+=res->key;
	}
	return tree;
}

avl* add1(avl* tree,avl* k){
	int i,j;
		if(k->key>tree->key&& tree->ind==0){
			tree->ind=1;
			if(tree->right!=NULL)
				tree->right=add1(tree->right,k);
			else
				tree->right=k;
			tree=rotate(tree);
		}
		else if(tree->ind==0){
			tree->ind=-1;
			if(tree->left!=NULL)
				tree->left=add1(tree->left,k);
			else
				tree->left=k;
			tree=rotate(tree);
		}
		else if(tree->ind==1 && k->key<=tree->key){
			tree->ind=0;
			if(tree->left!=NULL)
				tree->left=add1(tree->left,k);
			else
				tree->left=k;
			tree=rotate(tree);
		}
		else if(tree->ind==-1&& k->key>tree->key){
			tree->ind=0;
			if(tree->right!=NULL)
				tree->right=add1(tree->right,k);
			else 
				tree->right=k;
			tree=rotate(tree);
		}
		else{
			if(tree->ind==1){
				if(tree->right!=NULL)
					tree->right=add1(tree->right,k);
				else
					tree->right=k;
				tree=rotate(tree);
			}
			else{
				if(tree->left!=NULL)
					tree->left=add1(tree->left,k);
				else
					tree->left=k;
				tree=rotate(tree);
			}
		}
	return tree;
}	

avl* add(avl* tree,int k){
	avl* node=(avl*)malloc(sizeof(avl));
	node->key=k;
	node->left=NULL;
	node->right=NULL;
	node->ind=0;
	tree=add1(tree,node);
	return tree;
}

avl* construct(int* arr,int N){
	avl* tree=(avl*)malloc(sizeof(avl));
	clock_t start,stop;
	start=clock();
	int i,j;
	tree->key=arr[0];
	tree->ind=0;
	tree->left=NULL;
	tree->right=NULL;
	for(i=1;i<N;i++){
		tree=add(tree,arr[i]);
	}
	stop=clock();
	t=(double)(stop-start)/CLOCKS_PER_SEC;
	return tree;
}

int find(int k,avl* BST_Ptr){
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

void measure(){
	printf("%lf\n",t );
}