/******************************************************************************
* ARCHIVO :  Main.c
*
* DESCRIPCION: Archivo principal del programa. Sintetizado en llamadas a funciones de las librerias
*
* AUTOR :    Mario Musicò Cortés
******************************************************************************/

#include <stdio.h>
#include <string.h>

#include "TUI.h"
#include "Dataorganizer.h"
#include "Algorithm.h"

//****************************************************************************
// Declaración e inicializacion de variables de tipos

// Nombres de los algoritmos a ejecutar
algorithm_ptr algorithmTypes[] = {bubble,insertion,selection,shell,heapsort,quicksort};
// Nombres de los algoritmos a visualizar
char algorithmNames[][16] = {"Burbuja  ", "Insercion", "Seleccion", "Shell    ", "Monticulo", "Quicksort"};
// Número de algoritmos						(i)
int n_algorithms = sizeof(algorithmNames) / sizeof(*algorithmNames);

// Nombres de los tipos de datos a utilizar
dataType dataTypes[] = {INCREASING, DECREASING, RANDOM, REPEATED};
// Nombres de los tipos de datos a visualizar
char dataNames[][16] = {"Creciente", "Decreciente", "Aleatorio", "Repetidos"};
// Número de tipos de datos					(j)
int n_data = sizeof(dataNames) / sizeof(*dataNames);

// Nombres de los costes
char costNames[][16] = {"Comparaciones", "Movimientos  ", "Tiempo       "};
// Número de costes							(k)
int n_costs = sizeof(costNames) / sizeof(*costNames);

// Cantidades de datos con las que se iteran
size_t dataSizes[] = {10, 100, 1000, 10000};
// Número de iteraciones por experimento	(l)
int iterations = sizeof(dataSizes) / sizeof(*dataSizes);

//****************************************************************************

void runExperiment(){
	char mode = experimentMode();
	int i, j;
	
	char run_algorithmID;
	dataType run_dataType;
	
	char **** results;
	switch (mode){
		case 'a':		// En modo automatico, comparar todos los algoritmos con todos los tipos de datos
			results = calculateTable(dataSizes, iterations, algorithmTypes, n_algorithms, dataTypes, n_data);
			resultVisualizer(results, algorithmNames, n_algorithms, dataNames, n_data, costNames, n_costs);
			break;
		case 'b':		// Comparar la velocidad de un algoritmo para diferentes tipos de datos
			n_algorithms = 1;
			run_algorithmID = algorithmMode(algorithmNames);
			results = calculateTable(dataSizes, iterations, &algorithmTypes[run_algorithmID], n_algorithms, dataTypes, n_data);
			resultVisualizer(results, &algorithmNames[run_algorithmID], n_algorithms, dataNames, n_data, costNames, n_costs);
			break;
		case 'c':	;	// Comparar diferentes algoritmos dado un tipo de dato
			n_data = 1;
			run_dataType = dataTypeMode(dataNames);
			results = calculateTable(dataSizes, iterations, algorithmTypes, n_algorithms, &dataTypes[run_dataType], n_data);
			resultVisualizer(results, algorithmNames, n_algorithms, &dataNames[run_dataType], n_data, costNames, n_costs);
			break;
	}
	freeTable(results, n_algorithms, n_data, n_costs);
}

void runOrganizer(){
	int datasize, orderType;
	FILE * datafile;
	char datamode = dataInputMode();
	switch (datamode){
		case 'a':
			printf("\nNumero de elementos que desea introducir: ");
			scanf("%d", &datasize);
			break;
		case 'b':
			datasize = fileOpener(&datafile);
			break;
	}
	int datavector[datasize];
	switch (datamode){
		case 'a':
			inputData(datavector, datasize);
			break;
		case 'b':
			fileReader(datavector, datasize, datafile);
			break;
	}
	multiSorter(datavector, datasize);
}

int main(int argc, char const *argv[]){
	char mode = programMode();
	switch (mode){
		case 'a':
			runExperiment();
			break;
		case 'b':
			runOrganizer();
			break;
	}
	return 0;
}
