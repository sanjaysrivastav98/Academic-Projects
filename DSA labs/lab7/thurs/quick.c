#include<stdio.h>
#include "quick.h"

student* readData(int m,FILE *fp){
	int i=0;
	student* s=(student*)malloc(m*sizeof(student));
	for(i=0;i<m;i++){
		fscanf(fp,"%s",s[i].name);
		fscanf(fp,"%u",&s[i].marks);
	}
	return s;
}

int pivot(student* s,int lo,int hi){
	return hi;
}

int part(student* s,int lo,int hi,int p,cmp *c){
	int lf,rt,n;
	lf=lo;
	rt=hi-1;
	student temp;
	// temp=s[hi];
	// s[hi]=s[lo];
	// s[lo]=temp;
	// c->x1++;
	while(lf<rt){
		for(;s[lf].marks<=s[hi].marks;lf++){
			c->x2++;
		}
		c->x2++;
		for(;rt>=lo&&s[rt].marks>s[hi].marks;rt--){
			c->x2++;
		}
		if(rt>=lo)
			c->x2++;
		if(lf<rt){
			temp=s[lf];
			s[lf]=s[rt];
			s[rt]=temp;
			c->x1++;
			rt--;
			lf++;
		}
	}
	if(lf==rt)
		n=rt;
	else
		n=rt+1;
	temp=s[p];
	s[p]=s[n];
	s[n]=temp;
	c->x1++;
	return n;
}

void insertSort(student* s,int lo,int hi,int y,cmp* c ){
	student temp;
	int i=lo,j=hi,k;
	for(i=lo;i<=hi;i++){
		k=i;
		for(j=i+1;j<=hi;j++){
			if(s[j].marks<s[k].marks){
				if(y==0)
					c->y2++;
				else
					c->y4++;
				k=j;
			}
			if(y==0)
				c->y2++;
			else
				c->y4++;
		}
		temp=s[i];
		s[i]=s[k];
		s[k]=temp;
		if(y==0)
			c->y1++;
		else
			c->y3++;
	}
}

void print(student * s,int m){
	int i=0;
	for(i=0;i<m;i++){
		printf("%s %u\n",s[i].name,s[i].marks);
	}
}

void quickInSort(student* s,int lo,int hi,int t,cmp *c){
	int p;
	if(hi>lo){
	if(hi-lo+1<=t){
		
		insertSort(s,lo,hi,0,c);
	}
	else{
		p=pivot(s,lo,hi);
		p=part(s,lo,hi,p,c);

		quickInSort(s,lo,p-1,t,c);
		quickInSort(s,p+1,hi,t,c);
	}
	}
}

pivots* pivot2(student* s,int lo,int hi){
	pivots *p=(pivots*)malloc(sizeof(pivots));
	p->p1=lo;
	p->p2=hi;
	return p;
}

pivots* part2(student* s,int lo,int hi,pivots* p,cmp *c){
	int l,m,g,n1,n2;
	l=lo+1;
	m=lo+1;
	g=hi-1;
	student temp;
	if(s[p->p1].marks>s[p->p2].marks){
		temp=s[p->p1];
		s[p->p1]=s[p->p2];
		s[p->p2]=temp;
		c->x3++;
	}
	c->x4++;
	while(m<g){
		for(;s[l].marks<s[p->p1].marks;l++){
			c->x4++;
		}
		c->x4++;
		if(m==lo+1){m=l;}
		for(;s[m].marks>=s[p->p1].marks&&s[m].marks<=s[p->p2].marks;m++){
			c->x4++;
		}
		c->x4++;
		for(;s[g].marks>s[p->p2].marks;g--){
			c->x4++;
		}
		c->x4++;
		if(m<g){
			if(s[m].marks>s[p->p2].marks){
				temp=s[m];
				s[m]=s[g];
				s[g]=temp;
				g--;
				c->x4++;
				c->x3++;
			}
			else if(s[m].marks<s[p->p1].marks){
				temp=s[m];
				s[m]=s[l];
				s[l]=temp;
				l++;
				m++;
				c->x4++;
				c->x3++;
			}
		}
	}		
	n1=l-1;
	if(m==g)
		n2=g;
	else 
		n2=g+1;
	temp=s[p->p1];
	s[p->p1]=s[n1];
	s[n1]=s[p->p1];
	c->x3++;
	temp=s[p->p2];
	s[p->p2]=s[n2];
	s[n2]=temp;
	p->p1=n1;
	printf("%d---n1   %d ----p->p1\n",n1,p->p1 );
	p->p2=n2;
	c->x3++;
	return p;
}

void quickDualPivotSort(student* s,int lo,int hi,int t,cmp *c){
	if(hi>lo){
		if(hi-lo+1<=t)
			insertSort(s,lo,hi,1,c);
		else{
			pivots* p=pivot2(s,lo,hi);
			//printf("%d pivot %d\n",p->p1,p->p2);
			p=part2(s,lo,hi,p,c);
			//printf("%d  part  %d\n",p->p1,p->p2);
			quickDualPivotSort(s,lo,p->p1,t,c);
			quickDualPivotSort(s,p->p1,p->p2,t,c);
			quickDualPivotSort(s,p->p2,hi,t,c);
		}
	}
}


void compare(cmp* c){
	printf("QuickInSort swaps: QuickSort: %d InsertionSort: %d\nQuickInSort comparisons: QuickSort: %d InsertionSort: %d\nQuickDualPivotSort swaps: QuickSort: %d InsertionSort: %d\nQuickDualPivotSort comparisons: QuickSort: %d InsertionSort: %d\n",c->x1,c->y1,c->x2,c->y2,c->x3,c->y3,c->x4,c->y4);
}
