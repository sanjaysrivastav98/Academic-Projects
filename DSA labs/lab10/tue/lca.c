#include "lca.h"

#include <string.h>
void mystrcpy(char* s1,char* s2){
	int i=0,a=strlen(s2);
	for(i=0;i<a;i++){
		s1[i]=s2[i];
	}
	s1[i]='\0';
}

int noofslashes(char* s){
	int a=strlen(s),i,z=0;
	for(i=0;i<a;i++){
		if(s[i]=='/')
			z++;
	}
	return z;
}

char** split(char* s){
	int i,a=noofslashes(s),k,z=0;
	char** d=(char**)malloc(a*sizeof(char*));
	for(i=0;i<a;i++){
		d[i]=(char*)malloc(500*sizeof(char));
	}
	for(i=0;i<a+1;i++){
		k=0;
		//printf("a--%d\n",i);
		while(s[z]!='/'){
			if(s[z]=='\0')
				break;
			d[i-1][k]=s[z];
			z++;
			k++;
		}
		z++;
	}
	return d;
}

char** split2(char* s){
    int i,a=noofslashes(s);
    char** d=(char**)malloc(a*sizeof(char*));
    char* s2="/";
    char* token;
    token= strtok(s,s2);

    for(i=0;i<a;i++){
        d[i]=(char*)malloc(500*sizeof(char));
    }
    i=0;
    while(token!=NULL&& a>0){
        mystrcpy(d[i],token);
        token=strtok(NULL,s2);
        i++;
    }
    return d;
}



int mystrcmp(char* s1,char* s2){
	if(s1==NULL||s2==NULL){
		return -1;
	}
	int a=strlen(s1),b=strlen(s2),i;
	if(a!=b){
		return 0;
	}
	for(i=0;i<a;i++){
		if(s1[i]!=s2[i]){
			return 0;
		}
	}
	return 1;
}

directory* insertatend(directory* d,char* s){
	directory* new=(directory*)malloc(sizeof(directory));
	mystrcpy(new->s,s);
	new->child=NULL;
	new->next=NULL;
	directory* temp=d->child;
	if(temp==NULL){
		d->child=new;
	}
	else{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new;
	}
	return d;
}

directory* isPresent(directory* d,char* s){
	directory* temp=d->child;
	if(temp==NULL){
		return NULL;
	}
	while(temp!=NULL){
		if(mystrcmp(temp->s,s)==1){
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}

directory* insert(directory* d,char* s){
	int a=noofslashes(s),i;
	char** s1=split2(s);
	directory* temp=d;
	directory* temp2;
	//printf("%s\n",s );
	
	//printf("%d\n",a );
	for(i=0;i<a;i++){
		temp2=isPresent(temp,s1[i]);
		if(temp2==NULL){
			temp=insertatend(temp,s1[i]);
			temp2=isPresent(temp,s1[i]);
		}
		temp=temp2;

	}	
	return d;
}

directory* readData(FILE* fp,int N){
	directory* d=(directory*)malloc(sizeof(directory));
	mystrcpy(d->s,"/");
	d->child=NULL;
	d->next=NULL;
	char** s=(char**)malloc(N*sizeof(char*));
	int i=0;
	for(i=0;i<N;i++){
		s[i]=(char*)malloc(1000*sizeof(char));
		fscanf(fp,"%s",s[i]);
		//printf("%s\n",s[i] );
		d=insert(d,s[i]);
		//printf("%s\n",s[i] );
	}
	return d;
}

directory* addreadData(directory* d,FILE* fp,int N){
	char** s=(char**)malloc(N*sizeof(char*));
	int i=0;
	for(i=0;i<N;i++){
		s[i]=(char*)malloc(1000*sizeof(char));
		fscanf(fp,"%s",s[i]);
		//printf("%s\n",s[i] );
		d=insert(d,s[i]);
		//printf("%s\n",s[i] );
	}
	return d;
}

void LCA(directory* d,char* s1,char* s2){
	int a=noofslashes(s1),b=noofslashes(s2),i,z=0;
	char** s3=split2(s1);
	char** s4=split2(s2);
	directory* temp=d;
	directory* temp1;
	if(mystrcmp(s3[0],s4[0])!=1){
		printf("0\n");
		return;
	}
	if(a>=b){
		for(i=0;i<a;i++){
			//printf("%s  %s\n",s3[i],s4[i] );
			if(mystrcmp(s3[i],s4[i])==1){
				if(temp!=NULL)
					temp1=temp->child;
				z=1;
				while(temp1!=NULL){
					if(mystrcmp(temp1->s,s3[i])==1){
						break;
					}
					z++;
					temp1=temp1->next;
				}
				printf("%d ",z );
				temp=temp1;
			}
			else{
				printf("\n");
				return;
			}
		}
	}
	else{
		for(i=0;i<b;i++){
			//printf("%s  %s\n",s3[i],s4[i] );
			if(mystrcmp(s3[i],s4[i])==1){
				if(temp!=NULL)
					temp1=temp->child;
				z=1;
				while(temp1!=NULL){
					if(mystrcmp(temp1->s,s3[i])==1){
						break;
					}
					z++;
					temp1=temp1->next;
				}
				printf("%d ",z );
				temp=temp1;
			}
			else{
				printf("\n");
				return;
			}
		}
	}
	//printf("\n");
	
}