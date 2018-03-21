#ifndef GUI_H_
#define GUI_H_

#include <stdio.h>
#include "Datacreator.h"

//Pide modo de uso del programa. Opciones: modo EXPERIMENTO, modo ORDENADOR
char programMode();

//Pide modo de EXPERIMENTO. Opciones: modo AUTO, modo ALGORITMOS, modo TIPODATOS
char experimentMode();

//Pide tipo de datos para ORDENADOR. Opciones: modo FICHERO, modo TECLADO
char datainputMode();

//Pide modo de ORDENADOR. Opciones: modo AUTO/LUCKY, modo TODOSALGORITMOS
char orderinputMode();

// Visualiza el array de datos
void showvector(int * datos, int longitud);

// Solicita al usuario el tipo de dato con el que quiere experimentar
datamode mododato();

#endif
