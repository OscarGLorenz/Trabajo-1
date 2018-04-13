#ifndef DATAORGANIZER_H_
#define DATAORGANIZER_H_

#include <stdio.h>
#include "Benchmark.h"

// Solicita al usuario introducir los valores del array por teclado
void inputData(int* datavector, size_t datasize);

// Permite al usuario introducir los valores del array a través de un fichero *.txt en la misma carpeta que el programa
void fileReader(int * datavector, size_t datasize, FILE * datafile);

void dataSaver(int * datavector, size_t datasize, char* input);

void filePrinter(int * datavector, size_t datasize, FILE * datafile);

// Ordena el array de datos introducido mediante todos los algoritmos implementados, comparando su velocidad.
char**** multiSorter(int * datavector, size_t datasize, algorithm_ptr algorithms[], int n_algorithm, char* filename);

#endif
