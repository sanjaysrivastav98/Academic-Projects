#include<stdio.h>
#include"zbucket.h"

void readData(FILE *fp,int (*arr)[2],int m,int n,int xlo,int xhi,int ylo,int yhi){
	int i=0;
	for(i=0;i<m;i++){
		fscanf(fp,"%d",&arr[i][0]);
		fscanf(fp,"%d",&arr[i][1]);
	}

}

linkedlist insert(int k,linkedlist head){
	int i=0,flag=0;
	node *temp=head.first;
	node* prev=temp;
	node* new;
	if(head.size==0){
		new=(node*)malloc(sizeof(node));
		new->next=NULL;
		new->b=k;
		head.first=new;
		head.size++;
	}
	else{
				temp=head.first;
		while(temp->next!=NULL){
			if(temp->b<=k){
				prev=temp;
				temp=temp->next;			
			}
			else{
				new=(node*)malloc(sizeof(node));
				new->b=k;
				if(temp!=head.first){
				prev->next=new;}
				else{
				head.first=new;
				}
				new->next=temp;	
				flag=1;
				break;		
			}
		}
		if(temp->next==NULL&&flag==0){
			new=(node*)malloc(sizeof(node));
			new->b=k;
			if(temp->b>k){
				new->next=temp;
				if(head.size==1){			
					head.first=new;
				}
				else{
					prev->next=new;
				}
			}
			else{
				new->next=NULL;
				temp->next=new;
				
			}
		}
		head.size++;
	}
	return head;
}

void print(int (*arr)[2],int m,int n){
	int i=0;
	for(i=0;i<m;i++){
		printf("%d\t%d\n",arr[i][0],arr[i][1]);
	}
}

void printBucket(linkedlist *s,int m,int n){
	int j=0,k=0;;
	node *temp;
	for(j=0;j<m;j++){
		printf("%d ::\t",j+n);
		if(s[j].size!=0){
			temp=s[j].first;
			k=0;
			while(k<s[j].size){
				printf("%d->\t",temp->b);
				temp=temp->next;
				k++;
			}
		}
		printf("\n");
	}

}

void SortSparseLists(int (*arr)[2],int m,int n,int xlo,int xhi,int ylo,int yhi){
	int i=0,j,k;
	if((xhi-xlo)>=(yhi-ylo)){
		linkedlist* s=(linkedlist*)malloc((xhi-xlo)*sizeof(linkedlist));
		for(i=0;i<m;i++){
			j=arr[i][0];
			k=arr[i][1];
			s[j-xlo]=insert(k,s[j-xlo]);
			//printf("%d   %d\n",i,arr[i][0]);
			//printBucket(s,xhi-xlo,xlo);
		}
		j=0;
		node* temp;
		for(i=0;i<(xhi-xlo);i++){
			if(s[i].size!=0){
				temp=s[i].first;
				for(k=0;k<s[i].size;k++){
					arr[j][0]=i+xlo;
					//printf("%d\t",arr[j][0]);
					arr[j][1]=temp->b;
					//printf("%d\n",arr[i+j+xlo][1]);					
					j++;
					temp=temp->next;
				}		
			}
		}
		

	}
	else{
		linkedlist* s=(linkedlist*)malloc((yhi-ylo)*sizeof(linkedlist));
		for(i=0;i<m;i++){
			j=arr[i][1];
			k=arr[i][0];
			s[j-ylo]=insert(k,s[j-ylo]);
			//printf("%d   2%d\n",i,j);

		}
			//printBucket(s,yhi-ylo,ylo);
		j=0;
		node* temp;
		for(i=0;i<(yhi-ylo);i++){
			if(s[i].size!=0){
				temp=s[i].first;
				for(k=0;k<s[i].size;k++){

					arr[j][1]=i+ylo;
					arr[j][0]=temp->b;
					//printf("%d\t",arr[i+j+ylo][0]);
					//printf("%d\n",arr[i+j+ylo][1]);
					j++;
					temp=temp->next;
				}		
			}
		}
	}
	print(arr,m,2);
	
}

/*void SortDenseLists(int (*arr)[2],int m,int n,int xlo,int xhi,int ylo,int yhi){*/
/*	int i=0,j,k;*/
/*	if((xhi-xlo)>=(yhi-ylo)){*/
/*		linkedlist* s=(linkedlist*)malloc((xhi-xlo)*sizeof(linkedlist));*/
/*		for(i=0;i<m;i++){*/
/*			j=arr[i][0];*/
/*			k=arr[i][1];*/
/*			s[j-xlo]=insert(k,s[j-xlo]);*/
/*			//printf("%d   %d\n",i,arr[i][0]);*/
/*			//printBucket(s,xhi-xlo,xlo);*/
/*		}*/
/*		j=0;*/
/*		node* temp;*/
/*		for(i=0;i<(xhi-xlo);i++){*/
/*			if(s[i].size!=0){*/
/*				temp=s[i].first;*/
/*				for(k=0;k<s[i].size;k++){*/
/*					arr[i+j+xlo][0]=i+xlo;*/
/*					printf("%d\t",arr[i+j+xlo][0]);*/
/*					arr[i+j+xlo][1]=temp->b;*/
/*					printf("%d\n",arr[i+j+xlo][1]);					*/
/*					j++;*/
/*					temp=temp->next;*/
/*				}		*/
/*			}*/
/*		}*/
/*		*/

/*	}*/
/*	else{*/
/*		linkedlist* s=(linkedlist*)malloc((yhi-ylo)*sizeof(linkedlist));*/
/*		for(i=0;i<m;i++){*/
/*			j=arr[i][1];*/
/*			k=arr[i][0];*/
/*			s[j-ylo]=insert(k,s[j-ylo]);*/
/*			//printf("%d   2%d\n",i,j);*/

/*		}*/
/*			printBucket(s,yhi-ylo,ylo);*/
/*		j=0;*/
/*		node* temp;*/
/*		for(i=0;i<(yhi-ylo);i++){*/
/*			if(s[i].size!=0){*/
/*				temp=s[i].first;*/
/*				for(k=0;k<s[i].size;k++){*/

/*					arr[i+j+ylo][1]=i+ylo;*/
/*					arr[i+j+ylo][0]=temp->b;*/
/*					printf("%d\t",arr[i+j+ylo][0]);*/
/*					printf("%d\n",arr[i+j+ylo][1]);*/
/*					j++;*/
/*					temp=temp->next;*/
/*				}		*/
/*			}*/
/*		}*/
/*	}*/

/*}*/

void SortDenseLists(int (*arr)[2],int m,int n,int xlo,int xhi,int ylo,int yhi){
	int i=0;
	int x,y;
	if(xhi-xlo>=yhi-ylo){
		x=xhi-xlo;
		y = yhi-ylo;
	}
	else{
		x=yhi-ylo;
		y=xhi-xlo;
	}
	int a[x][y];
	int j=0,k=0,t;
	for(i=0;i<x;i++){
		for(k=0;k<y;k++){
			a[i][k]=0;	
		}
	}
	for(i=0;i<m;i++){
		a[arr[i][0]-xlo][arr[i][1]-ylo]++;
		
	}
	for(i=0;i<x;i++){
		for(k=0;k<y;k++){
			t=a[i][k];
			while(t!=0){
				arr[j][0]=i+xlo;
				arr[j][1]=k+ylo;
				j++;
				t--;
			}
		}

	}
	print(arr,m,2);
	
}
