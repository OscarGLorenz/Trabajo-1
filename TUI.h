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

//Pide modo de uso del programa. Opciones: modo EXPERIMENTO, modo ORDENADOR
char programMode();

//Pide modo de EXPERIMENTO. Opciones: modo AUTO, modo ALGORITMOS, modo TIPODATOS
char experimentMode();

// Pide tipo de algoritmo a analizar
char algorithmMode(char algorithmNames[][16]);

//Pide orden inicial de datos
dataType dataTypeMode(char dataNames[][16]);

//Pide tipo de datos para ORDENADOR. Opciones: modo FICHERO, modo TECLADO
char dataInputMode();

// Visualiza el array de datos
void showVector(int * datavector, int datasize);

// Abre el archivo de datos introduciendo su nombre
int fileOpener(FILE ** datafile);

// Visualiza los resultados de los benchmark
void resultVisualizer(char**** results, char algorithmNames[][16], int n_algorithms, char dataNames[][16], int n_data, char costNames[][16], int n_costs);

#endif
