#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Datacreator.h"

#define PARAMAX longitud			// Limite de 'entropia global' para ser considerado ordenado ascendente
#define PARAMIN longitud			// Limite de 'entropia global' para ser considerado ordenado descendente
#define PARAMINC longitud			// Limite de 'entropia icremental' para ser considerado relativamente ordenado (posiciones consecutivas son similares)

void swap(int * a, int * b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

int distancia(int a, int b){
	int dist = a - b;
	return dist < 0 ? - dist : dist;
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

void inputdata(int * datos, int longitud){
	int i;
	for(i = 0; i < longitud; i++){
		printf("Introduzca dato %d: ", i+1);
		scanf("%d", datos + i);
	}
}

double maxorder(int longitud){
	int i, factor = 0;
	for(i = 1; i <= longitud; i++){
		factor += i * i;
	}
	return factor;
}

double minorder(int longitud){
	int i, factor = 0;
	for(i = 1; i <= longitud; i++){
		factor += i * (longitud - i + 1);
	}
	return factor;
}

int incremental(int * datos, int longitud){
	int i;
	double entropia = 0;
	for(i = 0; i < longitud - 1; i++){
		entropia += distancia(datos[i], datos[i+1]);
	}
	if (entropia < PARAMINC) return 2;
	return 0;
}

int order(int * datos, int longitud){
	int i; 
	double entropia = 0;
	const double ordenmax = maxorder(longitud), inversmax = minorder(longitud);
	for(i = 0; i < longitud; i++){
		entropia += datos[i] * (i + 1);
	}
	if (ordenmax - entropia < PARAMAX) return 1;
	if (entropia - inversmax < PARAMIN) return -1;
	return incremental(datos, longitud);
}

/*
El tipo de orden sera: 
 1: ~ordenado creciente
-1: ~ordenado decreciente
 2: ~consecutivos cercanos
 0: aleatorio
*/

int datacreator(datamode modo, int * datos, int longitud){
	int orden = 0;
	startvector(datos, longitud, 1);
	
	switch(modo){
		case CRECIENTE:
			break;
		case DECRECIENTE: 
			invertvector(datos, longitud);
			break;
		case DESORDENADO:
			randomize(datos, longitud);
			break;
		case REPETIDOS:
			duplicate(datos, longitud);
			break;
		case USUARIO:
			inputdata(datos, longitud);
			orden = order(datos, longitud);
			printf("\n\nTipo de orden: %d\n", orden);
			break;
	}
	return orden;
}


