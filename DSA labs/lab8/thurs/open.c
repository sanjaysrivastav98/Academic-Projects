#include "open.h"

unsigned int hash1(char *s,int t){
	unsigned int b=1,c=1,A=65791,m;
	int i;
	for(i=0;i<32;i++){
		b=b<<1;
		b=b|1;
	}
	int l=strlen(s);
	unsigned int* m=(unsigned int*)malloc((l+1)sizeof(unsigned int));
	m[0]=0;
	for(i=0;i<l;i++){
		m[i+1]=(A*m[i]+s[i])&b;
	}
	m=(m[l]*7)&b;
	m=m>>(32-t);
	return m;
}

unsigned int hash2(char *s,int t){
	unsigned int b=1,c=1,A=65791,m;
	int i;
	for(i=0;i<32;i++){
		b=b<<1;
		b=b|1;
	}
	int l=strlen(s);
	unsigned int* m=(unsigned int*)malloc((l+1)sizeof(unsigned int));
	m[0]=0;
	for(i=0;i<l;i++){
		m[i+1]=(A*m[i]+s[i])&b;
	}
	m=(m[l]*7)&b;
	b=1;
	for(i=0;i<t;i++){
		b=b<<1;
		b=b|1;
	}
	m=m&b;
	return m;
}

char** readData(FILE* fp,int N){
	char** s=(char**)malloc(N* sizeof(char*));
	int i;
	for(i=0;i<N;i++){
		char* s[i]=(char*)malloc(20*sizeof(char));
		fscanf(fp,"%s",s[i]);
	}
	return s;
}

hashTable* createHashTable(char**s,int N,int K,int t){
	hashTable* h=(hashTable*)malloc(sizeof(hashTable));
	h->t=t;
	h->entries=0;
	unsigned int b=1;
	int i=0;
	b=b<<t;
	h->size=b;
	h->loadFactor=0;
	h->findCount=0;
	h->findProbes=0;
	h->findRatio=0;
	h->k=K;
	h->data=(char**)malloc((h->size)*(sizeof(char*)));
	for(i=0;i<N;i++){
		h=add(h,i,s);
	}
	return h;
}

int mystrcmp(char *s,char* d){
	if(s==NULL){
		return -1;
	}
	else{
		return strcmp(s,d);
	}
}

datapro* find(hashTable* h,int i,char** s){
	datapro* d=(datapro*)malloc(sizeof(datapro));
	int j,m=1,n,t,z=0,y;

	j=hash1(s[i],h->t);
	y=mystrcmp(h->data[j],s[i]);
	if(y==1){
		d->dat=s[i];
		d->z=z;
		return d;
	}
	if(h->k==0){
		while(mystrcmp(h->data[n],s[i])==0){
			z++;
			n=(n+1)%h->size;
		}
		if(mystrcmp(h->data[n],s[i])==-1){
			d->dat=NULL;
			return d;
		}
	}
	else if(h->k==1){
		n=j;
		while(mystrcmp(h->data[n],s[i])==0){
			z++;
			n=(j+(m*m))%h->size;
			m++;
		}
		if(mystrcmp(h->data[n],s[i])==-1){
			d->dat=NULL;
			return d;
		}
	}
	else if(h->k==2){
		n=hash2(s[i],h->t);
		t=j;
		while(mystrcmp(h->data[t],s[i])==0){
			z++;
			t=(j+m*n)%h->size;
			m++;
		}
		if(mystrcmp(h->data[n],s[i])==-1){
			d->dat=NULL;
			return d;
		}
	}
	d->dat=s[i];
	d->z=z;
	return d;
}

hashTable* add(hashTable* h,int i,char** s){
	if(find(h,i,s)->dat==NULL)
		return h;
	int j,m=1,n,t,z;
	j=hash1(s[i],h->t);
	if(h->data[j]==NULL){
		h->data[j]=s[i];
		h->entries++;
		h->loadFactor=h->entries/h->size;
		return h;
	}
	if(h->k==0){
		while(h->data[n]!=NULL){
			n=(n+1)%h->size;z++;
		}
		h->data[n]=s[i];
	}
	else if(h->k==1){
		n=j;
		while(h->data[n]!=NULL){
			n=(j+(m*m))%h->size;z++;
			m++;
		}
		h->data[n]=s[i];
	}
	else if(h->k==2){
		n=hash2(s[i],h->t);
		t=j;
		while(h->data[t]!=NULL){
			t=(j+m*n)%h->size;z++;
			m++;
		}
		h->data[t]=s[i];
	}
	h->findProbes=z;
	h->entries++;
	h->loadFactor=h->entries/h->size;
	return h;
}

