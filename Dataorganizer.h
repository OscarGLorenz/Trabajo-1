#ifndef DATAORGANIZER_H_
#define DATAORGANIZER_H_

// Solicita al usuario introducir los valores del array por teclado
void inputData(int * datavector, int datasize);

// Permite al usuario introducir los valores del array a través de un fichero *.txt en la misma carpeta que el programa
void fileReader(int * datavector, int datasize, FILE * datafile);

// Ordena el array en modo LUCKY o TODOSALGORITMOS
void dataSorter(int * datavector, int datasize, char ordermode);

#endif
