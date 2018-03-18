#ifndef BENCHMARK_H_
#define BENCHMARK_H_

/* Ejemplo de uso de Benchmark.h

  #include <stdio.h>
  #include <Benchmark.h>

  // Ordena dos elementos en orden creciente
  int ordenar2 (int * lista, unsigned int n, Experimento * experimento) {
    iniciarCuenta(experimento);

    if (comparar(lista[0] > lista[1], experimento))
    swap(&lista[0], &lista[1], experimento);

    finalizarCuenta(experimento);
  }

  int main() {
    int listaDesordenada[2] = {10,1};
    int listaOrdenada[2] = {1,10};

    Experimento desorden = nuevoExperimento();
    Experimento orden = nuevoExperimento();

    ordenar2(listaDesordenada, 2, &desorden);
    ordenar2(listaOrdenada, 2, &orden);

    printf("------------%s------------\n", STR(orden2));
    printf("%s: Comparaciones: %u, Movimientos: %u, Tiempo %u ns\n", STR(desorden),
      desorden.comparaciones, desorden.movimientos, tiempoNanosegundos(&desorden));
    printf("%s: Comparaciones: %u, Movimientos: %u, Tiempo %u ns\n", STR(orden),
      orden.comparaciones, orden.movimientos, tiempoNanosegundos(&orden));

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
struct experimento {
  unsigned int comparaciones; //Guarda número de comparaciones
  unsigned int movimientos;   //Guarda número de movimientos
  struct timespec inicio;     //Estructura con el tiempo al inicio
  struct timespec fin;        //Estructura con el tiempo al final
  size_t elementos; 	      //Tamaño del experimento
};

/* Para abreviar ahora se llamará "Experimento" sin más */
typedef struct experimento Experimento;

/* Genera un nuevo experimento, inicializa variables */
Experimento nuevoExperimento(size_t n);

/* Intercambia las variables x e y, añade 3 movimientos al experimento*/
void swap(int * x, int * y, Experimento * experimento);

/* Compara la expresión dada, actualiza el experimento y devuelve la expresión*/
int comparar(int expresion, Experimento * experimento);

/* Inicia la cuenta, se guarda el tiempo actual del proceso */
void iniciarCuenta(Experimento * experimento);

/* Finaliza la cuenta, se guarda el tiempo actual del proceso */
void finalizarCuenta(Experimento * experimento);

/* Devuelve en ms el tiempo transcurrido del inicio al fin */
unsigned int tiempoMilisegundos(Experimento * experimento);

/* Devuelve en ns el tiempo transcurrido del inicio al fin */
unsigned int tiempoNanosegundos(Experimento * experimento);

#endif
