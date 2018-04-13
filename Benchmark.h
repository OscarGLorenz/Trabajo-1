/******************************************************************************
* ARCHIVO :        Benchmark.h
*
* DESCRIPCIÓN :
*       Funciones varias para evaluar el coste computacional de un algoritmos
*       También tiene la opción de iterar por todas las combinaciones de
*       experimentos que uno desee en cuanto al orden inicial de los datos,
*       el algoritmo a utilizar y el tamaño de los vectores a ordenar.
*
* TIPOS DE DATO :
*       Experiment: estructura que contabiliza los movimientos y comparaciones
*       	además del tiempo transcurrido y número de elementos al
*       	que está referido este experimento.
*	      Cost: guarda el coste computacional de una combinación de algoritmo y
*		      tipo de dato, con un puntero a función del tipo (lineal,
*		      cuadrático o otro) y el coeficiente que le acompaña
*	      trans_ptr: puntero a función transformación, las distintas
*		      transformaciones (lineal, lineal-logaritmica cuadrática)....
*	      algorithm_ptr: punto a función a los algoritmos de ordenación
*
* FUNCIONES PÚBLICAS :
*       Experiment	  newExperiment( size_t )
*	      void		      swap( int* , int* , Experiment* )
*	      int		        compare( int , Experiment* )
*	      void		      startCount( Experiment* )
*	      void		      endCount( Experiment* )
*	      unsigned int	millis( Experiment* )
*	      unsigned int	nanos( Experiment* )
*	      float		      lin( float , float )
*	      float     		quad( float , float )
*	      float     		linlog(	float , float )
*	      void 		      costIdentification( Experiment* , size_t , char* ,
*						                           char* , char* )
*	      char**** 	    calculateTable(	size_t[] , int , algorithm_ptr[], int ,
*					                            dataType[], int )
*     	void 		       freeTable( char**** , int , int , int )
* MACROS :
*       TRANS: Funciones de transformación entrecomilladas y con llaves
*       NTRANS: Número de funciones de transformación
*
* AUTOR :    Óscar García Lorenz
******************************************************************************/

#ifndef BENCHMARK_H_
#define BENCHMARK_H_

// #define DEBUG // Descomentar Para mostrar resultados adicionales

/* En el standard ISO o ANSI de C no están permitidas las funciones POSIX
de esta forma podremos ejecutar funciones POSIX. Se necesita en clock_gettime */
#ifdef __unix__
#define _POSIX_C_SOURCE 200809L
#endif

#include <time.h>
#include "Datacreator.h"

#define TRANS {unity,lin,quad,linlog}			// Array de las transformaciones por defecto
#define NTRANS 4						// Número de transformaciones por defecto

/*
 *  Funciones, lin, quad y linlog
 * --------------------------------------------------------
 *   Diferentes costes computacionales. Transformaciones de los datos.
 *
 *   x: abcisas
 *   y: ordenadas
 *
 *   resultado: variable real resultado de la transformación
 */
float lin(float x, float y);
float quad(float x, float y);
float linlog(float x, float y);
float unity(float x, float y);

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

// Puntero a función para los diferentes algoritmos
typedef void(*algorithm_ptr)(int*,int,Experiment*);

// Coste de un algoritmo
typedef struct {
  trans_ptr transform; 					// Tipo de coste computacional
  float coef; 							// Coeficiente del coste
} Cost;

/*
 *  Función: newExperiment
 * --------------------------------------------------------
 *   Genera un nuevo experimento, inicializa variabless
 *
 *   n: tamaño del vector asociado a este experimento
 *
 *   resultado: estructura experimento inicializada
 */
Experiment newExperiment(size_t n);

/*
 *  Función: swap
 * --------------------------------------------------------
 *   Intercambia el os para contabilizar los intercambios.
 *
 *   x: puntero al primer entero
 *   y: puntero al segundo entero
 *   experiment: puntero al experimento
 */
void swap(int * x, int * y, Experiment * experiment);

/*
 *  Función: compare
 * --------------------------------------------------------
 *   Intercambia el valor de las variables dadas y suma
 *   tres movimientos al experimento. Esta función debe usarse dentro
 *   de los algoritmos para contabilizar los intercambios.
 *
 *   x: puntero al primer entero
 *   y: puntero al segundo entero
 *   experiment: puntero al experimento
 */
int compare(int expresion, Experiment * experiment);

/*
 *  Función: startCount
 * --------------------------------------------------------
 *   Inicia a contar el tiempo del algoritmo en el que se ejecute
 *
 *   experiment: puntero al experimento
 */
void startCount(Experiment * experiment);

/*
 *  Función: endCount
 * --------------------------------------------------------
 *   Finaliza la cuenta de tiempo del algoritmo en el que se ejecute
 *
 *   experiment: puntero al experimento
 */
void endCount(Experiment * experiment);

/*
 *  Función: millis
 * --------------------------------------------------------
 *   Devuelve el tiempo transcurrido en milisegundos desde la llamada
 *   a startCount y la de endCount
 *
 *   experiment: puntero al experimento
 *
 *   resultado: tiempo en milisegundos transcurridos
 */
unsigned int millis(Experiment * experiment);

/*
 *  Función: nanos
 * --------------------------------------------------------
 *   Devuelve el tiempo transcurrido en nanosegundos desde la llamada
 *   a startCount y la de endCount
 *
 *   experiment: puntero al experimento
 *
 *   resultado: tiempo en nanosegundos transcurridos
 */
unsigned int nanos(Experiment * experiment);

/*
 *  Función: costIdentification
 * --------------------------------------------------------
 *   Identifica el coste computacional de una serie de experimentos
 *
 *   experiment: array de experimentos
 *   n: número de experimentos
 *   mov_str: cadena de caracteres con el coste computacional en movimientos
 *   comp_str: cadena de caracteres con el coste coste computacional
 *            en comparaciones
 *   nanos_str: cadena de caracteres con el coste coste computacional
 *            en nanosegundos
 *
 *   NOTA: es recomendable que las cadenas de caracteres tengan al menos 20
 */
void costIdentification(Experiment * experiment, size_t n, char * mov_str,
    char * comp_str, char * nanos_str);

/*
 *  Función: calculateTable
 * --------------------------------------------------------
 *   Ejecuta una serie de experimentos dadas las combinaciones que se quieren
 *   de orden inicial, número de elementos y algoritmos
 *
 *   nelements: array con el número de elementos de cada tanda de experimentos
 *   num_nelement: tamaño de nelements
 *   algorithms: array con los algoritmos a ejecutar
 *   num_algorithm: tamaño de num_algorithm
 *   types: array con los ordenes iniciales de los datos a ejecutar
 *   num_types: tamaño de types
 *
 *   resultado: tabla con los costes computacionales en forma de char*,
 *        el primer índice son los algoritmos, el segundo los datos y el tercero
 *        son los costes 0 movimientos, 1 comparaciones, 2 tiempo.
 *
 *   NOTA: Hay que liberar la tabla una vez terminado de usarla con freeTable
 */
char **** calculateTable(size_t nelements[], int num_nelement,
 algorithm_ptr algorithms[], int num_algorithm,
 dataType types[], int num_types);

 /*
  *  Función: freeTable
  * --------------------------------------------------------
  *   Libera la memoria de la tabla anterior
  *
  *   c: tabla dinámica generada por calculateTable
  *   first: tamaño del primer índice de la tabla (número de algoritmos)
  *   second: tamaño del segundo índice de la tabla (número de datos)
  *   first: tamaño del tercer índice de la tabla (costes, normalmente 3)
  */
void freeTable(char **** c, int first, int second, int third);

#endif
