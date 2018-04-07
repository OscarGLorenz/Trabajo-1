#ifndef DATACREATOR_H_
#define DATACREATOR_H_

#include <time.h>

typedef enum datatype{ 
	INCREASING, 
	DECREASING, 
	RANDOM, 
	REPEATED 
} dataType;

// Estructura básica de la librería
typedef struct experiment{
  unsigned int comparations; 			//Guarda número de comparaciones
  unsigned int movements;   			//Guarda número de movimientos
  struct timespec start;    			//Estructura con el tiempo al inicio
  struct timespec end;        			//Estructura con el tiempo al final
  size_t elements; 	      				//Tamaño del experimento
} Experiment;

// Puntero a función para los diferentes algoritmos
typedef void(*algorithm_ptr)(int*,size_t,Experiment*);

// Tabla de resultados
typedef struct {
	int n_algorithms; 					// Números de algoritmos (i)
	algorithm_ptr algorithmTypes[6];// Nombres de los algoritmos a ejecutar
	char algorithmNames[6][16]; 		// Nombres de los algoritmos a visualizar
	
	int n_data; 						// Números de tipos de datos (j)
	dataType dataTypes[4];				// Nombres de los tipos de datos a utilizar
	char dataNames[4][16]; 				// Nombres de los tipos de datos a visualizar
	
	int n_costs; 						// Número de costes (k)
	char costTypes[3][16]; 				// Nombres de los costes
	
	int iterations;						// Número de iteraciones por experimento (l)
	size_t datasizes[4];					// Cantidades de datos con las que se iteran
	
} Types;

// Crea el array de datos del tipo solicitado. dataType, dataspacing: 0 = consecutivos; 1 = incremento aleatorio
void dataCreator(int * datavector, int datasize, dataType dataorder, int dataspacing);

#endif
