#include "radix.h"

char** readStrings(FILE *fp,int n,int w){
	char** s=(char**)malloc(n*sizeof(char*));
	int i=0;
	for(i=0;i<n;i++){
		s[i]=(char*)malloc(w*sizeof(char));
		fscanf(fp,"%s",s[i]);
	}

	return s;
}

void swap(char* s,char* g,int w){
	int i=0;
	char temp;
	for(i=0;i<w;i++){
		temp=s[i];
		s[i]=g[i];
		g[i]=temp;
	}
}

intPair keyIndex(char** A,int l,int h,int d,int w){
	int i=0,f,k=0,j;
	char ref='X';
	int piv=1;
	int p=0,q=h,m1=l,m2=h;
	char ** s=(char**)malloc((h-l+1)*sizeof(char*));
	//char ** g=(char**)malloc((h-l+1)*sizeof(char*));
	for(i=0;i<(h-l+1);i++){
		s[i]=(char*)malloc(w*sizeof(char));
		for(j=0;j<w;j++)
			s[i][j]=A[i][j];
	}
	while(m1<=m2){
		for(;s[p][d]-ref==piv;p++);
		if(m1<p){
			m1=p;
		}
		for(;s[m1][d]-ref<piv;m1++);
		for(;s[q][d]-ref==piv;q--);
		if(m2>q)
			m2=q;
		for(;s[m2][d]-ref>piv;m2--);
		if(m1<=m2&&s[m1][d]-ref==piv){
			i=m1;
			while(i>p){
			swap(s[i],s[i-1],h-l+1);i--;}
			p++;m1++;
		}
		if(m1<=m2&&s[m2][d]-ref==piv){
			i=m2;
			while(i<q){
			swap(s[i],s[i+1],h-l+1);i++;}
			m2--;q--;
		}
		if(m1<=m2&&s[m1][d]-ref>piv&&s[m2][d]-ref<piv){
			swap(s[m1],s[m2],h-l+1);m1++;m2--;
		}
	}
	for(i=p;i<m1;i++){
		A[k++]=s[i];
	}
	for(i=l;i<p;i++){
		A[k++]=s[i];
	}
	for(i=q+1;i<=h;i++){
		A[k++]=s[i];
	}
	for(i=m2+1;i<=q;i++){
		A[k++]=s[i];
	}
	intPair x;
	x.i=m1-p;
	x.j=q-m2;
	return x;

	
}



void lsdRadixSort(char **A,int l,int h,int w){
	int i=0,j=0,f,k,d=0;
	
	for(d=w-1;d>=0;d--){
		
		keyIndex(A,l,h,d,w);
	}
	
	

}

