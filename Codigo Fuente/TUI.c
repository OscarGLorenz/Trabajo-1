/******************************************************************************
* ARCHIVO :  TUI.c
*
* DESCRIPCION: Contiene las funciones de interfaz de usuario y visualizacion. Ver aclaraciones de funciones publicas en header
*
* AUTOR :    Mario Musicò Cortés
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "TUI.h"

// Implementacion para vaciar la pantalla de la consola de comandos
#if __unix__ 
	#include <stdlib.h>
	void clear(){
    	system("clear");
		printf("\n");
	}
#elif defined(_WIN32) || defined(WIN32) 
	void clear(){
		system("cls");
		printf("\n");
	}
#endif


char programMode(){
	char mode;
	printf("\nQue desea hacer?\n");
	printf("a) Ejecutar experimento de obtencion de la complejidad de diferentes algoritmos de ordenacion de datos\n");
	printf("b) Ordenar una serie de datos introducidos por el usuario, en forma de fichero o por teclado.\n");
	printf("\t\tSe compararan los diferentes algoritmos implementados y\n");
	printf("\t\tal final se devolveran los datos ordenados en un nuevo fichero\n");
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b'));
	return mode;
}

char experimentMode(int iterations, int* dataSizes){
	char mode;
	int l;
	clear();
	printf("\nHa entrado en modo EXPERIMENTO\n");
	printf("\nPara cada caso, se realizara una regresion para obtener el residuo frente al modelo teorico,\n");
	printf("\tprobando con las siguientes cantidades de datos: ");
	for (l = 0; l< iterations; l++){
		printf("%lu, ", (unsigned long)dataSizes[l]);
	}
	printf("\n\nComo desea realizar el experimento?\n");
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

char dataInputMode(){
	char mode;
	clear();
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

char algorithmMode(int n_algorithms, char algorithmNames[][NAMESIZE]){
	int i;
	char mode;
	printf("Que tipo de algoritmo desea analizar?\n");
	for (i = 0; i < n_algorithms; i++){
		printf("%c) %s\n", 'a'+i, algorithmNames[i]);
	}
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b') && (mode != 'c') && (mode != 'd') && (mode != 'e') && (mode != 'f'));
	return mode - 'a';
}

dataType dataTypeMode(int n_data, char dataNames[][NAMESIZE]){
	int i;
	char mode;
	printf("\nComo desea que se encuentren los datos inicialmente?\n");
	for (i = 0; i < n_data; i++){
		printf("%c) %s\n", 'a'+i, dataNames[i]);
	}
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b') && (mode != 'c') && (mode != 'd'));
	return (dataType)mode - 'a';
}

int dataSpacingMode(){
	char mode;
	printf("\nDe que tipo desea que sean los datos generados? Segun su disposicion una vez queden ordenados:\n");
	printf("a) De valores consecutivos\n");
	printf("b) De valores con incrementos aleatorios\n");
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b'));
	return mode == 'a' ? 0 : 1;
}


void showVector(int * datavector, int datasize){
	int i;
	for (i = 0; i < datasize; i++){
		printf("%d ", datavector[i]);
	}
	printf("\n");
}

int fileOpener(FILE ** datafile, char* filename){
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
	printf("\nEl archivo contiene %lu datos a ordenar", (unsigned long)datasize);
	return datasize;
}

void resultVisualizer(char**** results, char algorithmNames[][NAMESIZE], int n_algorithms, char dataNames[][NAMESIZE], int n_data, char costNames[][NAMESIZE]){
	int i, j, k;
	printf("\n\nAlgoritmos\tTipo de coste computacional:\n\t\t");
	for(k = 0; k < COSTS; k++){
		printf("%s\t\t", costNames[k]);
	}
	printf("\n");
	for(i = 0; i < n_algorithms; i++){
		printf("** %s **\n", algorithmNames[i]);
		for(j = 0; j < n_data; j++){
			printf("%s:\t",dataNames[j]);
			for (k = 0; k < COSTS; k++){
				printf("%s\t\t", results[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
