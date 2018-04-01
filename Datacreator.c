#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Datacreator.h"

// Conmuta 2 variables proporcionadas por referencia
static void swap(int * a, int * b){
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
		swap(datavector + i, datavector + j);
	}
}

// Aleatoriza un array dado realizando tantas pasadas de swaps como su tama�o
static void randomize(int * datavector, int datasize){
	int i, j;
	srand(clock());
	for(j = 0; j < datasize; j++){
		for(i=0; i < datasize; i++){
			swap(datavector + i, datavector + (rand() % datasize));
		}
	}
}

// Modifica array en un numero aleatorio de posiciones, duplicando posiciones tambi�n aleatorias
static void duplicate(int * datavector, int datasize){
	int i, j;
	srand(clock());
	j = rand() % datasize;
	if (j < 2) j = 2;
	for(i = 0; i < j; i++){
		*(datavector + rand()%datasize) = *(datavector + rand()%datasize);
	}
}

void dataCreator(int * datavector, int datasize, int dataType, int dataspacing){
	startVector(datavector, datasize, dataspacing);
	switch(dataorder){
		case 0:
			break;
		case 1:
			invertVector(datavector, datasize);
			break;
		case 2:
			randomize(datavector, datasize);
			break;
		case 3:
			randomize(datavector, datasize);
			duplicate(datavector, datasize);
			break;
	}
}
