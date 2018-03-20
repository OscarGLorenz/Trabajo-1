#include <stdio.h>
#include "GUI.h"

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
	printf("e) Introducir datos personalizados\n\n");
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
			return USUARIO;
	}
}


