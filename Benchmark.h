#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include <time.h>
#include "Datacreator.h"

#define TRANS {lin,quad,linlog}			// Array de las transformaciones por defecto
#define NTRANS 3						// Número de transformaciones por defecto

// Estructura básica de la librería
typedef struct experiment{
  unsigned int comparations; 			//Guarda número de comparaciones
  unsigned int movements;   			//Guarda número de movimientos
  struct timespec start;    			//Estructura con el tiempo al inicio
  struct timespec end;        			//Estructura con el tiempo al final
  size_t elements; 	      				//Tamaño del experimento
} Experiment;

// Puntero a función para los diferentes costes computacionales
typedef float(*trans_ptr)(float,float);

// Coste de un algoritmo
typedef struct cost{
  trans_ptr transform; 					// Tipo de coste computacional
  float coef; 							// Coeficiente del coste
} Cost;

// Puntero a función para los diferentes algoritmos
typedef void(*algorithm_ptr)(int*,size_t,Experiment*);

/* Genera un nuevo experimento, inicializa variables */
Experiment newExperiment(size_t n);

/* USO EN ALGORITMOS. Hace un intercambio entre dos variables y computa
como tres movimientos adicionales para el experimento */
void swap(int * x, int * y, Experiment * experiment);

/* USO EN ALGORITMOS. Evalua una expresión lógica y la devuelve. Computa una
comparación adicional al experimento */
int compare(int expresion, Experiment * experiment);

/* USO EN ALGORITMOS. Inicia la cuenta al principio del fragmento de código a
evaluar */
void startCount(Experiment * experiment);

/* USO EN ALGORITMOS. Finaliza la cuenta al final del fragmento de código a
evaluar */
void endCount(Experiment * experiment);

/* Devuelve el tiempo transcurrido desde startCount hasta endCount en
milisegundos */
unsigned int millis(Experiment * experiment);

/* Devuelve el tiempo transcurrido desde startCount hasta endCount en
nanosegundos */
unsigned int nanos(Experiment * experiment);

// Diferentes costes computacionales. Transformaciones de los datos.
float lin(float x, float y);
float quad(float x, float y);
float linlog(float x, float y);

// Calcula el coste de movimientos, comparaciones y tiempo de una serie de experimentos.
void costIdentification(Experiment * experiment, size_t n, char * mov_str, char * comp_str, char * nanos_str);

// Genera una estructura Results con los costes computacionales de cada algoritmo y para cada dato suministrado
char **** calculateTable(size_t nelements[], int num_nelement,
 algorithm_ptr algorithms[], int num_algorithm,
 dataType types[], int num_types);

 // Libera la estructura creada por la función anterior.
 void freeTable(char **** c, int first, int second, int third);
#endif
