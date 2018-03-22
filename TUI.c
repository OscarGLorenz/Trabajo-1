#include <stdio.h>
#include "TUI.h"

/*
#include <sys/stat.h>
#if __unix__ 
	void clear() {
    		system("clear");
	}
#elif defined(_WIN32) || defined(WIN32) 
	void clear() {
		system("cls");
#endif
*/

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
	printf("\tprobando con un numero de datos de la forma 10^n, con n = 1..6\n");
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
		printf("\nNumero de elementos que desea introducir: ");
		scanf("%d", datasize);
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

void dataFile(int * datavector, int datasize){
	char filename[32];
	FILE * datafile;
	printf("El fichero debe contener un elemento de tipo entero natural en cada fila.");
	printf("Indique el nombre del fichero, situado en la misma carpeta que el programa: ");
	do {
		scanf("%s", filename);
		if((datafile = fopen(filename,"r")) == NULL){
			printf("Error al abrir el archivo. Vuelva a intentarlo: ");
		}
	} while (datafile == NULL);
	
}

void inputData(int * datavector, int datasize){
	int i;
	int data[datasize];
	printf("\n");
	for(i = 0; i < datasize; i++){
		printf("Introduzca dato %d: ", i+1);
		scanf("%d", datavector + i);
	}
}

