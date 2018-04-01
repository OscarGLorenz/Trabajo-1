#include <math.h>
#include <string.h>
#include <stdio.h>

#include "Benchmark.h"

/* En windows no existe la función clock_gettime, asi que emularemos su
funcionamiento con windows */
#ifdef _WIN32

#include <Windows.h>
#define CLOCK_PROCESS_CPUTIME_ID 1
static int firstTime = 1;
static LARGE_INTEGER frecuency;

int clock_gettime(int dummy, struct timespec *ct) {
    LARGE_INTEGER count;

    if (firstTime) {
        firstTime = 0;
        QueryPerformanceFrequency(&frecuency);
    }
    QueryPerformanceCounter(&count);
    ct->tv_sec = count.QuadPart / frecuency.QuadPart;
    ct->tv_nsec = ((count.QuadPart % frecuency.QuadPart) * 1e9) / frecuency.QuadPart;
    return 0;
}
#endif

/* Inicializa los campos de una estrucura experimento */
Experiment newExperiment(size_t n) {
  Experiment experiment;
  experiment.comparations = 0;
  experiment.movements = 0;
  experiment.elements = n;
  return experiment;
}

/* USO EN ALGORITMOS. Hace un intercambio entre dos variables y computa
como tres movimientos adicionales para el experimento */
void swap(int * x, int * y, Experiment * experiment) {
  experiment->movements+=3;
  int aux = *x;
  *x = *y;
  *y = aux;
}

/* USO EN ALGORITMOS. Evalua una expresión lógica y la devuelve. Computa una
comparación adicional al experimento */
int compare(int expresion, Experiment * experiment) {
  experiment->comparations++;
  return expresion;
}

/* USO EN ALGORITMOS. Inicia la cuenta al principio del fragmento de código a
evaluar */
void startCount(Experiment * experiment) {
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &experiment->start);
}

/* USO EN ALGORITMOS. Finaliza la cuenta al final del fragmento de código a
evaluar */
void endCount(Experiment * experiment) {
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &experiment->end);
}

/* Devuelve el tiempo transcurrido desde startCount hasta endCount en
milisegundos */
unsigned int millis(Experiment * experiment) {
  return (experiment->end.tv_nsec-experiment->start.tv_nsec)/10e6 +
  (experiment->end.tv_sec-experiment->start.tv_sec) * 10e3;
}

/* Devuelve el tiempo transcurrido desde startCount hasta endCount en
nanosegundos */
unsigned int nanos(Experiment * experiment) {
  return (experiment->end.tv_nsec-experiment->start.tv_nsec)+
  (experiment->end.tv_sec-experiment->start.tv_sec) * 10e9;
}

/* COSTES COMPUTACIONALES */
float lin(float x, float y) {
  return y;
}
float quad(float x, float y) {
  return y/x;
}
float linlog(float x, float y) {
  return y/log(x);
}


/* Cálcula la regresión lineal de una variable de un conjunto de puntos
ARGUMENTOS: vectores de ordenadas (x) y abcisas (y) de los puntos y su número (n)
            trans, transformacion matemática a efectuar con el conjunto de puntos
RESULTADOS: b0 ordenada en el origen de la recta de regresión
            b1 pendiente de la recta de regresión
            Devuelve el residuo del los puntos con respecto a la recta de regresión
*/
float regrex(float * x, float * y, size_t n, float * b0, float * b1, trans_ptr trans) {
  float yT[n]; // Vector auxiliar para guardar las y transformadas

  // Transforma los puntos con la funcion dada
  for (size_t i = 0; i < n; i++)
      yT[i] = trans(x[i],y[i]);

  //Cálculo de las medias
  float meanX = 0, meanY = 0;
  for (size_t i = 0; i < n; i++) {
    meanY += yT[i];
    meanX += x[i];
  }
  meanX /= n; meanY /= n;

  //Cálculo de la pendiente de la recta de regresión
  float num = 0, denom = 0;
  for (size_t i = 0; i < n; i++) {
    num += (yT[i]-meanY)*(x[i]-meanX);
    denom += (x[i]-meanX)*(x[i]-meanX);
  }
  *b1 = num/denom;

  //Cálculo de la ordenada en el origen
  *b0 = meanY - *b1 * meanX;

  //Cálculo de los residuos
  float residue2 = 0;
  for (size_t i = 0; i < n; i++)
    residue2 += (*b0 + *b1 * x[i] - yT[i]) * (*b0 + *b1 * x[i] - yT[i]);
  return sqrt(residue2);
}

/* Identifica la transformación que hay que aplicar al conjunto de puntos dado
para que pueda ser aproximado por una recta
ARGUMENTOS: vectores de ordenadas (x) y abcisas (y) de los puntos y su número (n)
            trans, vector de transformaciones para probar y su número ntrans
RESULTADO:  Devuelve una estructura Coste, con la transformación adecuada y la
            pendiente de la recta de regresión que aproxima a ese conjunto.
*/
#define EPS 0.01 // Tolerancia para la identificación
Cost identify(float * x, float * y, size_t n, trans_ptr * trans, size_t ntrans) {
    Cost cost;
    // Pendiente, ordenada en el origen y residuo
    float b1[ntrans], b0[ntrans], res[ntrans];

    // Probar todas las transformaciones y guardar el resultado
    for (size_t i = 0; i < ntrans; i++) {
      res[i] = regrex(x,y,n,&b0[i],&b1[i],trans[i]);
      #ifdef DEBUG  //Muestra por pantalla los resultados si DEBUG está definido
        printf("res=%.2f b0=%.2f b1=%.2f\n",res[i], b0[i], b1[i]);
      #endif
    }
    #ifdef DEBUG
      printf("\n");
    #endif

    /* Búsqueda de la transformación que resulte en un residuo menor y con
    pendiente distinta de 0 */
    size_t less = 0;
    for (size_t i = 1; i < ntrans; i++)
      if (res[i] < res[less] && b1[i] >= EPS)
        less = i;

    // Una vez encontrado el óptimo guardar y devolver como resultado
    cost.transform = trans[less];
    cost.coef = b1[less];
    return cost;
}

/* Transforma una estructura coste en un char * */
void costToString(Cost cost, char * c) {
  char type[10];
  if (cost.transform == lin) {
    strcpy(type,"O(n)");
  } else if (cost.transform == quad) {
    strcpy(type,"O(n^2)");
  } else if (cost.transform == linlog) {
    strcpy(type,"O(n log n)");
  }

  sprintf(c,"%.2f %s", cost.coef, type);
}

/* Dada una lista de experimentos, calcula los costes computacionales en
movimientos, comparaciones y tiempo
ARGUMENTOS: experiment, vector de experimentos y su número n
RESULTADOS: mov_str, coste en movimientos
            comp_str, coste en comparaciones
            nanos_str, coste en tiempo
            El tamaño de estos char* deben ser de al menos unos 20 caracteres
*/
void costIdentification(Experiment * experiment, size_t n, char * mov_str, char * comp_str, char * nanos_str) {
  // Vector auxiliar que almacena las transformaciones disponibles
  trans_ptr transformations[NTRANS] = TRANS;

  // Variables reales para almacenar los datos a los que se efectuaran regresiones
  float comp_f[n], move_f[n], nanos_f[n], number_f[n];

  // Iteración por toda la lista de experimentos para recabar los datos
  for (size_t i = 0; i < n; i++) {
    comp_f[i] = experiment[i].comparations;
    move_f[i] = experiment[i].movements;
    nanos_f[i] = nanos(&experiment[i]);
    number_f[i] = experiment[i].elements;
  }

  // Identificación de los costes de comparaciones, moviemientos y tiempo
  Cost comp_cost = identify(number_f, comp_f, n, transformations, NTRANS);
  Cost mov_cost = identify(number_f, move_f, n, transformations, NTRANS);
  Cost nanos_cost = identify(number_f, nanos_f, n, transformations, NTRANS);

  // Conversión a char* de los anteriores costes
  costToString(comp_cost, comp_str);
  costToString(mov_cost, mov_str);
  costToString(nanos_cost, nanos_str);
}

// *************** FOR OGL ***************************************

Costs runBenchmark(int data[][4], Types typestable, int* datasize, algorithm_ptr, int dataType, int iterations){
	int k, l;
	Experiment results[iterations];
	Costs experimentcosts;
	for (l = 0; l < iterations; l++){
		results[i] = newExperiment(datasize[l]);
		int buffer[datasize[l]];
		memcpy(buffer,data[l][dataType],nelem*sizeof(int));
		algorithm[k](buffer, datasize[l], results[l];
	}
	costIdentification(results, datasize, &experimentcosts);
	return experimentcosts;
}

/*
void calculateTable(Results * result, size_t nelements[], int n_nelement,
  algorithm_ptr algorithms[], char algorithm_str[][30], int num_algorithm,
  dataType types[], char type_str[][30], int num_types) {

  Experiment experiment[num_types][num_algorithm][n_nelement];

    for (int i = 0; i < num_types; i++) {
      for (int j = 0; j < n_nelement; j++) {
        size_t nelem = nelements[j];
        int raw_data[nelem];
        int buffer[nelem];

        //dataCreator(raw_data, nelem, types[i], 0);

        for (int k = 0; k < num_algorithm; k++) {
          memcpy(buffer,raw_data,nelem*sizeof(int));
          experiment[i][k][j] = newExperiment(nelem);
          algorithms[k](buffer, nelem, &experiment[i][k][j]);
        }
      }

      for (int k = 0; k < num_algorithm; k++)
        costIdentification(experiment[i][k], n_nelement,
          result->cost[k][i][0], result->cost[k][i][1], result->cost[k][i][2]);

    }

}
*/
