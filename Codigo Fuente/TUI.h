/******************************************************************************
* ARCHIVO :     TUI.h
*
* DESCRIPCIÓN : Prototipos de funciones para generar la interfaz de usuario en la consola
*
* AUTOR :		Mario Musicò Cortés
******************************************************************************/

#ifndef TUI_H_
#define TUI_H_

#include "Datacreator.h"

/*  --------------------------------------------------------------------------------
*	void clear(): 		Solicita al S.O. que vacie la consola de comandos
*/
void clear();

/*  --------------------------------------------------------------------------------
*	char programMode(): Solicita al usuario el modo de uso del programa
*	return:				a = modo EXPERIMENTO, b = modo ORDENADOR
*/
char programMode();

/*  --------------------------------------------------------------------------------
*	char experimentMode(): Solicita al usuario la opcion de uso del modo EXPERIMENTO
*	return:				a = modo AUTO, b = modo ALGORITMOS, c = modo TIPODATOS
*/
char experimentMode(int iterations, int* dataSizes);

/*  --------------------------------------------------------------------------------
*	char dataInputMode(): Solicita al usuario la opcion de uso del modo ORDENADOR
*	return:				a = modo TECLADO, b = modo FICHERO
*/
char dataInputMode();

/*  --------------------------------------------------------------------------------
*	char algorithmtMode(): En modo EXPERIMENTO / 1 ALGORITMO, solicita al usuario el algoritmo deseado
*	return:				ID del tipo de algoritmo (ver Main.c)
*/
char algorithmMode(int n_algorithms, char algorithmNames[][NAMESIZE]);

/*  --------------------------------------------------------------------------------
*	char algorithmtMode(): En modo EXPERIMENTO / 1 TIPO DE DATO, solicita al usuario el tipo de dato a tratar
*	return:				tipo de dato (enum) (ver Main.c)
*/
dataType dataTypeMode(int n_data, char dataNames[][NAMESIZE]);

/*  --------------------------------------------------------------------------------
*	int dataSpacingMode(): Para la creaciond e datos en Filecreator.c, solicita el tipo de
*						incremento entre los datos una vez quedan ordenados
*	return:				0 = CONSECUTIVOS, 1 = DE INCREMENTO ALEATORIO
*/
int dataSpacingMode();

/*  --------------------------------------------------------------------------------
*	void showVector(): 	Visualiza el array de datos
*	datavector: 		puntero al vector de datos
*	datasize: 			tamaño del vector de datos
*/
void showVector(int * datavector, int datasize);

/*  --------------------------------------------------------------------------------
*	int fileOpener(): 	Abre el archivo de datos para el modo ORDENADOR y devuelve el tamaño del vector del archivo
*	filename: 			nombre del archivo de datos
*	return: 			tamaño del vector de datos que hay escrito en el archivo
*/
int fileOpener(FILE ** datafile, char* filename);

// Visualiza los resultados de los benchmark
void resultVisualizer(char**** results, char algorithmNames[][NAMESIZE], int n_algorithms, char dataNames[][NAMESIZE], int n_data, char costNames[][NAMESIZE]);

#endif
