#ifndef DATACREATOR_H_
#define DATACREATOR_H_

typeDef enum {
	INCREASING,
	DECREASING,
	RANDOM,
	REPEATED
} dataType;

// Crea el array de datos del tipo solicitado. dataType, dataspacing: 0 = consecutivos; 1 = incremento aleatorio
void dataCreator(int * datavector, int datasize, dataType dataorder, int dataspacing);

#endif
