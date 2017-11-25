#include "hashset.h"

int hash(int j,int M){
	return  (19*j+23)%M;;
}


void readData(FILE *fp,unsigned int* a,unsigned int * b,int M){
	int N,X,Y,i,temp2;
	unsigned int B=1;
	fscanf(fp,"%d",&N);
	//printf("%d\n",M );
	fscanf(fp,"%d",&X);
	//printf("%d\n",X );
	fscanf(fp,"%d",&Y);
	//printf("%d\n",Y);
	int *a1=(int*)malloc(X*sizeof(int));
	int *b1=(int*)malloc(Y*sizeof(int));
	for(i=0;i<X;i++){
		fscanf(fp,"%d",&a1[i]);
		temp2=(int)a1[i]%N;
		a[hash(a1[i],M)]=a[hash(a1[i],M)]|(B<<temp2);

	}
	for(i=0;i<Y;i++){
		fscanf(fp,"%d",&b1[i]);
		temp2=(int)b1[i]%N;
		b[hash(b1[i],M)]=b[hash(b1[i],M)]|(B<<temp2);
	}

}

unsigned int *Union(unsigned int* a,unsigned int * b,int M){
	unsigned int*c=(unsigned int*)malloc(M*sizeof(unsigned int));
	int i;
	for(i=0;i<M;i++){
		c[i]=a[i]|b[i];
	} 
	return c;
}

unsigned int* Intersection(unsigned int* a,unsigned int * b,int M){
	unsigned int*c=(unsigned int*)malloc(M*sizeof(unsigned int));
	int i;
	for(i=0;i<M;i++){
		c[i]=a[i]&b[i];
	} 
	return c;
}

unsigned int* Difference(unsigned int* a,unsigned int * b,int M){
	unsigned int*c=(unsigned int*)malloc(M*sizeof(unsigned int));
	int i,j;
	unsigned int temp,temp2,d=1;

	for(i=0;i<M;i++){
		c[i]=a[i];
		temp=c[i];
		//temp1=b[i];
		temp2=a[i]&b[i];
		for(j=0;j<32;j++){
			if(temp&d==1&&temp2&d==1){
				c[i]=c[i]-(d<<j);
			}
			temp=temp>>1;
			temp2=temp2>>1;
		}
	}
	return c;
}

void print(unsigned int *c,int M){
	int i=0,flag=0,j;
	unsigned int temp,d=1;
	int* arr=(int*)malloc(32*sizeof(int));
	for(j=0;j<M;j++){
		temp=c[j];
		for(i=0;i<32;i++){
			if(temp&d==1){
				printf("%d\t",arr[z] );
				flag=1;
			}
			temp=temp>>1;
		}
	}
	if(flag!=1)
		printf("NULL");
	printf("\n");


}