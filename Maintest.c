#include <stdio.h>
#include "TUI.h"
#include "Datacreator.h"
#include "Dataorganizer.h"

#define MUESTRAMAX 6		//Para el modo experimento, se generarán vectores de datos a ordenar de tamaño 10^n, con n = 1..MUESTRAMAX

void runExperiment(){
	char mode = experimentMode();
	switch (mode){
		case 'a':
			
			break;
		case 'b':
			
			break;
		case 'c':
			
			break;
	}
}

void runOrganizer(){
	char dataMode = datainputMode();	
	char orderMode = orderinputMode();
	switch (dataMode){
		case 'a':
			
			break;
		case 'b':
			
			break;
	}
}

int main(int argc, char const *argv[]){
	char mode = programMode();	
	switch (mode){
		case 'a':
			runExperiment();
			break;
		case 'b':
			runOrganizer();
			break;
	}
	return 0;
}

/*		
//	Experimento experimento[4];
	float count[4];
	float number[4];

for (int i = 0; i < 4; i++) {
		experimento[i] = nuevoExperimento();
		int n = number[i] = pow(10,i+1);
		int datos[n];
		startvector(datos, n);
		randomize(datos, n);
		burbuja(datos, n, &experimento[i]);
		count[i] = experimento[i].comparaciones;
	}
  	
	complejidad(number,count,4);
	return 0;
}

int main(){
	int longitud, orden;
	datamode modo = mododato();
	printf("Cantidad de datos a ordenar: ");
	scanf("%d", &longitud);
	int datos[longitud];
	datacreator(modo, datos, longitud);
	showvector(datos, longitud);
	return 0;
}
*/
