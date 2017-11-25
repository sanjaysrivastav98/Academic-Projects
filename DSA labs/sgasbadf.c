#include <stdio.h>

int main()
{
    // Declare the variable
    int n,m,f=0,count=0,z=0;
    scanf("%d",&n);
    scanf("%d",&m);
    int x[m],y[m],freq[m];
    int i,j;
    for(i=0;i<m;i++){
        freq[i]=0;
    }
    for(i=0;i<m;i++){
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
        freq[x[i]-1]++;
        freq[y[i]-1]++;
    }
    for(i=0;i<n;i++){
            if(freq[i]==2){
                f=0;
                printf("%d--f%d\n",f,count);
            }
            else if(freq[i]==1){
                count++;
                printf("%d\n",count);
            }
            else if(freq[i]==0){
                break;
            }
            else {
                f=1;
                break;
            }
    }
    
    if(f==0&& count==0){
        printf("ring topology\n");z=1;
        //return 0;
    }
    else if(f==0&& count==2){
        printf("line topology\n");z=1;
        //return 0;
    }
    else {
         for(i=0;i<m;i++){
            if(freq[i]==m){
                printf("star topology\n");z=1;
            //return 0;
            }
        }
    }
    if(z==0)
    printf("unknown topology\n");
    return 0;
}
