#include "dict.h"

long long int mypow(int a, int b){
	long long int c;
	int i=0;
	c=1;
	for(i=0;i<b;i++){
		c*=a;
	}
	return c;

}

int min(int a,int b){
	if(a<b)
		return a;
	else
		return b;

}


int mylog(long long int x){
	long long int j=x;int c=0;
	for(;j!=1;j/=2){
		c++;

	}
	if(x&(mypow(2,c)-1)==0)
	return c;
	else
		return c+1;
}

int bit(long long  int k,int t){

	int *a=(int*)malloc(100*sizeof(int));
	int i=0;
	int b;
	long long int j=k;
	if(t>32)
		return k;

	for(i=0;i<33-t;i++)
		j=j >> 1;
	return j;
	
	// else
	// 	return k;
}




int hash(char *s,int c,int t){
	int l=strlen(s);
	long int  A=65791;
	int i=0;
	long long int k;
	long int m[l+1];
	m[0]=0;
	for(i=0;i<l;i++){
		m[i+1]=(A*m[i]+(int)s[i])&(mypow(2,32)-1);
	}
	k=(m[l]*c)&(mypow(2,32)-1);
}

hashTable* createHashTable(int t,int a,int b){
	hashTable* h =(hashTable*)malloc(sizeof(hashTable));
	h->s=mypow(2,t);
	h->a=a;
	h->b=b;
	h->n=0;
	char **d =(char** )malloc(h->s*sizeof(char*));
	int i=0;
	for(i=0;i<h->s;i++){
		d[i]=NULL;
	}
	h->data=d;
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
int find(hashTable* h,char* str){
	int i,j=0,k;
	k=mylog(h->s);
	i=hash(str,h->a,k);
	if(mystrcmp(h->data[i],str)==0){
		
		return 0;
	}
	else
		{
		j=hash(str,h->b,k);
		if(mystrcmp(h->data[j],str)==0){

			return 0;}
		}

	return -1;
}

void mystrcpy(char *s,char* d){
	s=(char*)malloc(20*sizeof(char));
	int i=0,l=strlen(d);
	for(i=0;i<l;i++){
		s[i]=d[i];
	}
}

int insert1(hashTable* h,char *str){
	int l,i,k=0,j;
	printf("%s--------------%s\n",h->data[2],str);
	l=find(h,str);
	printf("%d----l\n",l);
	k=mylog(h->s);
	char *newstr;
	printf("%d\n",l);
	if(l==0){
		return 1;
	}
	else{
		i=hash(str,h->a,k);
		if(h->data[i]==NULL){
			mystrcpy(h->data[i],str);
			h->n++;
			return 1;
		}
		else{
			j=hash(str,h->b,k);
			if(h->data[j]==NULL){
				mystrcpy(h->data[j],str);
				h->n++;
				return 1;
			}
			else{
				mystrcpy(newstr,h->data[j]);
				mystrcpy(h->data[j],str);
				MAX_CNT++;
				j=insert1(h,newstr);
				if(MAX_CNT==10||j==1){
					MAX_CNT =0;
					return 0;
				}
			}


		}

	}
	return 0;


}

void printHashTable(hashTable *h){
	int i=0;
	for(i=0;i<h->s;i++){
		if(h->data[i]!=NULL){
			printf("%d\t%s\n",i,h->data[i]);
		}

	}

}

