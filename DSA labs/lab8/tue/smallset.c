#include "smallset.h"

void readData(FILE *fp,unsigned int *a,unsigned int *b){
	unsigned int B=1;
	int X,Y,N,i,temp;
	fscanf(fp,"%d",&N);
	//printf("%d\t",N );
	fscanf(fp,"%d",&X);
	//printf("%d\t",X );
	fscanf(fp,"%d",&Y);
	//printf("%d\n",Y );
	for(i=0;i<X;i++){
		fscanf(fp,"%d",&temp);
		//printf("%d\t",temp );
		*a=*a|B<<temp;
	}
	//printf("\n");
	for(i=0;i<Y;i++){
		fscanf(fp,"%d",&temp);
		//printf("%d\t",temp );
		*b=*b|B<<temp;
	}
	//printf("\n");
}


unsigned int Union(unsigned int *a,unsigned int *b){
	unsigned int c;
	c=*a|*b;
	return c;

}

unsigned int Intersection(unsigned int *a,unsigned int *b){
	unsigned int c;
	c=*a&*b;
	return c;
}

unsigned int Difference(unsigned int *a,unsigned int *b){
	unsigned int c,e;
	int i=0;
	e=*a&*b;
	c=*a;
	unsigned int d=1,temp=c,temp1=e;
	for(i=0;i<32;i++){
		if(temp&d==1&&temp1&d==1){
			c=c-(d<<i);
		}
		temp=temp>>1;
		temp1=temp1>>1;
	}
	return c;
}

void print(unsigned int c){
	int i=0,flag=0;
	unsigned int temp=c,d=1;
	for(i=0;i<32;i++){
		if(temp&d==1){
			printf("%d\t",i );
			flag=1;
		}
		temp=temp>>1;
	}
	if(flag!=1)
		printf("NULL");
	printf("\n");

}
