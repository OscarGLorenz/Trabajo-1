#ifndef DATACREATOR_H_
#define DATACREATOR_H_

enum Datamode{
	CRECIENTE,
	DECRECIENTE,
	DESORDENADO,
	REPETIDOS
};

typedef enum Datamode datamode;

/*
// Conmuta 2 variables proporcionadas por referencia
static void swap(int * a, int * b);

// Rellena el array de datos con valores ascendentes; dataspacing: 0 = consecutivos; 1 = incremento aleatorio
static void startVector(int * datavector, int datasize, int dataspacing);

// Invierte el orden de un array
static void invertVector(int * datavector, int datasize);

// Aleatoriza un array dado realizando tantas pasadas de swaps como su tama�o
static void randomize(int * datavector, int datasize);

// Modifica array en un numero aleatorio de posiciones, duplicando posiciones tambi�n aleatorias
static void duplicate(int * datavector, int datasize);
*/

// Crea el array de datos del tipo solicitado. datamode: CRECIENTE, DECRECIENTE, DESORDENADO, REPETIDOS; dataspacing: dataspacing: 0 = consecutivos; 1 = incremento aleatorio
void dataCreator(int * datavector, int datasize, datamode dataorder, int dataspacing);

#endif
