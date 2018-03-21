#ifndef LUCKY_H_
#define LUCKY_H_

#define PARAMAX longitud			// Límite de 'entropía global' para ser considerado ordenado ascendente
#define PARAMIN longitud			// Límite de 'entropía global' para ser considerado ordenado descendente
#define PARAMINC longitud			// Límite de 'entropía icremental' para ser considerado relativamente ordenado (posiciones consecutivas son similares)

// Calcula la 'entropia global' en el caso de mayor orden ascendente
double maxorder(int longitud);

// Calcula la 'entropia global' en el caso de mayor orden descendente
double minorder(int longitud);

// Calcula la 'entropia incremental' del array, segun la distancia entre valores de posiciones consecutivas
int incremental(int * datos, int longitud);

// Calcula el 'tipo de orden' segun la 'entropia global' y 'entropia incremental'
int order(int * datos, int longitud);

/*
El tipo de orden será: 
 1: ~ordenado creciente
-1: ~ordenado decreciente
 2: ~consecutivos cercanos
 0: aleatorio
*/

#endif
