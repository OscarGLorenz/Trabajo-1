#ifndef BENCHMARK_H_
#define BENCHMARK_H_

/* Ejemplo de uso de Benchmark.h

  #include <stdio.h>
  #include <Benchmark.h>

  // Ordena dos elementos en orden creciente
  int ordenar2 (int * list, size_t n, Experiment * experiment) {
    startCount(experiment);

    if (compare(list[0] > list[1], experiment))
    swap(&list[0], &list[1], experiment);

    endCount(experiment);
  }

  int main() {
    size_t n = 2;
    int listaDesordenada[] = {10,1};
    int listaOrdenada[] = {1,10};

    Experiment desorder = newExperiment(n);
    Experiment order = newExperiment(n);

    ordenar2(listaDesordenada, n, &desorden);
    ordenar2(listaOrdenada, n, &orden);

    printf("------------%s------------\n", STR(orden2));
    printf("%s: Comparaciones: %u, Movimientos: %u, Tiempo %u ns\n", STR(desorden),
      desorden.comparations, desorden.movements, nanos(&desorden));
    printf("%s: Comparaciones: %u, Movimientos: %u, Tiempo %u ns\n", STR(orden),
      orden.comparations, orden.movements, nanos(&orden));

    return 0;
  }

Salida por pantalla:
------------orden2------------
desorden: Comparaciones: 1, Movimientos: 3, Tiempo 700 ns\n"
orden: Comparaciones: 1, Movimientos: 0, Tiempo 300 ns\n"

*/

#include <time.h>

/* Convierte a const char * su argumento */
#define STR(x) #x

/* Estructura básica de la librería */
struct experiment {
  unsigned int comparations; //Guarda número de comparaciones
  unsigned int movements;   //Guarda número de movimientos
  struct timespec start;     //Estructura con el tiempo al inicio
  struct timespec end;        //Estructura con el tiempo al final
  size_t elements; 	      //Tamaño del experimento
};

/* Para abreviar ahora se llamará "Experimento" sin más */
typedef struct experiment Experiment;

/* Genera un nuevo experimento, inicializa variables */
Experiment newExperiment(size_t n);

/* Intercambia las variables x e y, añade 3 movimientos al experimento*/
void swap(int * x, int * y, Experiment * experiment);

/* Compara la expresión dada, actualiza el experimento y devuelve la expresión*/
int compare(int expresion, Experiment * experiment);

/* Inicia la cuenta, se guarda el tiempo actual del proceso */
void startCount(Experiment * experiment);

/* Finaliza la cuenta, se guarda el tiempo actual del proceso */
void endCount(Experiment * experiment);

/* Devuelve en ms el tiempo transcurrido del inicio al fin */
unsigned int millis(Experiment * experiment);

/* Devuelve en ns el tiempo transcurrido del inicio al fin */
unsigned int nanos(Experiment * experiment);

#endif
