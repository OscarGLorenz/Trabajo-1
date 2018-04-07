#include <stdio.h>

#include "TUI.h"
#include "Datacreator.h"
#include "Dataorganizer.h"
#include "Benchmark.h"

#define SIZES 10, 100, 1000, 10000

void runExperiment(){
	extern Types typestable;
	char mode = experimentMode(&typestable);
	int i, j, l;
	int datasize[] = {SIZES};
	int iterations = sizeof(datasize) / sizeof(int);
	typestable.n_costs = 3;
	algorithm_ptr algorithms[6];
	dataType datatypes[4];
	char **** results;
	switch (mode){
		case 'a':		// En modo automatico, comparar todos los algoritmos con todos los tipos de datos\n
			typestable.n_algorithms = 6;
			typestable.n_data = 4;
			for (i = 0; i < typestable.n_algorithms; i++){
				algorithms[i] = typestable.algorithmTypes[i];
			}
			for (j = 0; j < typestable.n_data; j++){
				datatypes[i] = typestable.dataTypes[i];
			}
			results = calculateTable(datasize, iterations, algorithms, typestable.n_algorithms, typestable.dataTypes, typestable.n_data);
			resultVisualizer(results, typestable);
			break;
		case 'b':		// Comparar la velocidad un algoritmo para diferentes tipos de datos
			algorithmMode(&typestable);
		
			resultVisualizer(results, typestable);
			break;
		case 'c':	;	// Comparar diferentes algoritmos dado un tipo de dato
			dataTypeMode(&typestable);
			
			resultVisualizer(results, typestable);
			break;
	}
}

void runOrganizer(){
	int datasize, orderType;
	FILE * datafile;
	char datamode = dataInputMode();
	char sortermode = sorterInputMode();
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
	switch (sortermode){
		case 'a':
			luckySorter(datavector, datasize);
			break;
		case 'b':
			multiSorter(datavector, datasize);
			break;
	}
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
