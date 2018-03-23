#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "Benchmark.h"
#include "Cost.h"

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

int main(int argc, char const *argv[]) {
  int p = 4;
  Experimento experimento[p];
  float count[p], movs[p], tims[p];
  float number[p];
  Cost comp, mov, timing;
  char comp_str[10], mov_str[10], timing_str[10];

  for (int i = 0; i < p; i++) {
    int n = number[i] = pow(10,i+1);
    experimento[i] = nuevoExperimento(n);
    int datos[n];
    startvector(datos, n);
    randomize(datos, n);
    burbuja(datos, n, &experimento[i]);
    count[i] = experimento[i].comparaciones;
    movs[i] = experimento[i].movimientos;
    tims[i] = tiempoNanosegundos(&experimento[i]);
  }

  comp = identify(number,count,p,TRANS,NTRANS); costToString(comp, comp_str);
  mov = identify(number,movs,p,TRANS,NTRANS); costToString(mov, mov_str);
  timing = identify(number,tims,p,TRANS,NTRANS); costToString(timing, timing_str);

  printf("BURBUJA\n");

  printf("Comparaciones: %s\n", comp_str);
  printf("Movimientos: %s\n", mov_str);
  printf("Tiempo: %s\n", timing_str);

  return 0;
}
