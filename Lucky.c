#include <stdio.h>
#include "Lucky.h"

int distancia(int a, int b){
	int dist = a - b;
	return dist < 0 ? - dist : dist;
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

