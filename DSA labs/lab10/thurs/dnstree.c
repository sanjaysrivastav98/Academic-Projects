#include "dnstree.h"
#include <string.h>


void mystrcpy(char* s1,char* s2){
	int a=strlen(s2),i;
	//printf("%d--strlen\n",a );
	for(i=0;i<a;i++){
		s1[i]=s2[i];
	}
	s1[i]='\0';
	//printf("%s--s1\n",s1);
}	

int noofDots(char* s){
	int i=0,count=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='.'){
			count++;
		}
	}
	return count;
}	

char** split(char* s){
	int i=0,j=noofDots(s)+1,k=0,z=0;
	//printf("%d %s\n",j,s );
	char** d= (char**)malloc(j*sizeof(char*));
	for(i=0;i<j;i++){
		d[i]=(char*)malloc(400*sizeof(char));
		k=0;
		while(s[z]!='.'){
			if(s[z]=='\0')
				break;
			d[i][k]=s[z];
			//printf("%c\n",s[z] );
			k++;
			z++;
		}
		z++;
		//printf("%s--\n",d[i] );
		
	}
	return d;
}

int mystrcmp(char* s1,char* s2){
	if(s1==NULL||s2==NULL){
		return -1;
	}
	int a=strlen(s1),b=strlen(s2);
	if(a!=b){
		return 0;
	}
	int i=0;
	while(i<a){
		if(s1[i]!=s2[i])
			return 0;
		i++;
	}	
	return 1;
}

dnsNode* isPresent(dnsNode* head,char* s){
	dnsNode* temp=head->child;
	while(temp!=NULL){
		if(mystrcmp(temp->str,s)==1){
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}

dnsNode* insertNode(dnsNode* head,char* s){
	dnsNode* new=(dnsNode*)malloc(sizeof(dnsNode));
	mystrcpy(new->str,s);
	new->next=NULL;
	new->child=NULL;
	dnsNode* temp=head->child;
	if(temp==NULL){
		head->child=new;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new;
	}
	return head;
}

dnsNode* insert(dnsNode* d,char** s,char** ip,int N){
	int i,j,k;
	char** p;
	dnsNode* temp=d;
	dnsNode* temp1;
	dnsNode* new;
	for(i=0;i<N;i++){
		new=(dnsNode*)malloc(sizeof(dnsNode));
		new->isLeafNode=1;
		new->child=NULL;
		new->next=NULL;
		temp=d;
		j=noofDots(s[i])+1;
		p=split(s[i]);
		
		for(k=j-1;k>=0;k--){
			temp1=isPresent(temp,p[k]);
			if(temp1==NULL){
				temp=insertNode(temp,p[k]);
				temp1=isPresent(temp,p[k]);
			}
			temp=temp1;
		}
		mystrcpy(new->str,ip[i]);
		temp->child=new;
		//printf("%s--ip\n",temp->str );
	}
	//print(d);
	return d;
}


dnsNode* readData(FILE *fp,int N){
	char** s =(char**)malloc(N*sizeof(char*));
	char** ip =(char**)malloc(N*sizeof(char*));
	
	int i;
	for (i = 0; i < N; i++)
	{
		s[i]=(char*)malloc(500*sizeof(char));
		ip[i]=(char*)malloc(500*sizeof(char));
		fscanf(fp,"%s",s[i]);
		//printf("%s ",s[i] );
		fscanf(fp,"%s",ip[i]);
		//printf("%s\n",ip[i] );
	}

	dnsNode* d=(dnsNode*)malloc(sizeof(dnsNode));
	mystrcpy(d->str,".");
	d->next=NULL;
	d->child=NULL;
	d=insert(d,s,ip,N);
	//print(d);
	return d;
}

void lookup(dnsNode* d,char* s){
	char** p;
	dnsNode* temp=d,*temp1;
	p=split(s);
	int k=0,flag=0,j=noofDots(s)+1,z;
	for(k=j-1;k>=0;k--){
		temp1=isPresent(temp,p[k]);
		//printf("%s  %d\n",temp1->str,k );
		if(temp1==NULL){
			flag=1;
			break;
		}
		
		
		temp=temp1;
		if(k==0){
			//printf("uyyyv\n");
			if(temp->child->isLeafNode==1){
				printf("%s ",temp->child->str );
				return;
			}
		}
	}
	
		temp=d;
		k=j-1;
		while(k>=0){
			z=0;
			temp1=temp->child;
			//printf("afdgbf %s\n",s );
			while(temp1!=NULL){
				//printf("%s %s\n",temp1->str,p[k] );
				if(mystrcmp(temp1->str,p[k])==1){
					//printf("%s\n",p[k] );
					break;
				}
				z++;
				//printf("%d--z\n",z );
				temp1=temp1->next;
			}
			//printf("%d ",z );
			if(temp1==NULL){
				break;
			}
			printf("%d ",z );
			temp=temp1;
			//printf("%s %d\n",temp->str,k );
			k--;
		}
	}


