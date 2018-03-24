#ifndef GUI_H_
#define GUI_H_

#include "Datacreator.h"

//Pide modo de uso del programa. Opciones: modo EXPERIMENTO, modo ORDENADOR
char programMode();

//Pide modo de EXPERIMENTO. Opciones: modo AUTO, modo ALGORITMOS, modo TIPODATOS
char experimentMode();

//Pide tipo de datos para ORDENADOR. Opciones: modo FICHERO, modo TECLADO
char dataInputMode();

//Pide modo de ORDENADOR. Opciones: modo AUTO/LUCKY, modo TODOSALGORITMOS
char sorterInputMode();

// Visualiza el array de datos
void showVector(int * datavector, int datasize);

//Pide orden inicial de datos. Opciones: CRECIENTE, DECRECIENTE, DESORDENADO, REPETIDOS
datamode dataOrderMode();

// Abre el archivo de datos introduciendo su nombre
int fileOpener(FILE ** datafile);

#endif
