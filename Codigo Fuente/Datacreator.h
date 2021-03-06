/******************************************************************************
* ARCHIVO :     Datacreator.h
*
* DESCRIPCIÓN :	Funciones varias para generar la interfaz de usuario en la consola.
*
* AUTOR :		Mario Musicò Cortés
******************************************************************************/

#ifndef DATACREATOR_H_
#define DATACREATOR_H_

#include <time.h>

#define NAMESIZE 	16
#define FILESIZE	32
#define COSTS 		3

typedef enum datatype{ 
	INCREASING, 
	DECREASING, 
	RANDOM, 
	REPEATED 
} dataType;

/*  --------------------------------------------------------------------------------
*	void dataCreator():	Crea el array de datos del tipo solicitado
*	datavector: 		puntero al vector de datos
*	datasize: 			tamaño del vector de datos
*	dataorder:			tipo de datos (posibles valores de dataType)
*	dataspacing:		0 = consecutivos; 1 = incremento aleatorio
*/
void dataCreator(int * datavector, int datasize, dataType dataorder, int dataspacing);

#endif
