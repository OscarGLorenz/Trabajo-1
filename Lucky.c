#include <stdio.h>
#include "Lucky.h"

// Calcula el incremento de valor entre dos posiciones consecutivas
static int distance(int a, int b){
	int dist = a - b;
	return dist < 0 ? - dist : dist;
}

// Calcula la 'entropia global' en el caso de mayor orden ascendente
static double maxorder(int datasize){
	int i, factor = 0;
	for(i = 1; i <= datasize; i++){
		factor += i * i;
	}
	return factor;
}

// Calcula la 'entropia global' en el caso de mayor orden descendente
static double minorder(int datasize){
	int i, factor = 0;
	for(i = 1; i <= datasize; i++){
		factor += i * (datasize - i + 1);
	}
	return factor;
}

// Calcula la 'entropia incremental' del array, segun la distancia entre valores de posiciones consecutivas
static char incremental(int * datavector, int datasize){
	int i;
	double entropy = 0;
	for(i = 0; i < datasize - 1; i++){
		entropy += distance(datavector[i], datavector[i+1]);
	}
	if (entropy < PARAMINC) return 'c';
	return 'd';
}

// Calcula el 'tipo de orden' segun la 'entropia global' y 'entropia incremental'
char orderType(int * datavector, int datasize){
	int i; 
	double entropy = 0;
	const double ordenmax = maxorder(datasize);
	const double inversmax = minorder(datasize);
	for(i = 0; i < datasize; i++){
		entropy += datavector[i] * (i + 1);
	}
	if (ordenmax - entropy < PARAMAX) return 'a';
	if (entropy - inversmax < PARAMIN) return 'b';
	return incremental(datavector, datasize);
}


