#include "lab1.h"
#include<stdio.h>

int getmax(int size, int *array, int *result);

int getMax(int size , int *array , int *result){
//This function goes through each element in the array and compares them with the highest value that the function has found so far.
//If if finds a element that is higher than it's current one it replaces it.
//Before it does anything though it checks and makes sure that 1. The array pointer is not NULL and that the array size is at least one.
        if(array==NULL || size<1){
                return -1;
        }
        *result = array[0];
        for(int i=0;i<size;i++){
                if(array[i] > *result){
                	*result = array[i];
		}
        }
	return 0;

}

