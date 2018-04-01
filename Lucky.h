#ifndef LUCKY_H_
#define LUCKY_H_

#define PARAMAX datasize			// Límite de 'entropía global' para ser considerado ordenado ascendente
#define PARAMIN datasize			// Límite de 'entropía global' para ser considerado ordenado descendente
#define PARAMINC datasize			// Límite de 'entropía icremental' para ser considerado relativamente ordenado (posiciones consecutivas son similares)

// Calcula el 'tipo de orden' segun la 'entropia global' y 'entropia incremental'
char orderType(int * datavector, int datasize);

/*
El tipo de orden será: 
 1: ~ordenado creciente
-1: ~ordenado decreciente
 2: ~consecutivos cercanos
 0: aleatorio
*/

#endif
