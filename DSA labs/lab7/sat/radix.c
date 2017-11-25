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


char** keyIndex(char** A,int l,int h,int d,int w){
	int i=0,f,k=0,j;
	char ref='a';
	char ** s=(char**)malloc((h-l+1)*sizeof(char*));
	for(i=0;i<(h-l+1);i++)
		s[i]=(char*)malloc(w*sizeof(char));
	int* a=(int*)malloc(26*sizeof(int));
	int* b=(int*)malloc(26*sizeof(int));

	//s[0]=A[0];
	f=A[0][d]-ref;
	for(i=0;i<(h-l+1);i++){
		//s[i]=A[i][d];
		a[A[i][d]-ref]++;
		//printf("%c     %d      %d\n",s[i],s[i]-ref,a[s[i]-ref]);
		if(f>A[i][d]-ref){
			f=A[i][d]-ref;
		}
	}
	//printf("\n");
	int temp=0;
	for(i=0;i<26;i++){
		if(a[i]>0){
			temp+=a[i];
			b[i]=temp;
			//printf("%c     %d      %d\n",i+ref,i+ref,b[i]);
			
		}
	}
	for(i=0;i<26;i++){
		if(a[i]>0){
			for(j=0;j<(h-l+1);j++){
				if(A[j][d]==i+ref){
					s[k]=A[j];
					k++;
				}
			}
		}
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

char** lsdRadixSort(char **A,int l,int h,int w){
	int i=0,j=0,f,k,d=0;
	//char ref='a';

	char** g = (char**)malloc((h-l+1)*sizeof(char*));
	// char * s;
	// int* a=(int*)malloc(26*sizeof(int));
	// int* b=(int*)malloc(26*sizeof(int));
	for(i=0;i<h-l+1;i++){
		g[i]=(char*)malloc(w*sizeof(char));
		//s[i]=(char*)malloc(w*sizeof(char));
		for(j=0;j<w;j++){
			g[i][j]=A[i][j];
		}
	}
	for(d=w-1;d>=0;d--){
		
		g=keyIndex(g,l,h,d,w);
	}
	return g;
	// 	//for(j=0;j<(h-l+1);j++){
	// //printf("%c\n",s[j]);
	// 	//}
	// 	for(i=0;i<(h-l+1);i++){
	// 		a[i]=0;
	// 	}
	// 	for(i=0;i<(h-l+1);i++){
	// 		a[A[i][d]-ref]++;
		
	// 		if(f>A[i][d]-ref){
	// 			f=A[i][d]-ref;
	// 		}
	// 	}
	// 	for(i=0;i<(h-l+1);i++){
	// 		if(g[i][d]!=s[i]||a[g[i][d]-ref]%2==0){
	// 			for(j=i;j<(h-l+1);j++){
	// 				if(g[j][d]==s[i] ){
	// 					swap(g[i],g[j],w);
	// 					//a[g[i][d]-ref]--;
	// 				}
					
					
	// 			}
	// 		}
	// 	//	printf("%s\n",g[i]);
	// 	}
	// 	//printf("\n");
	// }
	// for(i=0;i<h-l+1;i++){
	// 	printf("%s\n",g[i]);
	// }


}

