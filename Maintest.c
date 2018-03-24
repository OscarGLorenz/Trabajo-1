#include <stdio.h>
#include "TUI.h"
#include "Datacreator.h"
#include "Dataorganizer.h"

void runExperiment(){
	char mode = experimentMode();
	switch (mode){
		case 'a':		// En modo automatico, comparar todos los algoritmos con todos los tipos de datos\n
			
			break;
		case 'b':		// Comparar la velocidad un algoritmo para diferentes tipos de datos
			
			break;
		case 'c':		// Comparar diferentes algoritmos dado un tipo de dato
			
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

