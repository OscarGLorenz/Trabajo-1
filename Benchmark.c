#include "Benchmark.h"
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#define CLOCK_PROCESS_CPUTIME_ID 1
static int primeraVez = 1;
static LARGE_INTEGER frecuencia;

int clock_gettime(int dummy, struct timespec *ct) {
    LARGE_INTEGER cuenta;

    if (primeraVez) {
        primeraVez = 0;

        QueryPerformanceFrequency(&frecuencia);

    }

    QueryPerformanceCounter(&cuenta);
	
    ct->tv_sec = cuenta.QuadPart / frecuencia.QuadPart;
    ct->tv_nsec = ((cuenta.QuadPart % frecuencia.QuadPart) * 1e9) / frecuencia.QuadPart;

    return 0;
}
#endif

Experimento nuevoExperimento(size_t n) {
  Experimento experimento;
  experimento.comparaciones = 0;
  experimento.movimientos = 0;
  elementos = n;
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
