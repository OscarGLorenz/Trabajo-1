#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Datacreator.h"

void swap(int * a, int * b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

void startVector(int * datavector, int datasize, int dataspacing){
	int i;
	srand(clock());
	datavector[0] = 1 + dataspacing * (rand() % datasize);
	if(datasize > 1){
		for (i = 1; i < datasize; i++){
			datavector[i] = datavector[i - 1] + 1 + dataspacing * (rand() % datasize);
		}
	}
}

void invertVector(int * datavector, int datasize){
	int i, j;
	for (i = 0, j = datasize - 1; i < j; i++, j--){
		swap(datavector + i, datavector + j);
	}
}

void randomize(int * datavector, int datasize){
	int i, j;
	srand(clock());
	for(j = 0; j < datasize; j++){
		for(i=0; i < datasize; i++){
			swap(datavector + i, datavector + (rand() % datasize));
		}
	}
}

void duplicate(int * datavector, int datasize){
	int i, j;
	srand(clock());
	j = rand() % datasize;
	if (j < 2) j = 2;
	for(i = 0; i < j; i++){
		*(datavector + rand()%datasize) = *(datavector + rand()%datasize);
	}
}

void dataCreator(int * datavector, int datasize, datamode dataorder, int dataspacing){
	startVector(datavector, datasize, dataspacing);
	switch(dataorder){
		case CRECIENTE:
			break;
		case DECRECIENTE: 
			invertVector(datavector, datasize);
			break;
		case DESORDENADO:
			randomize(datavector, datasize);
			break;
		case REPETIDOS:
			randomize(datavector, datasize);
			duplicate(datavector, datasize);
			break;
	}
}

