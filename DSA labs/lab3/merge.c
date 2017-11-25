#include<stdio.h>
#include<stdlib.h>

void merge(int *a,int *b,int *c,int s1,int s2,int s3){
	if(s1==0){
		int i=0;
		for (i =0;i<s2;i++){
			c[i]=b[i];
		}
	}
	else if(s2==0){
		int i=0;
		for (i =0;i<s1;i++){
			c[i]=a[i];
		}
	}
	else{
		int a1=a[0];
		int b1=b[0];
		if(a1<b1){
			c[0]=a1;
			merge(a+1,b,c+1,s1-1,s2,s3-1);	
		}
		else{
			c[0]=b1;
			merge(a,b+1,c+1,s1,s2-1,s3-1);
		}
	}
	
}

void mergeIn(int *a,int *b,int s1,int s2){
	int i=0,j=s1-1,temp,temp1;
	while(i<s2){
			temp1=b[i];

		while(j>=0){
			if(temp1<=a[j]){
				//printf("%d\n",a[j]);
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
				
			}
			else{	
				break;
			}
			j--;
		}
		
		j=(s1+i);
		i++;	
	}
}
void mergesort(int *arr,int size){
	int j=size;
	if(size!=1){	
		if(size%2==0){		
		mergesort(arr,size/2);
		mergesort(arr+size/2,size/2);
		mergeIn(arr,arr+size/2,size/2,size/2);
		}
		else{
		mergesort(arr,size/2);
		mergesort(arr+size/2,size/2+1);
		mergeIn(arr,arr+size/2,size/2,1+size/2);			
		}
	}
}


int main(int argc,char *argv[]){
	FILE *fp = fopen(argv[1],"r");
	//FILE *fp = stdin;
	int a;
	fscanf(fp,"%d ",&a);
	int arr[a];
	int i=0;
	while(!feof(fp)){
		fscanf(fp,"%d ",&arr[i]);	
		//printf("%d\n\n ",arr[i]);
		i++;
	}
	mergesort(arr,a);
	//mergeIn(arr,arr+a/2,a/2,a/2);
	i=0;
	for(i=0;i<a;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}

