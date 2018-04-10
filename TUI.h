#ifndef GUI_H_
#define GUI_H_

#include "Datacreator.h"

// Tabla de resultados
typedef struct modetypes{
	int n_algorithms; 					// Números de algoritmos
	char algorithmNames[6][32]; 		// Nombres de los algoritmos a visualizar
	char algorithmTypes[6][32];			// Nombres de los algoritmos a ejecutar

	int n_data; 						// Números de tipos de datos
	char dataNames[4][32]; 				// Nombres de los tipos de datos a visualizar
	dataType dataTypes[4];				// Nombres de los tipos de datos a utilizar

	int n_costs; 						// Número de costes
	char costTypes[3][32]; 				// Nombres de los costes
} Types;

//Pide modo de uso del programa. Opciones: modo EXPERIMENTO, modo ORDENADOR
char programMode();

//Pide modo de EXPERIMENTO. Opciones: modo AUTO, modo ALGORITMOS, modo TIPODATOS
char experimentMode();

// Pide tipo de algoritmo a analizar
void algorithmMode(Types* typestable);

//Pide orden inicial de datos
void dataTypeMode(Types* typestable);

//Pide tipo de datos para ORDENADOR. Opciones: modo FICHERO, modo TECLADO
char dataInputMode();

//Pide modo de ORDENADOR. Opciones: modo AUTO/LUCKY, modo TODOSALGORITMOS
char sorterInputMode();

// Visualiza el array de datos
void showVector(int * datavector, int datasize);

// Abre el archivo de datos introduciendo su nombre
int fileOpener(FILE ** datafile);

// Visualiza los resultados de los benchmark
void resultVisualizer(char**** results, Types typestable);

#endif
