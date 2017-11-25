#include<stdio.h>
#include<stdlib.h>


void merge(FILE *fp1,FILE *fp2,FILE *fp){
	int a;
	int b;
	fscanf(fp1,"%d",&a);
	fscanf(fp2,"%d",&b);
	if (a>b){
		fprintf(fp,"%d",b);
		FILE *fp3=fopen("1.txt","r+");
		while(!feof(fp1)){
			fprintf(fp3,"%d",a);
			fscanf(fp1,"%d",&a);		
		}
		fprintf(fp3,"%d",a);
		fclose(fp3);
		FILE *fp4=fopen("1.txt","r+");		
		merge(fp4,fp2,fp);
	}
	else{
		fprintf(fp,"%d",a);
		FILE *fp3=fopen("1.txt","r+");
		while(!feof(fp1)){
			fprintf(fp3,"%d",b);
			fscanf(fp2,"%d",&b);		
		}
		fprintf(fp3,"%d",b);
		fclose(fp3);
		FILE *fp4=fopen("1.txt","r+");
		merge(fp1,fp4,fp);		
	}
}

FILE* sort(FILE *fp,int size){
	if(size=2){
		int a,b;
		fscanf(fp,"%d",&a);
		fscanf(fp,"%d",&b);
		if(b>a){
			return fp;
		}
		else{
			FILE *fp1=fopen("1.txt","w+");
			fprintf(fp1,"%d",a);
			fprintf(fp1,"%d",b);		
			return fp1;		
		}		
	}
	else if(size==1){
		return fp;
	}
	else if(size%2==0){
		FILE *fp1= fopen("1.txt","w+");
		FILE *fp2= fopen("2.txt","w+");
		size/=2;
		int i=0;
		int a;
		while(i<size){
			fscanf(fp,"%d",&a);
			fprintf(fp1,"%d",a);
			i++;		
		}	
		while(i<2*size){
			fscanf(fp,"%d",&a);
			fprintf(fp2,"%d",a);		
			i++;		
		}
		FILE *fp3 = fopen("3.txt","w+");
		merge(sort(fp1,size),sort(fp2,size),fp3);
		return fp3;	
	}
	else{
		FILE *fp1=fopen("1.txt","w+");
		FILE *fp2 = fopen("2.txt","w+");
		int i=0;
		int a;
		while(i<size/2){
			fscanf(fp,"%d",&a);
			fprintf(fp1,"%d",a);
			i++;		
		}
		while(i<size){
			fscanf(fp,"%d",&a);
			fprintf(fp2,"%d",a);		
			i++;		
		}
		FILE *fp3 = fopen("3.txt","w+");
		merge(sort(fp1,size/2),sort(fp2,size/2+1),fp3);		
		return fp3;	
	}
}


int main(){
	FILE *fp = fopen("input.txt","r+");
	FILE *fp1=fopen("output.txt","w+");
	fp1=sort(fp,1000000);
	return 0;
	
}
