/******************************************************************************
* ARCHIVO :  TUI.c
*
* AUTOR :    Mario Musicò Cortés
******************************************************************************/

#include <stdio.h>
#include "TUI.h"

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

char algorithmMode(char algorithmNames[][16]){
	int i;
	char mode;
	printf("Que tipo de algoritmo desea analizar?\n");
	for (i = 0; i < 6; i++){
		printf("%c) %s\n", 'a'+i, algorithmNames[i]);
	}
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b') && (mode != 'c') && (mode != 'd') && (mode != 'e') && (mode != 'f'));
	return mode - 'a';
}

dataType dataTypeMode(char dataNames[][16]){
	int i;
	char mode;
	printf("\nComo desea que se encuentren los datos inicialmente?\n");
	for (i = 0; i < 4; i++){
		printf("%c) %s\n", 'a'+i, dataNames[i]);
	}
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b') && (mode != 'c') && (mode != 'd'));
	return (dataType)mode - 'a';
}

char dataInputMode(){
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

void resultVisualizer(char**** results, char algorithmNames[][16], int n_algorithms, char dataNames[][16], int n_data, char costNames[][16], int n_costs){
	int i, j, k;
	printf("\n\nAlgoritmos\tTipo de coste computacional:\n\t\t");
	for(k = 0; k < n_costs; k++){
		printf("%s\t\t", costNames[k]);
	}
	printf("\n");
	for(i = 0; i < n_algorithms; i++){
		printf("** %s **\n", algorithmNames[i]);
		for(j = 0; j < n_data; j++){
			printf("%s:\t",dataNames[j]);
			for (k = 0; k < n_costs; k++){
				printf("%s\t\t", results[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
