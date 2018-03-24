#include <stdio.h>
#include "Dataorganizer.h"
#include "Lucky.h"

void inputData(int * datavector, int datasize){
	int i;
	int data[datasize];
	printf("\n");
	for(i = 0; i < datasize; i++){
		printf("Introduzca dato %d: ", i+1);
		scanf("%d", datavector + i);
	}
}

void fileReader(int * datavector, int datasize, FILE * datafile){
	int i, aux;
	for (i = 0; i < datasize; i++){
		fscanf(datafile, "%d\n", &aux); 
		datavector[i] = aux;
	}
	fclose(datafile);
}

void dataSorter(int * datavector, int datasize, char ordermode){
	switch (ordermode){
		case 'a':
			
			break;
		case 'b':
			
			break;
	}
}
