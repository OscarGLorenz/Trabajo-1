#ifndef DATACREATOR_H_
#define DATACREATOR_H_

enum Datamode{
	CRECIENTE,
	DECRECIENTE,
	DESORDENADO,
	REPETIDOS,
};

typedef enum Datamode datamode;

// Conmuta 2 variables proporcionadas por referencia
void swap(int * a, int * b);

// Rellena el array de datos con valores ascendentes; modo: 0 = consecutivos; 1 = incremento aleatorio
void startvector(int * datos, int longitud, int modo);

// Invierte el orden de un array
void invertvector(int * datos, int longitud);

// Aleatoriza un array dado realizando tantas pasadas de swaps como su tamaño
void randomize(int * datos, int longitud);

// Modifica array en un numero aleatorio de posiciones, duplicando posiciones también aleatorias
void duplicate(int * datos, int longitud);

// Crea el array de datos del tipo solicitado
int datacreator(datamode modo, int * datos, int longitud);

#endif
