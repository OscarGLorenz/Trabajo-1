#include <stdio.h>

void swap(int * a, int * b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void showvector(int * datos, int longitud){
	int i;
	for (i = 0; i < longitud; i++){
		printf("%d ", datos[i]);
	}
	printf("\n");
}

void startvector(int * datos, int longitud){
	int i;
	for (i = 0; i < longitud; i++){
		datos[i]=i+1;
	}
}

void invertvector(int * datos, int longitud){
	int i, j;
	for (i = 0, j = longitud - 1; i < j; i++, j--){
		swap(datos + i, datos + j);
	}
}

void randomize(int * datos, int longitud){
	int i, j;
	srand(clock());
	for(j = 0; j < longitud; j++){
		for(i=0; i < longitud; i++){
			swap(datos + i, datos + (rand() % longitud));
		}
	}
}

void duplicate(int * datos, int longitud){
	int i, j;
	srand(clock());
	j = rand() % longitud;
	j < 2? 2: j;
	for(i = 0; i < j; i++){
		*(datos + rand()%longitud) = *(datos + rand()%longitud);
	}
}

void inputdata(int * datos, int longitud){
	int i;
	for(i = 0; i < longitud; i++){
		printf("Introduzca dato %d: ", i+1);
		scanf("%d", datos + i);
	}
}

int datacreator(char modo, int * datos, int longitud){
	startvector(datos, longitud);
	switch(modo){
		case 'a':
			break;
		case 'b': 
			invertvector(datos, longitud);
			break;
		case 'c':
			randomize(datos, longitud);
			break;
		case 'd':
			duplicate(datos, longitud);
			break;
		case 'e':
			inputdata(datos, longitud);
			break;
	}
	showvector(datos, longitud);
}

int main() {
	int longitud;
	char modo;
	printf("\nMODOS DISPONIBLES:\n");
	printf("a) Ordenado sentido creciente\n");
	printf("b) Ordenado sentido decreciente\n");
	printf("c) Desordenado\n");
	printf("d) Con duplicados\n");
	printf("e) Introducir datos personalizados\n\n");
	printf("Intruduzca modo: ");
	scanf("%c", &modo);
	printf("Cantidad de datos a ordenar: ");
	scanf("%d", &longitud);
	int datos[longitud];
	datacreator(modo, datos, longitud);

	return 0;
}
