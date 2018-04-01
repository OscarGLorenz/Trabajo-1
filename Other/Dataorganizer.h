#ifndef DATAORGANIZER_H_
#define DATAORGANIZER_H_

// Solicita al usuario introducir los valores del array por teclado
void inputData(int * datavector, int datasize);

// Permite al usuario introducir los valores del array a través de un fichero *.txt en la misma carpeta que el programa
void fileReader(int * datavector, int datasize, FILE * datafile);

// Ordena el array de datos introducido con dl algoritmo que se estima mas apropiado
void luckySorter(int * datavector, int datasize);

// Ordena el array de datos introducido mediante todos los algoritmos implementados, comparando su velocidad.
void multiSorter(int * datavector, int ldatasize);

#endif
