#include <stdio.h>
#include <string.h>
#include <math.h>

#include "TUI.h"
#include "Datacreator.h"
#include "Dataorganizer.h"
#include "Benchmark.h"
#include "Algorithm.h"
#include "Cost.h"

void runExperiment(){
	char mode = experimentMode();
	switch (mode){
		case 'a':		// En modo automatico, comparar todos los algoritmos con todos los tipos de datos\n
			break;
		case 'b':		// Comparar la velocidad un algoritmo para diferentes tipos de datos

			break;
		case 'c':	;	// Comparar diferentes algoritmos dado un tipo de dato

			int iter = 4;
			Experiment bubbleS[iter], insert[iter], select[iter], heap[iter], shell[iter], quick[iter];

			for (size_t i = 0; i < iter; i++) {
				size_t nelem = pow(10,1+i);
				unsigned int random[nelem];
				unsigned int buffer[nelem];

				startVector(random, nelem,'a');
				randomize(random,nelem);

				memcpy(buffer,random,nelem);
				bubbleS[i] = newExperiment(nelem);
				bubble(buffer, nelem, &bubbleS[i]);

				memcpy(buffer,random,nelem);
				insert[i] = newExperiment(nelem);
				insertion(buffer,nelem,&insert[i]);

				memcpy(buffer,random,nelem);
				select[i] = newExperiment(nelem);
				selection(buffer,nelem,&select[i]);


			}
			printf("Algo Moves Comps Time\n");;
			char comp_str[40], move_str[40], nanos_str[40];

			comp_str[0] = '\0'; move_str[0] = '\0'; nanos_str[0] = '\0';
			costIdentification(bubbleS, iter, move_str, comp_str, nanos_str);
			printf("Bubble: %s  %s  %s\n", move_str, comp_str, nanos_str);

			comp_str[0] = '\0'; move_str[0] = '\0'; nanos_str[0] = '\0';
			costIdentification(insert, iter, move_str, comp_str, nanos_str);
			printf("Insert: %s  %s  %s\n", move_str, comp_str, nanos_str);

			comp_str[0] = '\0'; move_str[0] = '\0'; nanos_str[0] = '\0';
			costIdentification(select, iter, move_str, comp_str, nanos_str);
			printf("Select: %s  %s  %s\n", move_str, comp_str, nanos_str);
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
