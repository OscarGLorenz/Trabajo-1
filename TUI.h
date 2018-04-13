/******************************************************************************
* ARCHIVO :     TUI.h
*
* DESCRIPCIÓN : Funciones varias para generar la interfaz de usuario en la consola
*
* AUTOR :		Mario Musicò Cortés
******************************************************************************/

#ifndef TUI_H_
#define TUI_H_

#include "Datacreator.h"

#define NAMESIZE 16

//Pide modo de uso del programa. Opciones: modo EXPERIMENTO, modo ORDENADOR
char programMode();

//Pide modo de EXPERIMENTO. Opciones: modo AUTO, modo ALGORITMOS, modo TIPODATOS
char experimentMode(int iterations, size_t* dataSizes);

// Pide tipo de algoritmo a analizar
char algorithmMode(int n_algorithms, char algorithmNames[][NAMESIZE]);

//Pide orden inicial de datos
dataType dataTypeMode(int n_data, char dataNames[][NAMESIZE]);

//Pide tipo de datos para ORDENADOR. Opciones: modo FICHERO, modo TECLADO
char dataInputMode();

// Visualiza el array de datos
void showVector(int * datavector, int datasize);

// Abre el archivo de datos introduciendo su nombre
int fileOpener(FILE ** datafile);

// Visualiza los resultados de los benchmark
void resultVisualizer(char**** results, char algorithmNames[][NAMESIZE], int n_algorithms, char dataNames[][NAMESIZE], int n_data, char costNames[][NAMESIZE], int n_costs);

#endif
