#include "set.h"


void readData(FILE *fp,unsigned int* a,unsigned int * b,int M){
	int N,X,Y,i,temp,temp2;
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
	//	printf("asddfr\n");
		temp=(int)a1[i]/N;
		temp2=(int)a1[i]%N;
		a[temp]=a[temp]|(B<<temp2);
		//printf("sadsfd\n");

	}
	//print(a,M);
	for(i=0;i<Y;i++){
		fscanf(fp,"%d",&b1[i]);
		temp=(int)b1[i]/N;
		temp2=(int)b1[i]%N;
		b[temp]=b[temp]|(B<<temp2);
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

unsigned int*Intersection(unsigned int* a,unsigned int * b,int M){
	unsigned int*c=(unsigned int*)malloc(M*sizeof(unsigned int));
	int i;
	for(i=0;i<M;i++){
		c[i]=a[i]&b[i];
	} 
	return c;
}

unsigned int*Difference(unsigned int* a,unsigned int * b,int M){
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
	for(j=0;j<M;j++){
		temp=c[j];
		for(i=0;i<32;i++){
			if(temp&d==1){
				printf("%d\t",i+j*32 );
				flag=1;
			}
			temp=temp>>1;
		}
	}
	if(flag!=1)
		printf("NULL");
	printf("\n");


}

