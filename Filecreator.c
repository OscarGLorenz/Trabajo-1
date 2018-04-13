//Hay que poner el nombre del programa!

#include <stdio.h>
#include "TUI.h"

// Nombres de los tipos de datos a visualizar
char dataNames[][16] = {"Creciente", "Decreciente", "Aleatorio", "Repetidos"};
// Número de tipos de datos					(j)
int n_data = sizeof(dataNames) / sizeof(*dataNames);

int fileCreator(FILE ** datafile){
	char filename[32];
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
	scanf("%d", &datasize);
	return datasize;
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

void filePrinter(FILE * datafile, int * datavector, int datasize){
	int i;
	fprintf(datafile, "%d,\n", datasize);
	for (i = 0; i < datasize; i++){
		fprintf(datafile, "%d\n", datavector[i]);
	}
	fclose(datafile);
	printf("\n*******************************************\n");
	printf("Fichero generado con exito.\n");
}

int main(){
	FILE * datafile;
	int datasize = fileCreator(&datafile);
	int datavector[datasize];
	dataType dataorder = dataTypeMode(n_data, dataNames);
	int dataspacing = dataSpacingMode();
	dataCreator(datavector, datasize, dataorder, dataspacing);
	filePrinter(datafile, datavector, datasize);
	return 0;
}
