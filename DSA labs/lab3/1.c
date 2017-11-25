#include <stdio.h>
#include <stdlib.h>

int main(){
	int count=1;
	int *a = (int*)malloc(count*sizeof(int));
	while(a){
		count*=2;	
		a=(int*)malloc(count*sizeof(int));
	}
	printf("%d\n",count);
	free(a);
}
