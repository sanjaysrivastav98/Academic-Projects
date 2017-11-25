#include<assert.h>
#include "pivot.h"


int pivot(double* ls,int lo,int hi){
	return (int)rand()/(int)RAND_MAX * (hi - lo) + lo;
}
