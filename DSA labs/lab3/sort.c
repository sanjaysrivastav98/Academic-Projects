#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void verify(int p, int n,FILE *fp){
//	int i=0;
//	int a;
//	for(i=p+1;i<p+n+1;i++){
//		fscanf(fp,"%d ",&a);
//		printf("%d\n",a);	
//	}
//}
void merge(FILE *fp1,FILE *fp2,int i){
	int a;
	int b,flag=0,flag1=0;
	char s[7];
	sprintf(s,"%d",i);
	strcat(s,".txt");
	fscanf(fp1,"%d",&a);
	fscanf(fp2,"%d",&b);
	FILE *tmp = fopen("101.txt","w");
	while(!feof(fp1)&&!feof(fp2)){
		if(a>b){
			fprintf(tmp,"%d\n",b);
			fscanf(fp2, "%d ",&b);
		}
		else{
			fprintf(tmp,"%d\n",a);
			fscanf(fp1, "%d ",&a);
		}
	}
	if(feof(fp1)){
		while(!feof(fp2)){
			if(a<b&&flag==0){
			fprintf(tmp,"%d\n",a);flag=1;}
			fprintf(tmp,"%d\n",b);
			fscanf(fp2, "%d ",&b);		
		}
		if(flag!=0){
		fprintf(tmp,"%d\n",b);}
		else{
			if(a>b){
				fprintf(tmp,"%d\n",b);
				fprintf(tmp,"%d\n",a);
			}	
			else{
				fprintf(tmp,"%d\n",a);
				fprintf(tmp,"%d\n",b);
			}
			
		}
	}
	else if(feof(fp2)){
		while(!feof(fp1)){
			if(a>b&&flag1==0){
			fprintf(tmp,"%d\n",b);flag1=1;}
			fprintf(tmp,"%d\n",a);
			fscanf(fp1, "%d ",&a);		
		}
		if(flag1!=0){
		fprintf(tmp,"%d\n",a);}
		else{
			if(a>b){
				fprintf(tmp,"%d\n",b);
				fprintf(tmp,"%d\n",a);			
			}	
			else{
				fprintf(tmp,"%d\n",a);
				fprintf(tmp,"%d\n",b);
			}			
		}
	}
	else{
		if(a>b){
			fprintf(tmp,"%d\n",b);
			fprintf(tmp,"%d\n",a);			
		}	
		else{
			fprintf(tmp,"%d\n",a);
			fprintf(tmp,"%d\n",b);
		}
	}
	//fclose(fp1);
	fclose(tmp);
	tmp= fopen("101.txt","r");
	fp1=fopen(s,"w");
	int j=0;
	while(!feof(tmp)){
		fscanf(tmp, "%d ",&j);
		fprintf(fp1,"%d\n",j);	
	}
	fclose(fp1);
	fclose(fp2);	
	fclose(tmp);
}

int main(){
	FILE *fp = fopen("input.txt","r+");
	int i=0;
	char s[7];	
	while(i<100){
		int j=0;
		int a,b[10000];
		sprintf(s,"%d",i);
		strcat(s,".txt");
		FILE *fp1=fopen(s,"w+");
		while(j<10000){
			fscanf(fp, "%d",&a);
			b[j]=a;	
			fprintf(fp1,"%d\n",a);		
			j++;
		}	
		i++;
		int k=0,l=0,sm=0,tm;	
		for(k=0;k<10000;k++){
			sm=k;
			for(l=k+1;l<10000;l++){
				if(b[sm]>b[l]){
					sm=l;	
				}				
			}
			tm=b[sm];
			b[sm]=b[k];
			b[k]=tm;
					
		}
		
		fclose(fp1);
		fp1 =fopen(s,"w+");
		for(k=0;k<10000;k++){
			fprintf(fp1,"%d\n",b[k]);		
		}
		fclose(fp1);
		
	}
	fclose(fp);
	i=0;
	int k=0;
	FILE *fp1= fopen("1.txt","r");
	char d[7];
	int n=100;
	while(n!=0&&n!=1){
		i=0;

		if(n%2==0){
			k=n/2;
		}
		else{
			k=n/2+1;		
		}		
		while(i<n/2){
			int a,b[10000];
			sprintf(s,"%d",i);
			sprintf(d,"%d",n-i-1);
			strcat(s,".txt");
			strcat(d,".txt");
			fp= fopen(s,"r");
			fp1=fopen(d,"r");
			merge(fp,fp1,i);
			i++;
			//fclose(fp);
			//fclose(fp1);
		}
		n=k;
		//printf("%d\n",n);
	}

	return 0;
}

