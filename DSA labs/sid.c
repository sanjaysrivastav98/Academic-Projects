#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char s;
    int t;
}node; 

int toggle(int a){
    if(a==0)
        return 1;
    else
        return 0;
}



int main()
{
    
    FILE *f =stdin;
    int n,q,l,r,i,j,x,count,z;
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&q);
    node *a=(node *)malloc(n*sizeof(node));
    char *s=(char*)malloc((n+1)*sizeof(char));
    fscanf(f," %s",s);
    for(i=0;i<n;i++){
        a[i].s=s[i];
        a[i].t=0;
    }
    char c;
    char *p=(char*)malloc(5*sizeof(char));
    for(i=0;i<q;i++){
        fscanf(f,"%d",&x);
        //printf("%d--var\n",x);
        switch(x)
        {
            case 1:
                fscanf(f," %c",&c);
                //printf("%c----%d----c and var\n",c,x);
                for(j=0;j<n;j++){
                    if(a[j].s==c)
                        a[j].t=toggle(a[j].t);
                }
                break;
            case 2:
                fscanf(f,"%d",&l);
                fscanf(f,"%d",&r);
                fscanf(f," %s",p);
                //printf("%d---l  %d----r   %s----p\n",l,r,p);
                z=strlen(p)==2;
                //printf("%s  %d",p,p=="on");
                count=0;
                for(j=l-1;j<r;j++){
                    //printf("%d---a[j].t   %d\n",a[j].t,z);
                    if(a[j].t==z)
                        count++;
                }
                printf("%d\n",count);
                break;
        }

    }
    fclose(f);
    
    return 0;
}