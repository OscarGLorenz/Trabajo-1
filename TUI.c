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
	printf("\tprobando con un numero de datos de la forma 10^n, con n = 2..4\n");
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

char orderInputMode(){
	char mode;
	printf("\nComo desea que se ordenen sus datos?\n");
	printf("a) \"I'm feeling lucky\", dime cual crees que es el algoritmo mas apropiado para este tipo de datos\n");
	printf("b) Comparar la velocidad de todos los algoritmos\n");
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

datamode dataOrderMode(){
	char mode;
	printf("\nComo desea que se encuentren los datos inicialmente?\n");
	printf("a) Ordenados sentido creciente\n");
	printf("b) Ordenados sentido decreciente\n");
	printf("c) Desordenados\n");
	printf("d) Con duplicados\n");
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b') && (mode != 'c') && (mode != 'd'));
	return mode == 'a' ? CRECIENTE : mode == 'b' ? DECRECIENTE : mode == 'c' ? DESORDENADO : REPETIDOS;
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

