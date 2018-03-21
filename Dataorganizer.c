#include <stdio.h>
#include "Dataorganizer.h"
#include "Lucky.h"

void datafile(int * datos, int longitud){
	char ficheronombre[32]
	FILE * ficherodatos;
	printf("El fichero debe contener un elemento de tipo entero natural en cada fila.");
	prinft("Indique el nombre del fichero, situado en la misma carpeta que el programa: ");
	do {
		scanf("%s",ficherodatos);
		if((ficherodatos = fopen(ficheronombre,"r")) == NULL){
			printf("Error al abrir el archivo. Vuelva a intentarlo: ");
		}
	} while (ficherodatos == NULL);
	
}

void inputdata(int * datos, int longitud){
	int i;
	for(i = 0; i < longitud; i++){
		printf("Introduzca dato %d: ", i+1);
		scanf("%d", datos + i);
	}
}


