/******************************************************************************
* ARCHIVO :  Dataorganizer.h
*
* DESCRIPCION: Contiene los prototipos de funciones del modo ORDENADOR
*
* AUTOR :    Mario Music� Cort�s
******************************************************************************/

#ifndef DATAORGANIZER_H_
#define DATAORGANIZER_H_

#include <stdio.h>
#include "Benchmark.h"

/*   --------------------------------------------------------------------------------
*	void inputData(): 	Solicita al usuario introducir los valores del array por teclado

*	datavector: 		puntero al vector de datos
*	datasize: 			tama�o del vector de datos
*/
void inputData(int* datavector, int datasize);

/*	--------------------------------------------------------------------------------
*	void fileReader():	Permite al usuario introducir los valores del array a trav�s de 
*							un fichero *.txt en la misma carpeta que el programa
*	datavector: 		puntero al vector de datos
*	datasize: 			tama�o del vector de datos
*	datafile:			puntero al archivo de datos
*/
void fileReader(int* datavector, int datasize, FILE* datafile);

/*	--------------------------------------------------------------------------------
*	char**** multiSorter():	Ordena el vector de datos dado con todos los algoritmos,
*								generando la tabla de datos compatible con resultVisualizer()
*	datavector: 		puntero al vector de datos
*	datasize: 			tama�o del vector de datos
*	algorithms[]:		vector de funciones de los algoritmos
*	n_algorithm:		tama�o del vector de funciones
*	filename:			nombre del archivo de entrada
*	return:				devuelve el puntero a la matriz/tabla de resultados generada
*/
char**** multiSorter(int* datavector, int datasize, algorithm_ptr algorithms[], int n_algorithm, char* filename);

#endif
