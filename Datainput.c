#include <stdio.h>

#define PARAMAX longitud			// Limite de 'entropia global' para ser considerado ordenado ascendente
#define PARAMIN longitud			// Limite de 'entropia global' para ser considerado ordenado descendente
#define PARAMINC longitud			// Limite de 'entropia icremental' para ser considerado relativamente ordenado (posiciones consecutivas son similares)

void swap(int * a, int * b) {		// Conmuta 2 variables proporcionadas por referencia
  int aux = *a;
  *a = *b;
  *b = aux;
}

int distancia(int a, int b){		// Calcula el incremento entre 2 elementos consecutivos, para el calculo de la 'entropia incremental'
	int dist = a - b;
	return dist < 0 ? - dist : dist;
}

void showvector(int * datos, int longitud){		// Visualiza el array de datos
	int i;
	for (i = 0; i < longitud; i++){
		printf("%d ", datos[i]);
	}
	printf("\n");
}

void startvector(int * datos, int longitud, int modo){		// Rellena el array de datos con valores ascendentes; modo: 0 = consecutivos; 1 = incremento aleatorio
	int i;
	srand(clock());
	datos[0] = 1 + modo * (rand() % longitud);
	if(longitud > 1){
		for (i = 1; i < longitud; i++){
			datos[i] = datos[i - 1] + 1 + modo * (rand() % longitud);
		}
	}
}

void invertvector(int * datos, int longitud){		// Invierte el orden de un array
	int i, j;
	for (i = 0, j = longitud - 1; i < j; i++, j--){
		swap(datos + i, datos + j);
	}
}

void randomize(int * datos, int longitud){			// Aleatoriza un array dado realizando tantas pasadas de swaps como su tamaño, para mayor aleatorizacion
	int i, j;
	srand(clock());
	for(j = 0; j < longitud; j++){
		for(i=0; i < longitud; i++){
			swap(datos + i, datos + (rand() % longitud));
		}
	}
}

void duplicate(int * datos, int longitud){			// Modifica array en un numero aleatorio de posiciones, duplicando posiciones también aleatorias
	int i, j;
	srand(clock());
	j = rand() % longitud;
	if (j < 2) j = 2;
	for(i = 0; i < j; i++){
		*(datos + rand()%longitud) = *(datos + rand()%longitud);
	}
}

void inputdata(int * datos, int longitud){			// Permite al usuario introducir los valores del array, dada su longitud previamente
	int i;
	for(i = 0; i < longitud; i++){
		printf("Introduzca dato %d: ", i+1);
		scanf("%d", datos + i);
	}
}

double maxorder(int longitud){			// Calcula la 'entropia global' en el caso de mayor orden ascendente
	int i, factor = 0;
	for(i = 1; i <= longitud; i++){
		factor += i * i;
	}
	return factor;
}

double minorder(int longitud){			// Calcula la 'entropia global' en el caso de mayor orden descendente
	int i, factor = 0;
	for(i = 1; i <= longitud; i++){
		factor += i * (longitud - i + 1);
	}
	return factor;
}

int incremental(int * datos, int longitud){			// Calcula la 'entropia incremental' del array, segun la distancia entre valores de posiciones consecutivas
	int i;
	double entropia = 0;
	for(i = 0; i < longitud - 1; i++){
		entropia += distancia(datos[i], datos[i+1]);
	}
	printf("\nEntropia: %f\n", entropia);
	if (entropia < PARAMINC) return 2;
	return 0;
}

int order(int * datos, int longitud){				// Calcula el 'tipo de orden' segun la 'entropia global' y 'entropia incremental'
	int i; 
	double entropia = 0;
	const double ordenmax = maxorder(longitud), inversmax = minorder(longitud);
	for(i = 0; i < longitud; i++){
		entropia += datos[i] * (i + 1);
	}
	printf("\nEntropia: %f\n", entropia);
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

int datacreator(char modo, int * datos, int longitud){		// Crea el array de datos del tipo solicitado, y estima su 'tipo de orden'
	startvector(datos, longitud, 1);
	switch(modo){
		case 'a':
			break;
		case 'b': 
			invertvector(datos, longitud);
			break;
		case 'c':
			randomize(datos, longitud);
			break;
		case 'd':
			duplicate(datos, longitud);
			break;
		case 'e':
			inputdata(datos, longitud);
			break;
	}
	return order(datos, longitud);
}

int main() {
	int longitud, orden;
	char modo;
	printf("\nMODOS DISPONIBLES:\n");
	printf("a) Ordenado sentido creciente\n");
	printf("b) Ordenado sentido decreciente\n");
	printf("c) Desordenado\n");
	printf("d) Con duplicados\n");
	printf("e) Introducir datos personalizados\n\n");
	printf("Intruduzca modo: ");
	scanf("%c", &modo);
	printf("Cantidad de datos a ordenar: ");
	scanf("%d", &longitud);
	int datos[longitud];
	orden = datacreator(modo, datos, longitud);
	showvector(datos, longitud);
	printf("\n\nTipo de orden: %d\n", orden);
	return 0;
}
