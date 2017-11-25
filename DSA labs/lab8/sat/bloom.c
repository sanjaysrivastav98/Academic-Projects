#include "bloom.h"
#include <math.h>

int hash(int A,int B,int N,int e){
	return (A*e+B)%N;
}

int hash1(int N,int e){
	return hash(7,11,N,e);
}

int hash2(int N,int e){
	return hash(11,13,N,e);
}

int hash3(int N,int e){
	return hash(13,17,N,e);
}

int hash4(int N,int e){
	return hash(17,19,N,e);
}

int hash5(int N,int e){
	return hash(19,23,N,e);
}



bloom CreateBloomFilter(int X,int N)
{
	bloom b;
	choose s;
	s.s1=CreateBitVector(N);
	s.s2=CreateBitVector1(N);
	b.c=s;
	b.l=5;
	b.n=N;
	b.w=X;
	b.m=0;
	return b;
}

bloom Insert(bloom b,int V){
	if(Find(b,V)){
		return b;
	}
	if(b.w==2){
		if(b.l>=1)
			b.c.s1=Set(b.c.s1,b.n,hash1(b.n,V));
		if(b.l>=2)
			b.c.s1=Set(b.c.s1,b.n,hash2(b.n,V));
		if(b.l>=3)
			b.c.s1=Set(b.c.s1,b.n,hash3(b.n,V));
		if(b.l>=4)
			b.c.s1=Set(b.c.s1,b.n,hash4(b.n,V));
		if(b.l>=5)
			b.c.s1=Set(b.c.s1,b.n,hash5(b.n,V));
	}
	else{
		if(b.l>=1)
			b.c.s2=Set1(b.c.s2,b.n,hash1(b.n,V));
		if(b.l>=2)
			b.c.s2=Set1(b.c.s2,b.n,hash2(b.n,V));
		if(b.l>=3)
			b.c.s2=Set1(b.c.s2,b.n,hash3(b.n,V));
		if(b.l>=4)
			b.c.s2=Set1(b.c.s2,b.n,hash4(b.n,V));
		if(b.l>=5)
			b.c.s2=Set1(b.c.s2,b.n,hash5(b.n,V));
	}
	b.m++;
	return b;

}

int Find(bloom b,int V){
	int i,z;
	if(b.w==2){
		if(b.l>=1){
			i=Get(b.c.s1,b.n,hash1(b.n,V));
		
		if (i==0)
			return 0;}
		if(b.l>=2){
			i=Get(b.c.s1,b.n,hash2(b.n,V));
		
		if (i==0)
			return 0;}
		if(b.l>=3){
			i=Get(b.c.s1,b.n,hash3(b.n,V));
		
		if (i==0)
			return 0;}
		if(b.l>=4){
			i=Get(b.c.s1,b.n,hash4(b.n,V));
		
		if (i==0)
			return 0;}
		if(b.l>=5){
			i=Get(b.c.s1,b.n,hash5(b.n,V));
		
		if(i==0)
			return 0;}
		return 1;
	
	} 
	else{
		if(b.l>=1){
			i=Get1(b.c.s2,b.n,hash1(b.n,V));
		
		if (i==0)
			return 0;}
		if(b.l>=2){
			i=Get1(b.c.s2,b.n,hash2(b.n,V));
		
		if (i==0)
			return 0;}
		if(b.l>=3){
			i=Get1(b.c.s2,b.n,hash3(b.n,V));
		
		if (i==0)
			return 0;}
		if(b.l>=4){
			i=Get1(b.c.s2,b.n,hash4(b.n,V));
		
		if (i==0)
			return 0;}
		if(b.l>=5){
			i=Get1(b.c.s2,b.n,hash5(b.n,V));
		
		if(i==0)
			return 0;}
		return 1;
	}
}

bloom Clear(bloom b){
	int i;
	if(b.w==1){
		for(i=0;i<b.n;i++){
			b.c.s1[i]=0;
		}

	}
	else
		b.c.s2=0;
	b.l=5;
	b.m=0;
	b.n=0;
	return b;
}

bloom Experiment(FILE *fp,bloom b){
	int i,K,L,z;
	double p,r;
	fscanf(fp,"%d",&K);
	//printf("4 %d ",K );
	fscanf(fp,"%d",&L);
	//printf("%d\n",L );
	int a[K][2];
	//int* arr=(int*)malloc(K*sizeof(int));
	b.l=L;
	for(i=0;i<K;i++){
		fscanf(fp,"%d",&a[i][0]);
		//printf("%d ",a[i][0] );
		fscanf(fp,"%d",&a[i][1]);
		//printf("%d\n",a[i][1] );
		if(a[i][0]==1){
			b=Insert(b,a[i][1]);
			//b.m++;
			r=(double)(-b.l)*(b.m)/(double)(b.n);
			//printf("%f\n",(double)(b.l*b.m)/b.n );
			r=1-exp(r);
			p=pow(r,b.l);
			printf("%lf\n",p);
		}
		else{
			z=Find(b,a[i][1]);
			r=(double)(-b.l)*(b.m)/(b.n);
			//printf("%d\t%d\t%d\t%f\n",b.l,b.m,b.n,r );
			r=1-exp(r);
			p=pow(r,b.l);
			printf("%d\t%lf\n",z,p);
		}
	}
	return b;

}