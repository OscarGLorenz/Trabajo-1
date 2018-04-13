#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Dataorganizer.h"

#define NAMESIZE 16

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

char**** multiSorter(int datasize, int * datavector, algorithm_ptr algorithms[], int n_algorithm, int n_costs){
	Experiment experiment;
	int buffer[datasize];
	char**** costs = (char****) calloc(n_algorithm, sizeof(char ***));
	for(int i = 0; i < n_algorithm; i++){
		printf("\nHola1\n");
		costs[i] = (char ***) calloc(1, sizeof(char**));
		costs[i][0] = (char **) calloc(n_costs, sizeof(char*));
		for (int k = 0; k < n_costs; k++){
			printf("\nHola2\n");
			costs[i][0][k] = (char *) calloc(NAMESIZE, sizeof(char));
			printf("\nHola2b\n");

		}
		printf("\nHola3\n");
		memcpy(buffer, datavector, datasize * sizeof(datavector));
		experiment = newExperiment(datasize);
		algorithms[i](buffer, datasize, &experiment);
	}
	return costs;
}
