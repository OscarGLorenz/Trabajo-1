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

void luckySorter(int * datavector, int datasize){
	char ordertype = orderType(datavector, datasize);
	switch (ordertype){
		case 'a':		// Considerablemente colocados en orden ascendente
			
			break;
		case 'b':		// Considerablemente colocados en orden descendente
			
			break;
		case 'c':		// Considerablemente colocados con pocas inserciones
			
			break;
		case 'd':		// Sin patrón, usar algoritmo equilibrado para cualquier tipo de orden inical
			
			break;
	}
}

void multiSorter(int * datavector, int datasize){
	
}
