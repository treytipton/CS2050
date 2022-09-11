#include<stdio.h>
#include<stdlib.h>

double * createDoubleArray(int minIndex, int maxIndex); 
void freeArray(int minIndex,double** array);

int main(void){
	int min,max,i;
	double* dArray;
	printf("What is the minIndex? ");
	scanf("%d",&min);
	printf("What is the maxIndex? ");
	scanf("%d",&max);
	max++;
	dArray = createDoubleArray(min,max);
	for(i=min;i<max;i++){
		printf("Index %d of the array is %f\n",i,dArray[i]);
	}
	freeArray(min,&dArray);

}

double * createDoubleArray(int minIndex, int maxIndex){
	int counter, size, i;
	double* array;
	size = maxIndex - minIndex;
	array = malloc(size * sizeof(double));
	array = array-minIndex;
	for(i=minIndex;i<maxIndex;i++){
		array[i]=(double)i*5;
	}
	return array;
}

void freeArray(int minIndex,double** array){
	*array = *array + minIndex;
	free(*array);
	*array = NULL;
}
