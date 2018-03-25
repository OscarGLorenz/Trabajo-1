#include <stdio.h>

#define PARAMAX longitud			// Limite de 'entropia global' para ser considerado ordenado ascendente
#define PARAMIN longitud			// Limite de 'entropia global' para ser considerado ordenado descendente
#define PARAMINC longitud			// Limite de 'entropia icremental' para ser considerado relativamente ordenado (posiciones consecutivas son similares)

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

/*
El tipo de orden sera: 
 1: ~ordenado creciente
-1: ~ordenado decreciente
 2: ~consecutivos cercanos
 0: aleatorio
*/

void datafile(int * datos, int longitud){
	char ficheronombre[32]
	FILE * ficherodatos;
	printf("El fichero debe contener un elemento de tipo entero natural en cada fila.");
	prinft("Indique el nombre del fichero, situado en la misma carpeta que el programa: ");
	do {
		scanf("%s",ficherodatos);
		if((ficherodatos = fopen(ficheronombre,"r")) == NULL){
			printf("Error al abrir el archivo. Vuelva a intentarlo: ");
		}
	} while (ficherodatos == NULL);
	
}

void inputdata(int * datos, int longitud){
	int i;
	for(i = 0; i < longitud; i++){
		printf("Introduzca dato %d: ", i+1);
		scanf("%d", datos + i);
	}
}


