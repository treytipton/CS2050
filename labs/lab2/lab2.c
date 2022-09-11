#include "lab2.h"

int * makeArray(int size );
void fillFives(int * array , int size );
void freeArray(int ** array);

int * makeArray(int size){//This function just makes an array, fills it with zeros and then returns a pointer to the array.
	int* array;
	int i;
	if(size == 0){return NULL;}
	array = malloc(size*sizeof(int));
	for(i=0;i<size;i++){
		array[i]=0;
	}
	return array;
}

void fillFives(int *array, int size){//this function just fills the previous array we created with multiples of five.
	int i;
	for(i=0;i<size;i++){
		array[i] = i*5;
	}
}

void freeArray(int **array){//This function frees the memory we allocated for the array we created earlier and sets the pointer to NULL so that the user knows we're done using the array.
	free(*array);
	*array = NULL;
}
