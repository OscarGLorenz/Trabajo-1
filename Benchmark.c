#include "Benchmark.h"
#include <time.h>

Experimento nuevoExperimento() {
  Experimento experimento;
  experimento.comparaciones = 0;
  experimento.movimientos = 0;
  return experimento;
}

void swap(int * x, int * y, Experimento * experimento) {
  experimento->movimientos+=3;
  int aux = *x;
  *x = *y;
  *y = aux;
}

int comparar(int expresion, Experimento * experimento) {
  experimento->comparaciones++;
  return expresion;
}

void iniciarCuenta(Experimento * experimento) {
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &experimento->inicio);
}

void finalizarCuenta(Experimento * experimento) {
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &experimento->fin);
}

unsigned int tiempoMilisegundos(Experimento * experimento) {
  return (experimento->fin.tv_nsec-experimento->inicio.tv_nsec)/10e6 +
  (experimento->fin.tv_sec-experimento->inicio.tv_sec) * 10e3;
}

unsigned int tiempoNanosegundos(Experimento * experimento) {
  return (experimento->fin.tv_nsec-experimento->inicio.tv_nsec)+
  (experimento->fin.tv_sec-experimento->inicio.tv_sec) * 10e9;
}

int ordenar2 (int * lista, unsigned int n, Experimento * experimento) {
  if(n != 2) return -1;

  iniciarCuenta(experimento);

  if (comparar(lista[0] > lista[1], experimento))
  swap(&lista[0], &lista[1], experimento);

  finalizarCuenta(experimento);

  return 0;
}
