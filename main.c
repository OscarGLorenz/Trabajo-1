#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "TUI.h"
#include "Datacreator.h"
#include "Dataorganizer.h"
#include "Benchmark.h"
#include "Algorithm.h"
#include "Cost.h"

/*
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

void burbuja(int * list, size_t n, Experiment * experiment){

  startCount(experiment);

  for(size_t i = 0; i < n-1 ;i++){
    for(size_t j = n-1; j > i ;j--){
      if (compare(list[j] < list[j-1], experiment)){
        swap(&list[j], &list[j-1], experiment);

      }
    }

  }
  endCount(experiment);

}
*/

int main(int argc, char const *argv[]) {
  size_t p = 4;
  Experiment experiment[p];
  char comp_str[10], mov_str[10], nanos_str[10];

  for (size_t i = 0; i < p; i++) {
    size_t n = pow(10,i+1);
    experiment[i] = newExperiment(n);
    int data[n];
    //startvector(data, n);
    //randomize(data, n);

    dataCreator(data, n, DESORDENADO, 0);
    bubble(data, n, &experiment[i]);
  }

  costIdentification(experiment, p, mov_str, comp_str, nanos_str);

  printf("BURBUJA\n");

  printf("Comparaciones: %s\n", comp_str);
  printf("Movimientos: %s\n", mov_str);
  printf("Tiempo: %s\n", nanos_str);

  return 0;
}
