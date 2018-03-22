#ifndef GUI_H_
#define GUI_H_

#include <stdio.h>
#include "Datacreator.h"

//Pide modo de uso del programa. Opciones: modo EXPERIMENTO, modo ORDENADOR
char programMode();

//Pide modo de EXPERIMENTO. Opciones: modo AUTO, modo ALGORITMOS, modo TIPODATOS
char experimentMode();

//Pide tipo de datos para ORDENADOR. Opciones: modo FICHERO, modo TECLADO
char dataInputMode();

//Pide modo de ORDENADOR. Opciones: modo AUTO/LUCKY, modo TODOSALGORITMOS
char orderInputMode();

// Visualiza el array de datos
void showVector(int * datavector, int datasize);

// Permite al usuario introducir los valores del array a través de un fichero *.txt en la misma carpeta que el programa
void dataFile(int * datavector, int datasize);

// Permite al usuario introducir los valores del array por teclado
void inputData(int * datavector, int datasize);

#endif
