#include <stdio.h>
#include "Datacreator.h"


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
