#ifndef LUCKY_H_
#define LUCKY_H_

#define PARAMAX datasize			// L�mite de 'entrop�a global' para ser considerado ordenado ascendente
#define PARAMIN datasize			// L�mite de 'entrop�a global' para ser considerado ordenado descendente
#define PARAMINC datasize			// L�mite de 'entrop�a icremental' para ser considerado relativamente ordenado (posiciones consecutivas son similares)

// Calcula la 'entropia global' en el caso de mayor orden ascendente
double maxorder(int datasize);

// Calcula la 'entropia global' en el caso de mayor orden descendente
double minorder(int datasize);

// Calcula la 'entropia incremental' del array, segun la distancia entre valores de posiciones consecutivas
char incremental(int * datavector, int datasize);

// Calcula el 'tipo de orden' segun la 'entropia global' y 'entropia incremental'
char orderType(int * datavector, int datasize);

/*
El tipo de orden ser�: 
 1: ~ordenado creciente
-1: ~ordenado decreciente
 2: ~consecutivos cercanos
 0: aleatorio
*/

#endif