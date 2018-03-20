#ifndef DATACREATOR_H_
#define DATACREATOR_H_

enum Datamode{
	CRECIENTE,
	DECRECIENTE,
	DESORDENADO,
	REPETIDOS,
	USUARIO
};

typedef enum Datamode datamode;

// Conmuta 2 variables proporcionadas por referencia
void swap(int * a, int * b);

// Calcula el incremento entre 2 elementos consecutivos, para el calculo de la 'entropia incremental'
int distancia(int a, int b);

// Visualiza el array de datos
void showvector(int * datos, int longitud);

// Rellena el array de datos con valores ascendentes; modo: 0 = consecutivos; 1 = incremento aleatorio
void startvector(int * datos, int longitud, int modo);

// Invierte el orden de un array
void invertvector(int * datos, int longitud);

// Aleatoriza un array dado realizando tantas pasadas de swaps como su tamaño
void randomize(int * datos, int longitud);

// Modifica array en un numero aleatorio de posiciones, duplicando posiciones también aleatorias
void duplicate(int * datos, int longitud);

// Permite al usuario introducir los valores del array, dada su longitud previamente
void inputdata(int * datos, int longitud);

// Calcula la 'entropia global' en el caso de mayor orden ascendente
double maxorder(int longitud);

// Calcula la 'entropia global' en el caso de mayor orden descendente
double minorder(int longitud);

// Calcula la 'entropia incremental' del array, segun la distancia entre valores de posiciones consecutivas
int incremental(int * datos, int longitud);

// Calcula el 'tipo de orden' segun la 'entropia global' y 'entropia incremental'
int order(int * datos, int longitud);

/*
El tipo de orden sera: 
 1: ~ordenado creciente
-1: ~ordenado decreciente
 2: ~consecutivos cercanos
 0: aleatorio
*/

// Crea el array de datos del tipo solicitado, y estima su 'tipo de orden'
int datacreator(datamode modo, int * datos, int longitud);

// Solicita al usuario el tipo de dato con el que quiere experimentar
datamode mododato();

#endif
