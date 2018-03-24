#include <stdio.h>
#include "TUI.h"
#include "Datacreator.h"
#include "Dataorganizer.h"

#define MUESTRAMAX 6		//Para el modo experimento, se generarán vectores de datos a ordenar de tamaño 10^n, con n = 1..MUESTRAMAX

void runExperiment(){
	char mode = experimentMode();
	switch (mode){
		case 'a':
			
			break;
		case 'b':
			
			break;
		case 'c':
			
			break;
	}
}

void runOrganizer(){
	int datasize;
	FILE * datafile;
	char datamode = dataInputMode();
	char ordermode = orderInputMode();
	switch (datamode){
		case 'a':
			printf("\nNumero de elementos que desea introducir: ");
			scanf("%d", &datasize);
				printf("\nHola\n");
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
	dataSorter(datavector, datasize, ordermode);
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

