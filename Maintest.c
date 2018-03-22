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
	char dataMode = dataInputMode(&datasize);
	char orderMode = orderInputMode();
	int datavector[datasize];
	switch (dataMode){
		case 'a':
			inputData(datavector, datasize);
			showVector(datavector, datasize);
			break;
		case 'b':
			
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

