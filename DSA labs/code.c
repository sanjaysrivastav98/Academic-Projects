#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int mypow(int a,int b){
  int i=0,res=1;
  for(i=0;i<b;i++){
    res*=a;
  }
  return res;
}
int main()
{
   FILE *f=stdin;
   int B;
   int T,i,j,K,*m,res,x;
   char s[100];
   char c;
   fscanf(f,"%d",&T);
   for(i=0;i<T;i++){

       fscanf(f,"%d",&K);
       fscanf(f,"%d",&B);
       m=(int*)malloc(K*sizeof(int));
       for(j=0;j<K;j++){
          fscanf(f,"%d",&m[j]);
        }
       for(j=0;j<K;j++){
           if(j!=0){
                fscanf(f,"%c",&c);

                if(c=='\n'){
                break;
                }
                printf("+");
           }
          //printf("fdvhgfgdfasv\n");

           fscanf(f,"%s",s);
            //printf("fdasv\n");

           res=0;
           for(x=0;x<strlen(s);x++){
               res+=((int)s[x]-(int)'a'+1)*mypow(B,m[x]);
               
           }
          printf("%d",res);
          
        }
        printf("\n");
       
       
   }
   fclose(f);
   return 0;
}
