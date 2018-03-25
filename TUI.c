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

char datainputMode(){
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

char orderinputMode(){
	char mode;
	printf("\nComo desea que se ordenen sus datos?\n");
	printf("a) \"I feel lucky\", dime cual crees que es el algoritmo mas apropiado para este tipo de datos\n");
	printf("b) Comparar la velocidad de todos los algoritmos\n");
	do{
		printf("Introducza su opcion: ");
		fflush(stdin);
		scanf("%c", &mode);
	} while((mode!= 'a') && (mode != 'b'));
	return mode;
}

void showvector(int * datos, int longitud){
	int i;
	for (i = 0; i < longitud; i++){
		printf("%d ", datos[i]);
	}
	printf("\n");
}

datamode mododato(){
	char modo;
	printf("\nMODOS DISPONIBLES:\n");
	printf("a) Ordenado sentido creciente\n");
	printf("b) Ordenado sentido decreciente\n");
	printf("c) Desordenado\n");
	printf("d) Con duplicados\n");
	printf("f) Datos presentes en fichero (1 numero/fila)\n\n");
	printf("f) Introducir datos\n\n");
	printf("Intruduzca modo: ");
	scanf("%c", &modo);
	switch(modo){
		case 'a':
			return CRECIENTE;
		case 'b': 
			return DECRECIENTE;
		case 'c':
			return DESORDENADO;
		case 'd':
			return REPETIDOS;
		case 'e':
			return FICHERO;
		case 'f':
			return USUARIO;
	}
}


