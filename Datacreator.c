#include <stdio.h>
#include <stdlib.h>
#include "Datacreator.h"

//	Conmuta 2 variables proporcionadas por referencia
static void swap2(int * a, int * b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

// Rellena el array de datos con valores ascendentes; dataspacing: 0 = consecutivos; 1 = incremento aleatorio
static void startVector(int * datavector, int datasize, int dataspacing){
	int i;
	srand(clock());
	datavector[0] = 1 + dataspacing * (rand() % datasize);
	if(datasize > 1){
		for (i = 1; i < datasize; i++){
			datavector[i] = datavector[i - 1] + 1 + dataspacing * (rand() % datasize);
		}
	}
}

// Invierte el orden de un array
static void invertVector(int * datavector, int datasize){
	int i, j;
	for (i = 0, j = datasize - 1; i < j; i++, j--){
		swap2(datavector + i, datavector + j);
	}
}

// Aleatoriza un array dado realizando tantas pasadas de swaps como su tamaño
static void randomize(int * datavector, int datasize){
	int i, j;
	srand(clock());
	for(j = 0; j < datasize; j++){
		for(i=0; i < datasize; i++){
			swap2(datavector + i, datavector + (rand() % datasize));
		}
	}
}

// Modifica array en un numero aleatorio de posiciones, duplicando posiciones también aleatorias
static void duplicate(int * datavector, int datasize){
	int i, j;
	srand(clock());
	j = rand() % datasize;
	if (j < 2) j = 2;
	for(i = 0; i < j; i++){
		*(datavector + rand()%datasize) = *(datavector + rand()%datasize);
	}
}

// Crea el array de datos del tipo solicitado. dataType, dataspacing: 0 = consecutivos; 1 = incremento aleatorio
void dataCreator(int * datavector, int datasize, dataType dataorder, int dataspacing){
	startVector(datavector, datasize, dataspacing);
	switch(dataorder){
		case INCREASING:
			break;
		case DECREASING:
			invertVector(datavector, datasize);
			break;
		case RANDOM:
			randomize(datavector, datasize);
			break;
		case REPEATED:
			randomize(datavector, datasize);
			duplicate(datavector, datasize);
			break;
	}
}
