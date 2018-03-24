#ifndef DATACREATOR_H_
#define DATACREATOR_H_

enum Datamode{
	CRECIENTE,
	DECRECIENTE,
	DESORDENADO,
	REPETIDOS
};

typedef enum Datamode datamode;

// Conmuta 2 variables proporcionadas por referencia
void swap(int * a, int * b);

// Rellena el array de datos con valores ascendentes; mode: 0 = consecutivos; 1 = incremento aleatorio
void startVector(int * datavector, int datasize, char mode);

// Invierte el orden de un array
void invertVector(int * datavector, int datasize);

// Aleatoriza un array dado realizando tantas pasadas de swaps como su tamaño
void randomize(int * datavector, int datasize);

// Modifica array en un numero aleatorio de posiciones, duplicando posiciones también aleatorias
void duplicate(int * datavector, int datasize);

// Crea el array de datos del tipo solicitado
void dataCreator(int * datavector, int datasize, datamode dataorder, char dataspacing);

#endif
