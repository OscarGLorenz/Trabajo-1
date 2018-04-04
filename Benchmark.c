/******************************************************************************
* ARCHIVO :        Benchmark.c
*
* AUTOR :    Óscar García Lorenz
******************************************************************************/

#include "Benchmark.h"

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/* En windows no existe la función clock_gettime, asi que emularemos su
funcionamiento con windows */
#ifdef _WIN32

#include <Windows.h>
#define CLOCK_PROCESS_CPUTIME_ID 1  /* Esta macro funcionará como dummy */
static int firstTime = 1; /* Variable estática para registrar las llamadas */
static LARGE_INTEGER frecuency;

/*
 *  Función: clock_gettime
 * --------------------------------------------------------
 *   Emulación de la función clock_gettime de POSIX
 *
 *   dummy: este argumentos está solo para emular la funcionalidad de POSIX
 *      solo admitirá CLOCK_PROCESS_CPUTIME_ID
 *   ct: estructura timespec para guardar el timestamp actual
 *
 */
int clock_gettime(int dummy, struct timespec *ct) {
    LARGE_INTEGER count;

    /* Si es la primera vez obtiene el valor de la frecuencia */
    if (firstTime) {
        firstTime = 0;
        QueryPerformanceFrequency(&frecuency);
    }

    /* Obtención del tiempo transcurrido desde el inicio */
    QueryPerformanceCounter(&count);
    /* Cálculo de los segundos */
    ct->tv_sec = count.QuadPart / frecuency.QuadPart;
    /* Cálculo de los nanosegundos */
    ct->tv_nsec = ((count.QuadPart % frecuency.QuadPart) * 1e9) /
          frecuency.QuadPart;
    return 0;
}
#endif

/*
 *  Función: newExperiment
 * --------------------------------------------------------
 *   Genera un nuevo experimento, inicializa variabless
 *
 *   n: tamaño del vector asociado a este experimento
 *
 *   resultado: estructura experimento inicializada
 */
Experiment newExperiment(size_t n) {
  Experiment experiment;
  experiment.comparations = 0;
  experiment.movements = 0;
  experiment.elements = n;
  return experiment;
}

/*
 *  Función: swap
 * --------------------------------------------------------
 *   Intercambia el valor de las variables dadas y suma
 *   tres movimientos al experimento. Esta función debe usarse dentro
 *   de los algoritmos para contabilizar los intercambios.
 *
 *   x: puntero al primer entero
 *   y: puntero al segundo entero
 *   experiment: puntero al experimento
 */
void swap(int * x, int * y, Experiment * experiment) {
  int aux = *x;
  experiment->movements+=3;
  *x = *y;
  *y = aux;
}

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
int compare(int expresion, Experiment * experiment) {
  experiment->comparations++;
  return expresion;
}

/*
 *  Función: startCount
 * --------------------------------------------------------
 *   Inicia a contar el tiempo del algoritmo en el que se ejecute
 *
 *   experiment: puntero al experimento
 */
void startCount(Experiment * experiment) {
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &experiment->start);
}

/*
 *  Función: endCount
 * --------------------------------------------------------
 *   Finaliza la cuenta de tiempo del algoritmo en el que se ejecute
 *
 *   experiment: puntero al experimento
 */
void endCount(Experiment * experiment) {
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &experiment->end);
}

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
unsigned int millis(Experiment * experiment) {
  return (experiment->end.tv_nsec-experiment->start.tv_nsec)/10e6 +
  (experiment->end.tv_sec-experiment->start.tv_sec) * 10e3;
}

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
unsigned int nanos(Experiment * experiment) {
  return (experiment->end.tv_nsec-experiment->start.tv_nsec)+
  (experiment->end.tv_sec-experiment->start.tv_sec) * 10e9;
}

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
float lin(float x, float y) {
  return y;
}
float quad(float x, float y) {
  return y/x;
}
float linlog(float x, float y) {
  return y/log(x);
}

/*
 *  Función: regrex
 * --------------------------------------------------------
 *   Calcula la regresión lineal de una variable de un conjunto de puntos
 *   transformando en primer lugar los datos con una función dada
 *
 *   x: array de abcisas
 *   y: array de ordenadas
 *   n: tamaño de los arrays anteriores
 *   b0: resultado por referencia de la ordenada en el origen de la
 *    recta de regresión
 *   b1: resultado por referencia de la pendiente de la recta de regresión
 *   trans: puntero a función de la transformación a aplicar antes de hacer la
 *    regresión a los datos obtenidos
 *
 *   resultado: residuo de los datos datos dados con respecto a la recta de
 *    regresión
 */
float regrex(float * x, float * y, size_t n, float * b0, float * b1,
              trans_ptr trans) {
  /* Vector auxiliar para guardar las y transformaciones */
  float* yT = (float*) malloc(sizeof(float) * n);
  float meanX = 0, meanY = 0; /* Medias de X e Y */
  float num = 0, denom = 0; /* Denominador y numerador de b1 */
  size_t i;
  float residue2 = 0; /* Residuo al cuadrado */

  /* Transforma los puntos con la funcion dada */
  for (i = 0; i < n; i++)
      yT[i] = trans(x[i],y[i]);

  /*Cálculo de las medias */
  for (i = 0; i < n; i++) {
    meanY += yT[i];
    meanX += x[i];
  }
  meanX /= n; meanY /= n;

  /*Cálculo de la pendiente de la recta de regresión */
  for (i = 0; i < n; i++) {
    num += (yT[i]-meanY)*(x[i]-meanX);
    denom += (x[i]-meanX)*(x[i]-meanX);
  }
  *b1 = num/denom;

  /*Cálculo de la ordenada en el origen */
  *b0 = meanY - *b1 * meanX;

  /*Cálculo de los residuos */
  for (i = 0; i < n; i++)
    residue2 += (*b0 + *b1 * x[i] - yT[i]) * (*b0 + *b1 * x[i] - yT[i]);

  free(yT);
  return sqrt(residue2);
}

/*
 *  Función: indentify
 * --------------------------------------------------------
 *   Identifica la transformación que hay que aplicar al conjunto de puntos dado
 *    para que pueda ser aproximado por una recta
 *
 *   x: array de abcisas
 *   y: array de ordenadas
 *   n: tamaño de los arrays anteriores
 *   trans: array de punteros a función de transformaciones a probar y buscar
 *     la óptima
 *   ntrans: tamaño del array trans
 *
 *   resultado: estructura Cost, con la transformación y coeficiente
 */
#define EPS 0.02 /* Tolerancia para la identificación */
Cost identify(float * x, float * y, size_t n, trans_ptr * trans,
                size_t ntrans) {
    Cost cost;
    size_t i;
    size_t less = 0; /* Índice de la mejor regresión */
    /* Pendiente, ordenada en el origen y residuo */
    float * b1 = (float*) malloc(n * sizeof(float));
    float * b0 = (float*) malloc(n * sizeof(float));
    float * res = (float*) malloc(n * sizeof(float));

    /* Probar todas las transformaciones y guardar el resultado */
    for (i = 0; i < ntrans; i++) {
      res[i] = regrex(x,y,n,&b0[i],&b1[i],trans[i]);
      #ifdef DEBUG
      /* Muestra por pantalla los resultados si DEBUG está definido */
        printf("res=%.2f b0=%.2f b1=%.2f\n",res[i], b0[i], b1[i]);
      #endif
    }
    #ifdef DEBUG
      printf("\n");
    #endif

    /* Búsqueda de la transformación que resulte en un residuo menor y con
    pendiente distinta de 0 */
    for (i = 1; i < ntrans; i++)
      if (res[i] < res[less] && b1[i] >= EPS)
        less = i;

    /* Una vez encontrado el óptimo guardar y devolver como resultado */
    cost.transform = trans[less];
    cost.coef = b1[less];

    free(b1);
    free(b0);
    free(res);

    return cost;
}

/*
 *  Función: costToString
 * --------------------------------------------------------
 *   Transforma una estructura coste en un char *
 *
 *   cost: coste a transfor * mar
 *   c: char* por referencia como resultado. Recomendable tamaño superior a 20
 */
void costToString(Cost cost, char * c) {
  char type[20];
  if (cost.transform == lin) {
    strcpy(type,"O(n)");
  } else if (cost.transform == quad) {
    strcpy(type,"O(n^2)");
  } else if (cost.transform == linlog) {
    strcpy(type,"O(n log n)");
  }

  sprintf(c,"%.2f %s", cost.coef, type);
}

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
                          char * comp_str, char * nanos_str) {
  /* Vector auxiliar que almacena las transformaciones disponibles */
  trans_ptr transformations[NTRANS] = TRANS;
  size_t i;
  Cost comp_cost, mov_cost, nanos_cost;

  /* Variables para almacenar los datos a los que se efectuaran regresiones */
  float * comp_f = (float*) malloc(n * sizeof(float));
  float * move_f = (float*) malloc(n * sizeof(float));
  float * nanos_f = (float*) malloc(n * sizeof(float));
  float * number_f = (float*) malloc(n * sizeof(float));

  /* Iteración por toda la lista de experimentos para recabar los datos */
  for (i = 0; i < n; i++) {
    comp_f[i] = experiment[i].comparations;
    move_f[i] = experiment[i].movements;
    nanos_f[i] = nanos(&experiment[i]);
    number_f[i] = experiment[i].elements;
  }

  /* Identificación de los costes de comparaciones, moviemientos y tiempo */
  comp_cost = identify(number_f, comp_f, n, transformations, NTRANS);
  mov_cost = identify(number_f, move_f, n, transformations, NTRANS);
  nanos_cost = identify(number_f, nanos_f, n, transformations, NTRANS);

  /* Conversión a char* de los anteriores costes */
  costToString(comp_cost, comp_str);
  costToString(mov_cost, mov_str);
  costToString(nanos_cost, nanos_str);

  free(comp_f);
  free(move_f);
  free(nanos_f);
  free(number_f);
}

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
  dataType types[], int num_types) {
  int i, j, k, l;
  const int num_costs = 3;
  size_t nelem;
  int * raw_data;
  int * buffer;

  char **** costs;
  Experiment *** experiment;

  /* Reservar memoria para costs */
  costs = (char ****) malloc(num_algorithm * sizeof(char ***));
  for(i = 0; i < num_algorithm; i++) {
    costs[i] = (char ***) malloc(num_types * sizeof(char**));
    for(j = 0; j < num_types; j++) {
      costs[i][j] = (char **) malloc(num_costs * sizeof(char*));
      for (k = 0; k < num_costs; k++) {
        costs[i][j][k] = (char *) malloc(30 * sizeof(char));
        costs[i][j][k][0] = '\0'; /* Inicialización del char* */
      }
    }
  }

  /* Reservar memoria para experiment */
  experiment = (Experiment ***) malloc(num_algorithm * sizeof(Experiment **));
  for(i = 0; i < num_algorithm; i++) {
    experiment[i] = (Experiment **) malloc(num_types * sizeof(Experiment*));
    for(j = 0; j < num_types; j++) {
      experiment[i][j] = (Experiment *) malloc(num_nelement * sizeof(Experiment));
    }
  }

  for (j = 0; j < num_types; j++) {
    for (l = 0; l < num_nelement; l++) {
      nelem = nelements[l];

      raw_data = (int *) malloc(nelem * sizeof(int));
      buffer = (int *) malloc(nelem * sizeof(int));

      dataCreator(raw_data, nelem, types[j], 0);

      for (i = 0; i < num_algorithm; i++) {
         memcpy(buffer,raw_data,nelem*sizeof(int));
         experiment[i][j][l] = newExperiment(nelem);
         algorithms[i](buffer, nelem, &experiment[i][j][l]);
      }

      free(raw_data);
      free(buffer);
  }

  for (i = 0; i < num_algorithm; i++)
    costIdentification(experiment[i][j], num_nelement,
      costs[i][j][0], costs[i][j][1], costs[i][j][2]);

  }

  /* Liberar memoria para experiment */
  for(i = 0; i < num_algorithm; i++) {
    for(j = 0; j < num_types; j++) {
      free(experiment[i][j]);
    }
    free(experiment[i]);
  }
  free(experiment);

  return costs;
}

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
void freeTable(char **** c, int first, int second, int third) {
  int i,j,k;
  for(i = 0; i < first; i++) {
    for(j = 0; j < second; j++) {
      for (k = 0; k < third; k++) {
        free(c[i][j][k]);
      }
      free(c[i][j]);
    }
    free(c[i]);
  }
  free(c);
}
