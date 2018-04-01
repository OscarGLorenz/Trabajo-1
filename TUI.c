#include <stdio.h>
#include <string.h>
#include "TUI.h"
#include "Benchmark.h"


char programMode(){
	char mode;
	printf("\nQue desea hacer?\n");
	printf("a) Ejecutar experimento de obtencion de la complejidad de diferentes algoritmos de ordenacion de datos\n");
	printf("b) Ordenar una serie de datos introducidos por el usuario, en forma de fichero o por teclado\n");
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b'));
	return mode;
}

char experimentMode(){
	char mode;
	printf("\n***********************************************************");
	printf("\nHa entrado en modo EXPERIMENTO\n");
	printf("\nPara cada caso, se realizara una regresion para obtener el residuo frente al modelo teorico,\n");
	printf("\tprobando con un numero de datos de la forma 10^n, con n = 1..4\n");
	printf("Como desea realizar el experimento?\n");
	printf("a) En modo automatico, comparar todos los algoritmos con todos los tipos de datos\n");
	printf("b) Comparar la velocidad un algoritmo para diferentes tipos de datos\n");
	printf("c) Comparar diferentes algoritmos dado un tipo de dato\n");
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b') && (mode != 'c'));
	return mode;
}

void algorithmMode(Types* typestable){
	int i;
	char mode;
	printf("Que tipo de algoritmo desea analizar?\n");
	for (i = 0; i < 6; i++){
		printf("%c) %s\n", 'a'+i, typestable->algorithmTypes[i]);
	}
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b') && (mode != 'c') && (mode != 'd') && (mode != 'e') && (mode != 'f'));
	typestable->n_algorithms = mode - 'a';
}

void dataTypeMode(Types* typestable){
	int i;
	char mode;
	printf("\nComo desea que se encuentren los datos inicialmente?\n");
	for (i = 0; i < 4; i++){
		printf("%c) %s\n", 'a'+i, typestable->dataTypes[i]);
	}
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b') && (mode != 'c') && (mode != 'd'));
	typesTable->n_data = mode - 'a';
}

char dataInputMode(int* datasize){
	char mode;
	printf("\n***********************************************************");
	printf("\nHa entrado en modo ORDENADOR\n");
	printf("\nIndique que tipo de datos desea introducir:\n");
	printf("a) Por teclado\n");
	printf("b) Datos que se encuentran en un fichero en la misma carpeta que el programa\n");
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b'));
	if (mode == 'a'){

	}
	return mode;
}

char sorterInputMode(){
	char mode;
	printf("\nComo desea que se ordenen sus datos?\n");
	printf("a) \"I'm feeling lucky\", dime cual crees que es el algoritmo mas apropiado para este tipo de datos\n");
	printf("b) Comparar la velocidad de todos los algoritmos al ordenar los datos introducidos\n");
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b'));
	return mode;
}

void showVector(int * datavector, int datasize){
	int i;
	for (i = 0; i < datasize; i++){
		printf("%d ", datavector[i]);
	}
	printf("\n");
}

int fileOpener(FILE ** datafile){
	char filename[32];
	int datasize;
	printf("\nEl fichero debe contener un elemento de tipo entero natural en cada fila,\n");
	printf("y en la primera fila la cantidad de datos que contiene para ordenar.\n");
	printf("Indique el nombre del fichero, situado en la misma carpeta que el programa: ");
	do {
		scanf("%s", filename);
		if((*datafile = fopen(filename,"r")) == NULL){
			printf("Error al abrir el archivo. Vuelva a intentarlo: ");
		}
	} while (*datafile == NULL);
	fscanf(*datafile, "%d,\n", &datasize);
	return datasize;
}

void typeDefiner(Types* typestable){
	// i: algoritmo
	strcpy(typestable->algorithmTypes[0], "Burbuja  ");
	strcpy(typestable->algorithmTypes[1], "Insercion");
	strcpy(typestable->algorithmTypes[2], "Seleccion");
	strcpy(typestable->algorithmTypes[3], "Shell    ");
	strcpy(typestable->algorithmTypes[4], "Monticulo");
	strcpy(typestable->algorithmTypes[5], "Quicksort");
	
	// j: tipo de dato
	strcpy(typestable->dataTypes[0], "Crecientes  ");
	strcpy(typestable->dataTypes[1], "Decrecientes");
	strcpy(typestable->dataTypes[2], "Aleatorios  ");
	strcpy(typestable->dataTypes[3], "Repetidos   ");
	
	// k: coste
    strcpy(typestable->costTypes[0], "Comparaciones");
    strcpy(typestable->costTypes[1], "Movimientos  ");
	strcpy(typestable->costTypes[2], "Tiempo       ");
	
	// l: iteración
}

void resultVisualizer(int data[][4], Types typestable, int* datasize, int datasize){
	int i, j;
	Costs experimentcosts;
	if(typestable.n_algorithms == 6 && typestable.n_data == 4){		// En modo automatico, comparar todos los algoritmos con todos los tipos de datos\n
		printf("\n\nAlgoritmos\tTipo de coste computacional:\n\t\t");
		for(j = 0; j < typestable.n_costs; j++){
			printf("%s\t", typestable.costTypes[j]);
		}
		printf("\n");
		for(i = 0; i < typestable.n_algorithms; i++){
			printf("** %s **\n", typestable.algorithmTypes[i]);
			for(j = 0; j < typestable.n_data; j++){
				printf("%s:\t",typestable.dataTypes[k]);
				experimentcosts = runBenchmark();
				printf("%s\t%s\t%s\n", experimentcosts.comps, experimentcosts.moves, experimentcosts.time);
			}
			printf("\n");
		}
	}
	else if(typestable.n_algorithms != 6){		// Comparar la velocidad un algoritmo para diferentes tipos de datos
		
	}
	else {			// Comparar diferentes algoritmos dado un tipo de dato
		
	}
}
