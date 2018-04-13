/******************************************************************************
* ARCHIVO :  Dataorganizer.c
*
* DESCRIPCION: Contiene las funciones de creacion del archivo de datos para la simulacion en modo ORDENADOR
*
* AUTOR :    Mario Musicò Cortés
******************************************************************************/

#include <stdio.h>
#include "TUI.h"
#include "Dataorganizer.h"

// Nombres de los tipos de datos a visualizar
char dataNames[][NAMESIZE] = {"Creciente", "Decreciente", "Aleatorio", "Repetidos"};
// Número de tipos de datos					(j)
int n_data = sizeof(dataNames) / sizeof(dataNames[0]);

/*	--------------------------------------------------------------------------------
*	int fileCreator():	
*	datafile: 			puntero a puntero de archivo
*	return:				tamaño del vector de datos a guardar
*/
int fileCreator(FILE ** datafile){
	char filename[FILESIZE];
	int datasize;
	printf("\nEste programa le permite generar un fichero de texto con una serie de datos pseudoaleatorios,\n");
	printf("para ser utilizados como simulacion de funcionamiento con el programa [Main.exe] en el modo ORDENADOR\n");
	printf("en caso de que usted no disponga de una serie de datos a ordenar.\n");
	printf("\nIntroduzca el nombre que le quiere dar al fichero de datos. Ejemplo: \"Datos.txt\": ");
	do {
		scanf("%s", filename);
		if((*datafile = fopen(filename,"w+")) == NULL){
			printf("Error al abrir el archivo. Vuelva a intentarlo: ");
		}
	} while (*datafile == NULL);
	printf("\nIntroduzca la cantidad de datos que desea generar: ");
	scanf("%lu", &datasize);
	return datasize;
}

/*	--------------------------------------------------------------------------------
*	int main():			Funcion principal del programa para crear un archivo con los tipos de datos deseados
*/
int main(){
	FILE * datafile;
	int datasize = fileCreator(&datafile);
	int datavector[datasize];
	dataType dataorder = dataTypeMode(n_data, dataNames);
	int dataspacing = dataSpacingMode();
	dataCreator(datavector, datasize, dataorder, dataspacing);
	filePrinter(datavector, datasize, datafile);
	fclose(datafile);
	return 0;
}
