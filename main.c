#include <stdio.h>
#include "Benchmark.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

void swapN(int * a, int * b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void startvector(int * datos, int longitud){
  for (int i = 0; i < longitud; i++)
    datos[i]=i+1;
}

void randomize(int * datos, int longitud){
  srand(clock());
  for(int j = 0; j < longitud; j++){
    for(int i = 0; i < longitud; i++){
      swapN(datos + i, datos + (rand() % longitud));
    }
  }
}

void burbuja(int * lista, int n, Experimento*experimento){ /* datos se pasa por dirección, N es el número de elementos, Experimento *exp es puntero a la estructura Experimento */

  iniciarCuenta(experimento);

  for(int i = 0; i < n-1 ;i++){
    for(int j = n-1; j > i ;j--){    /* me voy al último elemento*/
      if (comparar(lista[j] < lista[j-1], experimento)){   /* lo comparo con el anterior y si es necesario lo cambio*/
        swap(&lista[j], &lista[j-1], experimento);

      }
    }

  }
  finalizarCuenta(experimento);

}


float regrex(float * x, float * y, unsigned int n, float * b0, float * b1) {
  //Cálculo de las medias
  float meanX = 0, meanY = 0;
  for (unsigned int i = 0; i < n; i++) {
    meanY += y[i];
    meanX += x[i];
  }
  meanX /= n; meanY /= n;

  //Cálculo de la pendiente de la recta de regresión
  float num = 0, denom = 0;
  for (unsigned int i = 0; i < n; i++) {
    num += (y[i]-meanY)*(x[i]-meanX);
    denom += (x[i]-meanX)*(x[i]-meanX);
  }
  *b1 = num/denom;

  //Cálculo de la ordenada en el origen
  *b0 = meanY - *b1 * meanX;

  //Cálculo de los residuos
  float residue2 = 0;
  for (unsigned int i = 0; i < n; i++)
  residue2 += (*b0 + *b1 * x[i] - y[i]) * (*b0 + *b1 * x[i] - y[i]);
  return sqrt(residue2);
}

void complejidad(float * x, float * y, size_t n) {
  float b1, b0, res, y2[n];

  printf("RESIDUO   COSTE\n");

  //Lineal
  res =  regrex(x, y, n, &b0, &b1);
  printf("%.2f     %+.2f%+.2f*O(n)\n", res, b0, b1);

  //Cuadrático
  for (size_t i = 0; i < n; i++)
  y2[i] = y[i]/x[i];
  res =  regrex(x, y2, n, &b0, &b1);
  printf("%.2f     %+.2f%+.2f*O(n^2)\n", res, b0, b1);

  //Logaritmico
  for (size_t i = 0; i < n; i++)
  y2[i] = y[i]/log(x[i]);
  res =  regrex(x, y2, n, &b0, &b1);
  printf("%.2f     %+.2f%+.2f*O(n logn)\n", res, b0, b1);


}

int main(int argc, char const *argv[]) {
  Experimento experimento[4];
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
