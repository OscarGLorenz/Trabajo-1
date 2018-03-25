#include "Benchmark.h"
#include <time.h>

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

Experiment newExperiment(size_t n) {
  Experiment experiment;
  experiment.comparations = 0;
  experiment.movements = 0;
  experiment.elements = n;
  return experiment;
}

void swap(int * x, int * y, Experiment * experiment) {
  experiment->movements+=3;
  int aux = *x;
  *x = *y;
  *y = aux;
}

int compare(int expresion, Experiment * experiment) {
  experiment->comparations++;
  return expresion;
}

void startCount(Experiment * experiment) {
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &experiment->start);
}

void endCount(Experiment * experiment) {
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &experiment->end);
}

unsigned int millis(Experiment * experiment) {
  return (experiment->end.tv_nsec-experiment->start.tv_nsec)/10e6 +
  (experiment->end.tv_sec-experiment->start.tv_sec) * 10e3;
}

unsigned int nanos(Experiment * experiment) {
  return (experiment->end.tv_nsec-experiment->start.tv_nsec)+
  (experiment->end.tv_sec-experiment->start.tv_sec) * 10e9;
}
