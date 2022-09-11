#include<stdio.h>
#include<stdlib.h>

float * readFloatFileIntoArray(FILE *fptr, int *length);
void freeFloatArray(float **fptr);

int main(void){
	FILE * fp;
	int length,i;
	float * pFloat;
	fp = fopen("float.csv","r");
	pFloat = readFloatFileIntoArray(fp,&length);
	if(!pFloat){return 0;}
	printf("Array contains %d elements.\n",length);
	if(pFloat != NULL){
		for(i=0;i<length;i++){
			printf("%d. Element: %.2f\n",i,pFloat[i]);
		}	
	}
	fclose(fp);
	freeFloatArray(&pFloat);
}

float * readFloatFileIntoArray(FILE *fptr, int *length){
	int i=0;
	int cLength=-1;
	float tFloat;
	if(fptr==NULL){
		return NULL;
	}
	while(!feof(fptr)){
		fscanf(fptr,"%f",&tFloat);
		++cLength;
	}
	rewind(fptr);
	float *aFloat;
	aFloat = malloc(cLength * sizeof(float));
	for(i=0;i<cLength;i++){
		fscanf(fptr,"%f",&tFloat);
		aFloat[i] = tFloat;
	} 
	*length = cLength;
	return aFloat;
}

void freeFloatArray(float **fptr){
	free(*fptr);
	*fptr = NULL;
}
