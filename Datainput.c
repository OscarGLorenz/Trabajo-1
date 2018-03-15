#include <stdio.h>

void showvector(int * datos, int longitud){
	int i;
	for (i = 0; i < longitud; i++){
		printf("%d ", datos[i]);
	}
	printf("\n");
}

void fillvector(int * datos, int longitud){
	int i;
	for (i = 0; i < longitud; i++){
		datos[i]=i+1;
	}
}

void swap(int * a, int * b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void randomize(int * datos, int longitud){
	int i, j, k;
	srand(clock());
	for(k = 0; k < longitud; k++){
		srand(clock());
		for(i=0; i < longitud; i++){
			j = rand() % longitud;
			swap(datos + i, datos + j);
		}
	}
}

int datacreator(char modo, int * datos, int longitud){
	int i;
	fillvector(datos, longitud);
	for(i = 0; i < 20; i++){
		randomize(datos, longitud);
		showvector(datos, longitud);
	}
}

int main() {
	int longitud;
	printf("Intruduzca longitud:");
	scanf("%d", &longitud);
	int datos[longitud];
	datacreator('a', datos, longitud);
	
	return 0;
}
