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


intPair keyIndex(char** A,int l,int h,int d,int w){
	int i=0,f,k=0,j;
	char ref='X';
	char ** s=(char**)malloc((h-l+1)*sizeof(char*));
	for(i=0;i<(h-l+1);i++)
		s[i]=(char*)malloc(w*sizeof(char));
	int* a=(int*)malloc(3*sizeof(int));
	int* b=(int*)malloc(3*sizeof(int));

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
	for(i=0;i<3;i++){
		if(a[i]>0){
			temp+=a[i];
			b[i]=temp;
			//printf("%c     %d      %d\n",i+ref,i+ref,b[i]);
			
		}
	}
	for(i=0;i<3;i++){
		if(a[i]>0){
			for(j=0;j<(h-l+1);j++){
				if(A[j][d]==i+ref){
					s[k]=A[j];
					k++;
				}
			}
		}
	}
	for(i=0;i<h-l+1;i++){
		for(j=0;j<w;j++){
			A[i][j]=s[i][j];
		}
	}
	intPair x;
	x.i=l;
	x.j=h;
	return x; 
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

void lsdRadixSort(char **A,int l,int h,int w){
	int i=0,j=0,f,k,d=0;
	//char ref='a';

	for(d=w-1;d>=0;d--){
		
		keyIndex(A,l,h,d,w);
	}
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

