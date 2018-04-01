#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include <time.h>

// Estructura básica de la librería
typedef struct experiment {
  unsigned int comparations; //Guarda número de comparaciones
  unsigned int movements;   //Guarda número de movimientos
  struct timespec start;     //Estructura con el tiempo al inicio
  struct timespec end;        //Estructura con el tiempo al final
  size_t elements; 	      //Tamaño del experimento
} Experiment;

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

// Puntero a función para los diferentes costes computacionales
typedef float(*trans_ptr)(float,float);

// Diferentes costes computacionales. Transformaciones de los datos.
float lin(float x, float y);
float quad(float x, float y);
float linlog(float x, float y);

// Array de las transformaciones por defecto
#define TRANS {lin,quad,linlog}
// Número de transformaciones por defecto
#define NTRANS 3

// Coste de un algoritmo
typedef struct {
  trans_ptr transform; // Tipo de coste computacional
  float coef; // Coeficiente del coste
} Cost;

// Calcula el coste de movimientos, comparaciones y tiempo de una serie de experimentos.
void costIdentification(Experiment * experiment, size_t n, char * mov_str, char * comp_str, char * nanos_str);

// Tabla de resultados
typedef struct {
	char cost[6][4][3][30]; // Costes con coeficientes
	char costTypes[][30]; // Nombres de los costes
	int n_cost; // Número de costes
	char algorithms[][30]; // Nombres de los algoritmos
	int n_algorithm; // Números de algoritmos
  char dataTypes[][30]; // Nombres de los tipos de datos
	int n_data; // Números de tipos de datos
} ResTable;

// Puntero a función para los diferentes algoritmos
typedef void(*algorithm_ptr)(int*,size_t,Experiment*);

// Genera una estructura Results con los costes computacionales de cada algoritmo y para cada dato suministrado
void calculateTable(Results * result, size_t nelements[], int n_nelement,
  algorithm_ptr algorithms[], char algorithm_str[][30], int num_algorithm,
  dataType types[], char type_str[][30], int num_types);


#endif
