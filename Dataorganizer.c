/******************************************************************************
* ARCHIVO :  Dataorganizer.c
*
* DESCRIPCION: Contiene las funciones del modo ORDENADOR
*
* AUTOR :    Mario Musicò Cortés
******************************************************************************/

#include "Benchmark.h"

#include <string.h>
#include <stdlib.h>

#include "Dataorganizer.h"
#include "TUI.h"

void inputData(int* datavector, size_t datasize){
	size_t i;
	printf("\n");
	for(i = 0; i < datasize; i++){
		printf("Introduzca dato %lu: ", i+1);
		scanf("%d", datavector + i);
	}
}

void fileReader(int* datavector, size_t datasize, FILE * datafile){
	size_t i;
	int	aux;
	for (i = 0; i < datasize; i++){
		fscanf(datafile, "%d\n", &aux); 
		datavector[i] = aux;
	}
	fclose(datafile);
}

void filePrinter(int * datavector, size_t datasize, FILE * datafile){
	size_t i;
	fprintf(datafile, "%lu,\n", datasize);
	for (i = 0; i < datasize; i++){
		fprintf(datafile, "%d\n", datavector[i]);
	}
	fclose(datafile);
	printf("Fichero generado con exito.\n");
}	

void dataSaver(int * datavector, size_t datasize, char* input){
	FILE* datafile;
	int i = 0, j = 0;
	char output[FILESIZE];
	char extension[8] = "";
	strcpy(output, input);
	do i++;
	while (output[i]!= '.');
	output[i] = '\0';
	i++;
	do{
		extension[j]=output[i];
		i++; j++;
	} while (output[i]!='\0');
	strcat(output, "_ordenado.");
	strcat(output, extension);
	printf("\nEl archivo de salida con los datos ordenados se llamara \"%s\".\n\n", output);
	
	if ((datafile = fopen(output, "w+")) == NULL){
		printf("Error al crear el archivo.");
	}
	else filePrinter(datavector, datasize, datafile);
	fclose(datafile);
}
	

char**** multiSorter(int * datavector, size_t datasize, algorithm_ptr algorithms[], int n_algorithm, char* filename){
	Experiment experiment;
	int buffer[datasize];
	float millisec;
	int i, k;
	char**** costs = (char****) calloc(n_algorithm, sizeof(char ***));
	for(i = 0; i < n_algorithm; i++){
		printf(".");
		costs[i] = (char ***) calloc(1, sizeof(char**));
		costs[i][0] = (char **) calloc(COSTS, sizeof(char*));
		for (k = 0; k < COSTS; k++){
			costs[i][0][k] = (char *) calloc(NAMESIZE, sizeof(char));
		}
		memcpy(buffer, datavector, datasize * sizeof(datavector));
		experiment = newExperiment(datasize);
		algorithms[i](buffer, datasize, &experiment);
		millisec = nanos(&experiment) / 1000000.0;
		sprintf(costs[i][0][0], "%lu", experiment.comparations);
		sprintf(costs[i][0][1], "%lu", experiment.movements);
		sprintf(costs[i][0][2], "%.3f", millisec);
		for (k = 0; k < COSTS; k++){
			if (strlen(costs[i][0][k]) < 8) strcat(costs[i][0][k], "\t");
		}
	}
	dataSaver(buffer, datasize, filename);
	return costs;
}
