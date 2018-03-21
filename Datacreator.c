#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Datacreator.h"

#define STARTMODE 1					// modo: 0 = consecutivos; 1 = incremento aleatorio para datos generados automáticamente

void swap(int * a, int * b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

void startvector(int * datos, int longitud, int modo){
	int i;
	srand(clock());
	datos[0] = 1 + modo * (rand() % longitud);
	if(longitud > 1){
		for (i = 1; i < longitud; i++){
			datos[i] = datos[i - 1] + 1 + modo * (rand() % longitud);
		}
	}
}

void invertvector(int * datos, int longitud){
	int i, j;
	for (i = 0, j = longitud - 1; i < j; i++, j--){
		swap(datos + i, datos + j);
	}
}

void randomize(int * datos, int longitud){
	int i, j;
	srand(clock());
	for(j = 0; j < longitud; j++){
		for(i=0; i < longitud; i++){
			swap(datos + i, datos + (rand() % longitud));
		}
	}
}

void duplicate(int * datos, int longitud){
	int i, j;
	srand(clock());
	j = rand() % longitud;
	if (j < 2) j = 2;
	for(i = 0; i < j; i++){
		*(datos + rand()%longitud) = *(datos + rand()%longitud);
	}
}

void datacreator(datamode modo, int * datos, int longitud){
	switch(modo){
		case CRECIENTE:
			startvector(datos, longitud, STARTMODE);
			break;
		case DECRECIENTE: 
			startvector(datos, longitud, STARTMODE);
			invertvector(datos, longitud);
			break;
		case DESORDENADO:
			startvector(datos, longitud, STARTMODE);
			randomize(datos, longitud);
			break;
		case REPETIDOS:
			startvector(datos, longitud, STARTMODE);
			duplicate(datos, longitud);
			break;
	}
}


